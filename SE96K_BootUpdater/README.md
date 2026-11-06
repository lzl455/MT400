# SE96K Boot Updater

一个"一次性 App"：由现有 Boot 当作普通固件写入 0x1000 并运行，它把内嵌的新 Boot
写进 Boot 区（0x0000–0x0FFF），然后进入新 Boot，由驱动把正式 App 写回去。
现有 Boot 和正式 App 都不需要改动，已出货的键盘也能升级 Boot。

## 前提

芯片烧录选项 **"0000-0FFF 写保护"必须是"允许擦写"**（规格书第 135–136 页）。
如果量产时设成了"不允许擦写"，软件无法改写 Boot，Updater 运行后会因为第 0 页
写入校验失败而停机，只能用烧录器恢复。**请先用一块板子验证。**

## 文件

| 文件 | 说明 |
| --- | --- |
| `Updater.prj` | ZCW 工程，芯片配置与 App 相同，`CodeOffset=1000`（与 App 一样从 0x1000 运行） |
| `MAIN.C` | 更新流程 |
| `flash.c` | 整页擦写 + 回读校验（IAP 流程同 App/Boot 的 `flash.c`） |
| `boot_image.c` / `boot_image.h` | 新 Boot 镜像及其项目ID、版本号，**由 `tools/hex2c.py` 生成** |
| `tools/hex2c.py` | 把 Boot 工程的 `output/SE95K.hex` 转成 `boot_image.c` / `.h` |

## 生成步骤

1. 编译 `SE93T_BootLoader` 工程，得到 `output/SE95K.hex`。
2. 生成镜像：

   ```bash
   python SE96K_BootUpdater/tools/hex2c.py SE93T_BootLoader/SE93T_BootLoader/output/SE95K.hex
   ```

   脚本会检查数据只在 0x0000–0x0FFF、尾标记为 `AA 55 5A`，并打印项目 ID / Boot 版本，请核对。
3. 用 ZCW 打开 `Updater.prj` 编译，`output/*.bin` 就是给驱动下发的 Updater 固件
   （格式与正式 App 的 bin 相同，从 0x1000 开始）。

> 仓库里当前的 `boot_image.c` 是用**旧 Boot**（版本 1）生成的占位文件。用它编出来的
> Updater 发现 Boot 区内容一致，什么都不写，直接进入 Boot。正式使用前务必按上面步骤重新生成。

## 固件标识（bin 文件偏移 0x5FF0）

Updater 在 0x6FF0 放了 16 字节标识，位置和格式都与正式 App 的 `fw_info` 相同，
驱动用同一段代码读取，再看 `[8..10]` 区分：

| 偏移 | 正式 App.bin | Updater.bin |
| --- | --- | --- |
| 0x5FF0–0x5FF3 | 项目ID ID3 ID2 ID1 ID0（`28 00 96 00`） | 新 Boot 的项目ID（同上顺序） |
| 0x5FF4 | App 版本号 | **将写入的新 Boot 版本号** |
| 0x5FF5–0x5FF7 | `02 00 01` | `00 00 00` |
| 0x5FF8–0x5FFF | `BYKC-V10` | **`UPD-BOOT`** |

驱动建议：

- 用户选了 bin 文件后，`0x5FF8..0x5FFA == "UPD"` 的按"升级 Boot"流程处理，否则按普通 App 处理。
  普通 App 流程中如果发现是 Updater，应拒绝（否则键盘会停在 Boot，看起来像"变砖"）。
- 项目ID的 ID0/ID1（0x5FF3、0x5FF2 = `00 96`）与 Boot 返回的不一致时拒绝。
- 第 0x5FF4 字节即 `NEW_BOOT_VER`：Boot 当前版本已等于它就跳过 Updater；
  Updater 运行后 Boot 版本等于它才算成功。驱动不必再写死版本号。

## 驱动侧流程

完整协议（报文格式、命令、校验算法、异常处理）见 [`docs/驱动升级协议.md`](../docs/驱动升级协议.md)。

全部使用现有协议，不需要新命令：

1. 向 App 下发跳 Boot 命令（App 命令头为 `0x0F`：`0F 1E 55 AA 00 FF`），等待 Boot 枚举
   （VID 0x32C2 / PID 0x001B，之后 Boot 的命令头为 `0x0E`）。
2. 读 Boot 信息（`0x0E 0x20`），返回的版本号（`in[6]`）已等于 Updater.bin 偏移 0x5FF4 的值，跳到第 6 步。
3. 用 W_FIFO + W_FLASH 把 **Updater 固件**写入（和写 App 完全一样）。
4. 下发 APP 命令（`0x0E 0x1E`），Boot 复位并运行 Updater。
5. Updater 约 0.2 s 内完成更新并软复位进入新 Boot。驱动等待 Boot 重新枚举
   （建议超时 5 s），再读一次 Boot 信息，确认版本号等于 Updater.bin 偏移 0x5FF4 的值。
6. 写入**正式 App**，下发 APP 命令，完成。

第 5 步超时没有枚举 → 说明 Updater 停机（写入失败），提示用户**重新插拔**；重新上电后
Updater 会自动从断点继续，然后按第 5 步继续。版本号没有变化 → Updater 判断不是本产品
Boot 或镜像校验失败，没有改动 Boot，可以直接写回正式 App。

## Updater 内部流程

```
上电/复位 → 运行 Updater (0x1000)
  ├─ 镜像累加和/尾标记错误 → Boot 完好则进旧 Boot；Boot 已是跳转桩则停机
  ├─ Boot 区已与镜像一致     → 进 Boot
  ├─ 非跳转桩且项目ID前两字节不符 → 进旧 Boot（不改）
  ├─ 1. 第 0 页写"跳转桩"(0x0000/0x0008/0x0018 → 0x1000/0x1008/0x1018)
  ├─ 2. 写第 1–31 页，每页回读校验，失败重试 3 次，仍失败则停机
  ├─ 3. 最后写第 0 页（新 Boot 复位向量），失败则恢复跳转桩并停机
  └─ 写 0x280 跳转标志 3C C3 55 AA → 软复位 → 新 Boot
```

- 第 1 步写完以后，任何时刻掉电，重新上电都会运行 Updater 并重新执行更新。
- **只有第 1 步和第 3 步各一次页擦写（约 3 ms 擦除 + 2 ms 编程）期间掉电会导致无法启动**，
  其余时间掉电都可以恢复。
- 更新完成、但驱动还没写回 App 时掉电：新 Boot 会跳到 Updater，Updater 发现 Boot 已一致，
  直接回到 Boot，驱动重新写 App 即可。
