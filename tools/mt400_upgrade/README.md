# mt400_upgrade —— 用软件模拟驱动

按 [`docs/驱动升级协议.md`](../../docs/驱动升级协议.md) 实现的上位机升级工具，用途：

- **当作驱动用**：直接对真实键盘执行 App 升级、Boot 升级，验证固件。
- **手动发命令**：`shell` 交互模式，一条条发 App / Boot 命令，看每个 TX/RX 报文。
- **没有硬件时验证流程**：`--sim` 使用模拟键盘。模拟器按固件源码逐条复现 Boot / App / Updater
  的行为（包括旧 Boot 的缺陷），可注入掉电、写保护等故障。
- **驱动开发参考**：`protocol.py` 就是驱动逻辑的参考实现，正式驱动可以照着移植。

## 安装

```bash
pip install hidapi          # 只用 --sim 时可以不装
```

- Windows：直接运行，不需要装驱动。
- Linux：需要 hidraw 读写权限（以 root 运行，或为 VID 331A / 32C2 加 udev 规则）。
- macOS：直接运行。

## 文件

| 文件 | 说明 |
| --- | --- |
| `mt400_upgrade.py` | 命令行入口 |
| `protocol.py` | 协议与流程：命令封装、校验、整页写、"首页最后写"、App / Boot 升级流程 |
| `hid_transport.py` | 真实设备传输层（hidapi），处理 App 有 Report ID、Boot 没有的差异 |
| `simulator.py` | 模拟键盘（Boot / App / Updater）及故障注入 |
| `test_simulator.py` | 自动测试（20 项） |

## 用法

```bash
# 真实键盘
python mt400_upgrade.py list                         # 列出设备及各 HID 接口
python mt400_upgrade.py info                         # 读版本 (自动判断 App / Boot)
python mt400_upgrade.py write-app App.bin            # 升级 App
python mt400_upgrade.py upgrade-boot Updater.bin App.bin   # 升级 Boot
python mt400_upgrade.py verify App.bin               # 进 Boot 回读整片比对
python mt400_upgrade.py jump-boot                    # 只跳 Boot
python mt400_upgrade.py run-app                      # Boot 运行 App
python mt400_upgrade.py read 0x5FF0 16               # Boot 读 Flash (地址为 bin 偏移)
python mt400_upgrade.py -v write-app App.bin         # -v 打印每条 TX/RX

# 模拟键盘 (默认使用仓库里的旧 Boot 与 App 编译产物)
python mt400_upgrade.py --sim info
python mt400_upgrade.py --sim write-app App.bin
python mt400_upgrade.py --sim upgrade-boot --sim-make-updater App.bin   # 自动生成模拟用 Updater
python mt400_upgrade.py --sim --sim-powerloss-at 10 upgrade-boot --sim-make-updater App.bin
python mt400_upgrade.py --sim --sim-write-protect upgrade-boot --sim-make-updater App.bin
python mt400_upgrade.py --sim --sim-app "" info      # 空白芯片 (无 App), 上电停在 Boot
```

模拟器选项：

| 选项 | 说明 |
| --- | --- |
| `--sim-boot FILE` | Boot 区镜像（4096 字节 bin），默认 `SE93T_BootLoader/.../output/20250331/SE95K.bin`（旧 Boot v1） |
| `--sim-app FILE` | 初始 App，默认 App 工程 `output/SE95K.bin`；`""` 表示无 App |
| `--sim-keys` | 上电时按住 左Ctrl+左Win |
| `--sim-write-protect` | Boot 区写保护（烧录选项"不允许擦写"） |
| `--sim-powerloss-at N` | Updater 第 N 次页擦写时掉电 |

## 交互模式 `shell`

逐条手动发命令，自动打印 TX/RX：

```
$ python mt400_upgrade.py --sim shell
app> info                       # 0F 20
app> jump                       # 0F 1E 55 AA 00 FF, 等 Boot 出现
boot> info                      # 0E 20
boot> fifo 0 01 02 03 04        # W_FIFO
boot> flash 0x10 4              # W_FLASH (自动算校验)
boot> page 0x0080 ff            # 整页写 (自动分 5 包 + 校验)
boot> read 0x10 8               # R_FLASH
boot> raw 0E 12 10 00 08 00     # 任意报文 (按固件编号, 首字节为命令头)
boot> run                       # 0E 1E, 等设备出现
boot> sim power keys            # [模拟] 断电, 按住组合键上电
```

`raw` 后面的字节就是文档里的 `out[0..]`，工具会按设备类型自动补 Report ID。

> 用 `fifo` + `flash` 在旧 Boot 上写非页对齐地址，会看到数据写进去了却回 NAK（错误码 4）。
> 这是旧 Boot 写后校验的缺陷（新 Boot 已修复），也是驱动必须 128 字节对齐整页写的原因。

## 测试

```bash
cd tools/mt400_upgrade
python -m unittest -v test_simulator
```

覆盖：校验算法、文件识别、App 主动上报被清空、新旧 Boot 信息、组合键进 Boot、R_FLASH、
新旧 Boot 上升级 App、空白芯片、拒绝错误文件、写入中途拔线后恢复、W_FIFO 传输错误重试、
Boot 升级、已是新 Boot 时跳过、Updater 掉电续写、**Updater 每一次页擦写掉电的恢复情况**、
Boot 已更新但 App 未写回时掉电、Boot 区写保护、非本产品 Boot 不改动、文件顺序错误、命令行。

掉电全覆盖测试证实：只有 Updater 的**第一次**（写跳转桩）和**最后一次**（写新第 0 页）页擦写
期间掉电会导致无法启动，其余任何时刻掉电都能在重新上电后自动恢复。

## 模拟器的局限

- 模拟的是**协议和 Flash 状态**，不执行固件指令，不能代替真机测试。
- Updater 由 `--sim-make-updater` 生成：只有内嵌的 Boot 镜像和 `UPD-BOOT` 标识，没有真正的代码。
  模拟器在 Updater 程序区里搜索内嵌的 Boot 镜像（结尾为 `AA 55 5A`、开头为 `Bo`），
  所以 ZCW 编出的真实 Updater.bin 也可以用 `--sim-app Updater.bin` 放进模拟器运行。
- 时序（擦写 5 ms、USB 重新枚举时间）不模拟，应答都是即时的。
