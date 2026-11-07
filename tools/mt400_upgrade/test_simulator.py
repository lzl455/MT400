# -*- coding: utf-8 -*-
"""
用模拟键盘验证驱动流程:  python -m unittest -v test_simulator
"""
import os
import sys
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)

from protocol import Session, FwFile, UpgradeError, page_checksum, BIN_SIZE   # noqa: E402
from simulator import SimKeyboard, SimBus, make_new_boot, make_sim_updater, stub_page  # noqa: E402
import mt400_upgrade                                                        # noqa: E402


def load(p):
    with open(p, 'rb') as f:
        return f.read()


OLD_BOOT = load(mt400_upgrade.DEF_SIM_BOOT)
APP_BIN = load(mt400_upgrade.DEF_SIM_APP)
NEW_BOOT = make_new_boot(OLD_BOOT)
UPD_BIN = make_sim_updater(NEW_BOOT)


def _differ_every_page(boot):
    """每页都改一个字节的新 Boot, 让 Updater 真正擦写全部 32 页"""
    b = bytearray(boot)
    for a in range(0, 0x1000, 128):
        b[a + 0x40] ^= 0x5A
    return bytes(b)


NEW_BOOT_FULL = _differ_every_page(NEW_BOOT)
UPD_FULL = make_sim_updater(NEW_BOOT_FULL)


def app_v(ver):
    """改版本号得到另一个 App"""
    b = bytearray(APP_BIN)
    b[0x5FF4] = ver
    b[0x3000] ^= 0xFF          # 改一点内容, 确保真的发生了写入
    return bytes(b)


class Base(unittest.TestCase):
    def make(self, boot=OLD_BOOT, app=APP_BIN, keys=False, **kw):
        kb = SimKeyboard(boot, app, **kw)
        kb.power_on(keys=keys)
        log = []
        s = Session(SimBus(kb), log=log.append, appear_timeout=0.2, gone_timeout=0.2, poll=0.01)
        return kb, s, log

    def assertApp(self, kb, app):
        self.assertEqual(kb.state, 'app')
        self.assertEqual(bytes(kb.flash[0x1000:0x1000 + BIN_SIZE]), app)


class TestBasics(Base):
    def test_checksum(self):
        self.assertEqual(page_checksum(b'\x00\x00'), 0xFA21)
        self.assertEqual(page_checksum(b'\x01\x02\x03\x04'), (0xFA21 + 0x0201 + 0x0403) & 0xFFFF)

    def test_fwfile(self):
        app, upd = FwFile(APP_BIN), FwFile(UPD_BIN)
        self.assertFalse(app.is_updater)
        self.assertEqual((app.pid, app.ver), (b'\x00\x96\x00\x28', 3))
        self.assertTrue(upd.is_updater)
        self.assertEqual(upd.ver, 2)
        with self.assertRaises(UpgradeError):
            FwFile(APP_BIN[:-1])

    def test_app_info_ignores_unsolicited(self):
        kb, s, _ = self.make()
        s.open('app')
        info = s.app_read_info()
        self.assertEqual(info[8:16], b'BYKC-V10')

    def test_boot_info_old_and_new(self):
        for boot, pid, ver in ((OLD_BOOT, b'\x00\x96\xFF\x01', 1), (NEW_BOOT, b'\x00\x96\x00\x28', 2)):
            kb, s, _ = self.make(boot=boot)
            s.enter_boot()
            self.assertEqual(s.boot_read_info(), (pid, ver))

    def test_power_on_keys_enters_boot(self):
        kb, s, _ = self.make(keys=True)
        self.assertEqual(kb.state, 'boot')

    def test_read_flash(self):
        kb, s, _ = self.make()
        s.enter_boot()
        self.assertEqual(s.boot_read_flash(0x5FF0, 16), APP_BIN[0x5FF0:0x6000])


class TestAppUpgrade(Base):
    def test_upgrade_app_old_and_new_boot(self):
        for boot in (OLD_BOOT, NEW_BOOT):
            kb, s, _ = self.make(boot=boot)
            new = app_v(4)
            s.upgrade_app(FwFile(new))
            self.assertApp(kb, new)

    def test_upgrade_from_empty_device(self):
        kb, s, _ = self.make(app=None)
        self.assertEqual(kb.state, 'boot')           # 无 App 上电停在 Boot
        s.upgrade_app(FwFile(APP_BIN))
        self.assertApp(kb, APP_BIN)

    def test_reject_updater_as_app(self):
        kb, s, _ = self.make()
        with self.assertRaises(UpgradeError):
            s.upgrade_app(FwFile(UPD_BIN))
        self.assertEqual(kb.state, 'app')            # 没有动设备

    def test_interrupted_write_stays_in_boot(self):
        """写到一半掉电: 首页已写空白, 上电停在 Boot, 重写成功"""
        kb, s, _ = self.make()
        s.enter_boot()
        new = app_v(5)
        calls = {'n': 0}
        orig = s.boot_write_page

        def flaky(addr, page, retries=3):
            calls['n'] += 1
            if calls['n'] == 50:
                kb.power_off()
                raise IOError('拔线')
            return orig(addr, page, retries)
        s.boot_write_page = flaky
        with self.assertRaises(IOError):
            s.boot_write_image(new)
        s.boot_write_page = orig
        s.close()
        kb.power_on()
        self.assertEqual(kb.state, 'boot')
        s.upgrade_app(FwFile(new))
        self.assertApp(kb, new)

    def test_fifo_error_is_retried(self):
        kb, s, log = self.make()
        s.enter_boot()
        kb.corrupt_fifo_once = True
        s.boot_write_image(app_v(6))
        self.assertTrue(any('W_FIFO' in l for l in log))
        s.finish_to_app(6)


class TestBootUpgrade(Base):
    def test_upgrade_boot(self):
        for upd, img in ((UPD_BIN, NEW_BOOT), (UPD_FULL, NEW_BOOT_FULL)):
            kb, s, _ = self.make()
            s.upgrade_boot(FwFile(upd), FwFile(APP_BIN))
            self.assertEqual(bytes(kb.flash[0:0x1000]), img)
            self.assertApp(kb, APP_BIN)
            self.assertIn('updater', kb.events)

    def test_powerloss_every_page(self):
        """Updater 任意一次页擦写掉电 (除两个已知窗口外) 都能恢复"""
        for n in range(1, 34):
            kb, s, _ = self.make(updater_powerloss_at=n)
            with self.assertRaises(UpgradeError):
                s.upgrade_boot(FwFile(UPD_FULL), FwFile(APP_BIN))
            s.close()
            kb.power_on()
            if n in (1, 33):          # 第 1 次 (写跳转桩) 和最后一次 (写新第 0 页) 是已知风险窗口
                self.assertEqual(kb.state, 'bricked', n)
                continue
            self.assertEqual(kb.state, 'boot', n)
            self.assertEqual(bytes(kb.flash[0:0x1000]), NEW_BOOT_FULL, n)

    def test_already_new_skips_updater(self):
        kb, s, _ = self.make(boot=NEW_BOOT)
        s.upgrade_boot(FwFile(UPD_BIN), FwFile(APP_BIN))
        self.assertNotIn('updater', kb.events)
        self.assertApp(kb, APP_BIN)

    def test_powerloss_resume(self):
        """Updater 写第 10 页时掉电 -> 驱动超时 -> 重新上电自动续写 -> 驱动重跑完成"""
        kb, s, _ = self.make(updater_powerloss_at=10)
        with self.assertRaises(UpgradeError):
            s.upgrade_boot(FwFile(UPD_FULL), FwFile(APP_BIN))
        self.assertEqual(kb.state, 'off')
        self.assertEqual(bytes(kb.flash[0:128]), stub_page())    # 第 0 页是跳转桩
        s.close()
        kb.power_on()                                            # 用户重新插拔
        self.assertEqual(kb.state, 'boot')                       # Updater 续写完成后进入新 Boot
        self.assertEqual(bytes(kb.flash[0:0x1000]), NEW_BOOT_FULL)
        s.upgrade_boot(FwFile(UPD_FULL), FwFile(APP_BIN))        # 再执行一次: 跳过 Updater, 写回 App
        self.assertApp(kb, APP_BIN)

    def test_poweroff_after_boot_updated_before_app(self):
        """Boot 已更新但 App 还没写回时掉电: 上电后 Updater 发现已一致, 直接回到 Boot"""
        kb, s, _ = self.make()
        s.enter_boot()
        s.boot_write_image(UPD_BIN)
        s.boot_run_app()
        s.close()
        self.assertEqual(kb.state, 'boot')
        kb.power_off()
        kb.power_on()
        self.assertEqual(kb.state, 'boot')
        self.assertEqual(bytes(kb.flash[0:0x1000]), NEW_BOOT)

    def test_write_protected(self):
        """Boot 区写保护: Updater 停机, 驱动超时; Boot 未被破坏"""
        kb, s, _ = self.make(write_protect_boot=True)
        with self.assertRaises(UpgradeError):
            s.upgrade_boot(FwFile(UPD_BIN), FwFile(APP_BIN))
        self.assertEqual(kb.state, 'halted')
        self.assertEqual(bytes(kb.flash[0:0x1000]), OLD_BOOT)

    def test_foreign_boot_untouched(self):
        """非本产品 Boot (ID1 不同): Updater 不改动, 驱动写回 App 后报错"""
        other = bytearray(OLD_BOOT)
        other[0xFF9] = 0x91
        kb, s, _ = self.make(boot=bytes(other))
        upd = make_sim_updater(NEW_BOOT)
        kb.flash[0x1000:0x1000 + BIN_SIZE] = upd       # 直接放入 Updater 运行
        kb._set_state('boot')
        s.open('boot')
        s.boot_run_app()
        s.close()
        self.assertEqual(kb.state, 'boot')
        self.assertEqual(bytes(kb.flash[0:0x1000]), bytes(other))

    def test_wrong_file_order(self):
        kb, s, _ = self.make()
        with self.assertRaises(UpgradeError):
            s.upgrade_boot(FwFile(APP_BIN), FwFile(UPD_BIN))


class TestPrecheck(Base):
    def test_placeholder_updater_rejected(self):
        """用旧 Boot 生成的占位 Updater: 发送前就拒绝, 设备不动"""
        kb, s, _ = self.make()
        with self.assertRaises(UpgradeError) as cm:
            s.upgrade_boot(FwFile(make_sim_updater(OLD_BOOT)), FwFile(APP_BIN))
        self.assertIn('占位', str(cm.exception))
        self.assertEqual(kb.state, 'app')

    def test_updater_without_image_rejected(self):
        b = bytearray(UPD_BIN)
        b[0x100:0x1100] = b'\xFF' * 0x1000
        errors, _ = FwFile(bytes(b)).check()
        self.assertTrue(any('找不到' in e for e in errors))

    def test_updater_tag_mismatch_rejected(self):
        b = bytearray(UPD_BIN)
        b[0x5FF4] = 7
        errors, _ = FwFile(bytes(b)).check()
        self.assertTrue(any('不一致' in e for e in errors))

    def test_step_cancel(self):
        kb, s, _ = self.make()
        answers = iter([True, False])               # 跳 Boot 后, 写 Updater 前取消
        s.confirm = lambda text: next(answers)
        with self.assertRaises(UpgradeError):
            s.upgrade_boot(FwFile(UPD_BIN), FwFile(APP_BIN))
        self.assertEqual(kb.state, 'boot')
        self.assertEqual(bytes(kb.flash[0:0x1000]), OLD_BOOT)


class TestCli(unittest.TestCase):
    def test_cli_sim(self):
        a = mt400_upgrade.DEF_SIM_APP
        self.assertEqual(mt400_upgrade.main(['--sim', 'info']), 0)
        self.assertEqual(mt400_upgrade.main(['--sim', 'write-app', a]), 0)
        self.assertEqual(mt400_upgrade.main(['--sim', 'upgrade-boot', '--sim-make-updater', a]), 0)
        self.assertEqual(mt400_upgrade.main(['--sim', 'verify', a]), 0)
        self.assertEqual(mt400_upgrade.main(['--sim', 'write-app', mt400_upgrade.DEF_SIM_BOOT]), 2)
        self.assertEqual(mt400_upgrade.main(['inspect', a]), 0)


if __name__ == '__main__':
    unittest.main()
