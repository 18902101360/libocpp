# c_ocpp — MCU-oriented OCPP 1.6 / 2.0.1 (C)

Two static libraries for a charge point:

- `c_ocpp16` — OCPP 1.6 (core + security whitepaper messages)
- `c_ocpp201` — OCPP 2.0.1

There is **no TCP/WebSocket** in this tree. One `ocpp16_session_t` / `ocpp201_session_t` is **one CSMS connection**: its own send callback, uniqueId sequence, pending CALLs, heartbeat timer, and control policy. Multi-operator is N sessions + N WebSockets in firmware.

cJSON arena is process-wide. Process one `session_rx` / encode at a time (serialize on the MCU).

## Layers

```
WS[i] rx  -->  session[i] (layer 2)  -->  RPC pack/unpack (layer 1)  -->  session.link.send
                  | seq / pending / timers / accept_control
```

1. **port** (`port/ocpp_port.c`) — arena (cJSON), clock, software timers. Replace on the chip.
2. **`ocpp_link_t`** — binds one session to one transport and policy.
3. **layer1** — `[2|3|4, uniqueId, …]` string assembly; payload codec in per-message files.
4. **layer2** — one context per CSMS.

Each OCPP action is `ocpp16/messages/ocpp16_<name>.c/.h` or `ocpp201/messages/ocpp201_<name>.c/.h` (version prefix so Keil object/header names do not collide). Structs use **fixed buffers**. Application data never uses `malloc`.

## Multi-link (N operators, e.g. 3)

There is no dual-only type. 2, 3, or N is `session[N]` + `link[N]` + N WebSockets. Typical 3-way policy: one control CSMS, two telemetry-only.

```c
#define OCPP_CSMS_N 3
ocpp16_session_t ctx[OCPP_CSMS_N]; /* BSS — each ~6 KiB (payload+frame) */

static int ws_send(const void *data, size_t len, void *user); /* user = &ws[i] */

void charger_ocpp_start(void) {
    ocpp_port_init();
    ocpp16_handlers_t h = {0};
    h.reset_req = my_reset;
    h.boot_notification_conf = my_boot_conf;

    ocpp_link_t link[OCPP_CSMS_N];
    const int accept_control[OCPP_CSMS_N] = {1, 0, 0}; /* only CSMS 0 may Reset/RemoteStart */
    ocpp16_boot_notification_req_t boot;
    ocpp16_boot_notification_req_example(&boot);

    for (int i = 0; i < OCPP_CSMS_N; i++) {
        ocpp_link_init(&link[i], i, ws_send, &ws[i], /*heartbeat_timer*/ i, accept_control[i]);
        ocpp16_session_init(&ctx[i], &h, &link[i]);
        ocpp16_session_send_boot_notification(&ctx[i], &boot);
    }
}

void on_ws_text(int i, const char *data, size_t len) {
    ocpp16_session_rx(&ctx[i], data, len);
}

void fanout_status(const ocpp16_status_notification_req_t *req) {
    for (int i = 0; i < OCPP_CSMS_N; i++) {
        ocpp16_session_send_status_notification(&ctx[i], req);
    }
}
```

- **Timer ids** must be unique across all contexts (`0 .. OCPP_PORT_TIMER_MAX-1`, default 16). With 3 links, heartbeat timers `0,1,2` are enough; do not reuse `OCPP_PORT_TIMER_HEARTBEAT` on every session.
- **RAM**: `N * sizeof(ocpp16_session_t)` plus one shared arena. Raise `OCPP_PORT_TIMER_MAX` if you also need boot-retry/call timers per link (`i*3+0` heartbeat, `i*3+1` retry, …).
- **`accept_control=0`**: Reset / RemoteStart / SetChargingProfile / … reply `CallError` `SecurityError` and do not run handlers. Queries such as `GetConfiguration` still answer. Failover: `ocpp16_session_bind()` flipping which index has `accept_control=1`.
- **Telemetry fan-out**: firmware loops `send_*` over the contexts that should see the event.
- Single-link bring-up can still use `ocpp_port_set_send()` and `session_init(s, h, NULL)`.

Put `ocpp16_session_t` in BSS. Override sizes: `OCPP_PORT_ARENA_SIZE`, `OCPP_PAYLOAD_MAX`, `OCPP_FRAME_MAX`, `OCPP_PORT_TIMER_MAX`.

## Porting

| Function | MCU meaning |
| --- | --- |
| `ocpp_port_init` | Bind cJSON hooks to your arena |
| `ocpp_port_malloc/free/realloc` + `ocpp_port_arena_reset` | One static buffer; `free` can be a no-op |
| `ocpp_port_now_ms` | SysTick / `HAL_GetTick` |
| `ocpp_port_timer_start/stop` | HW timer or `ocpp_port_timer_tick()` from SysTick |
| `ocpp_link.send` | Write one WebSocket **text** frame for **that** CSMS |
| `ocpp_port_log` | RTT/UART, or empty |

## 本地编译与测试（Linux 主机）

`c_ocpp/CMakeLists.txt` 只编 **主机**：三份静态库 + 测试程序。命令默认在 **仓库根目录** 执行（能看到 `c_ocpp/` 文件夹）。单片机工程不要用这套 CMake 去链 `test_*`，固件编法见下文「移植与编译框架」。

### 一键脚本

配环境、编库、跑完全部 `ctest`（含 WebSocket 联调）：

```bash
chmod +x c_ocpp/build_and_test.sh   # 只需一次
./c_ocpp/build_and_test.sh
```

常用参数：

```bash
./c_ocpp/build_and_test.sh --clean                 # 删掉 c_ocpp/build 后重来
./c_ocpp/build_and_test.sh -j 8                    # 指定并行数
./c_ocpp/build_and_test.sh -- -G Ninja             # -- 后面交给 cmake 配置
./c_ocpp/build_and_test.sh -- -DPython3_EXECUTABLE=/usr/bin/python3
```

脚本会检查 `cc` / `cmake` / `ctest` / `python3`。成功时应 5/5 Passed。下面各小节是同一流程的拆开说明。

### 环境

| 工具 | 说明 |
| --- | --- |
| C 编译器 | `gcc` 或 `clang`，C11 |
| CMake | ≥ 3.14 |
| Make 或 Ninja | CMake 默认生成器一般是 Make |
| Python 3 | 3.8+ 即可；CSMS **不用 pip**（只用标准库） |

```bash
cc --version
cmake --version
python3 --version
```

Debian / Ubuntu 缺包时：

```bash
sudo apt update
sudo apt install -y build-essential cmake python3
```

代码用本仓库的 MCU 库分支，例如：

```bash
git fetch origin
git checkout cursor/c-ocpp-mcu-76bd
```

### 配置

```bash
cmake -S c_ocpp -B c_ocpp/build
```

- `-S c_ocpp`：源码目录（其中的 `CMakeLists.txt`）
- `-B c_ocpp/build`：产物目录，不要提交进 git

指定编译器或生成器：

```bash
cmake -S c_ocpp -B c_ocpp/build -DCMAKE_C_COMPILER=gcc
cmake -S c_ocpp -B c_ocpp/build -G Ninja
cmake -S c_ocpp -B c_ocpp/build -DPython3_EXECUTABLE=/usr/bin/python3
```

`messages/*.c` 用了 `file(GLOB …)`。增删报文 `.c` 之后要 **再跑一遍这条 cmake**，然后才 `--build`。

### 编译

```bash
cmake --build c_ocpp/build
cmake --build c_ocpp/build -j$(nproc)    # 多核
```

只编某一个目标：

```bash
cmake --build c_ocpp/build --target test_ocpp16
cmake --build c_ocpp/build --target test_ocpp_csms
```

产物都在 `c_ocpp/build/`：

| 文件 | 内容 |
| --- | --- |
| `libc_ocpp_core.a` | cJSON + `ocpp_json.c` + `ocpp_rpc.c` + **主机** `port/ocpp_port.c` |
| `libc_ocpp16.a` | 1.6 session + `ocpp16/messages/*.c`，PUBLIC 链 core |
| `libc_ocpp201.a` | 2.0.1 同上 |
| `test_ocpp16` / `test_ocpp201` / `test_ocpp_both` | 无 socket 的编解码与 session |
| `test_ocpp_csms` | C 客户端（`tests/test_ocpp_csms.c` + `tests/ws_client.c`） |

`c_ocpp_core` 只编一次，避免 1.6 和 2.0.1 各链一份 cJSON / `ocpp_port` 造成符号重复。主机 `ocpp_port.c` 用了 `clock_gettime`，**不能**原样链进裸机。

### 跑测试

```bash
ctest --test-dir c_ocpp/build --output-on-failure
```

应 5/5 Passed：

| 测试 | 做什么 |
| --- | --- |
| `test_ocpp16` | 1.6 全部报文编解码 + Boot / Reset / 三路 session（无网络） |
| `test_ocpp201` | 2.0.1 同样 |
| `test_ocpp_both` | 同一进程同时链接 1.6 与 2.0.1 |
| `test_ocpp_csms_py` | `PYTHONPATH=c_ocpp/csms` 下跑 Python unittest |
| `test_ocpp_csms` | 拉起 Python CSMS，C 客户端走 WebSocket，覆盖全部 1.6 / 2.0.1 的 Request 与 Confirmation |

只跑一类或直接跑二进制：

```bash
ctest --test-dir c_ocpp/build -R test_ocpp16 --output-on-failure
./c_ocpp/build/test_ocpp16
./c_ocpp/build/test_ocpp201
./c_ocpp/build/test_ocpp_both
```

`test_ocpp_csms` 不要只启动二进制：CTest 会执行

```text
python3 c_ocpp/csms/run_live_test.py <build>/test_ocpp_csms
```

脚本占用一个空闲端口、启动 `python3 -m ocpp_csms`，再跑 C 客户端（超时 90 秒）。

### 手动起 CSMS 再连（可选）

`c_ocpp/csms` 是模块化的 1.6 + 2.0.1 服务器，不是固件。协议库本身仍无 TCP；`tests/ws_client.c` 仅主机测试用。

终端 A：

```bash
cd c_ocpp/csms
PYTHONPATH=. python3 -m ocpp_csms --host 127.0.0.1 --port 9000 --interval 3600
```

终端 B（仓库根，且已编译）：

```bash
./c_ocpp/build/test_ocpp_csms 127.0.0.1 9000
```

成功时类似：`all req/conf OCPP 1.6 (14+26) and 2.0.1 (25+40) OK`。

桩 URL：`ws://127.0.0.1:9000/<chargePointId>`，子协议 `ocpp1.6` 或 `ocpp2.0.1`。更多参数见 `c_ocpp/csms/README.md`。

### 常见问题

| 现象 | 处理 |
| --- | --- |
| `Could not find Python3` | 安装 `python3`，或加 `-DPython3_EXECUTABLE=/usr/bin/python3` |
| 新增 `messages/*.c` 没进库 | 再执行一次 `cmake -S c_ocpp -B c_ocpp/build` |
| `test_ocpp_csms` 连不上 / 超时 | 确认本机 `127.0.0.1` 可 listen；不要拦回环 |
| 想看 CSMS 收发 | 不要 `--quiet`，直接 `python3 -m ocpp_csms --port 9000` |

干净重编：

```bash
rm -rf c_ocpp/build
cmake -S c_ocpp -B c_ocpp/build
cmake --build c_ocpp/build -j$(nproc)
ctest --test-dir c_ocpp/build --output-on-failure
```


## 移植与编译框架

仓库里的 `c_ocpp/CMakeLists.txt` 只负责 **Linux 主机**：编静态库 + `ctest`。单片机工程不要直接跑这个 CMake 的测试目标，把同一套 **C 源文件** 编进固件即可。协议层不依赖操作系统、TCP 或 WebSocket。

### 目录与角色

```
c_ocpp/
  port/           唯一允许按芯片改实现的层（默认是 Linux host）
  layer1/         RPC 组帧 + JSON 辅助（cJSON）
  ocpp16/         1.6 消息编解码 + session
  ocpp201/        2.0.1 消息编解码 + session
  third_party/cjson/
  tests/          仅主机；MCU 不要加入编译
  csms/           主机 Python CSMS（1.6 / 2.0.1），给 c_ocpp 联调用
```

对外入口：

- 1.6：`#include "ocpp16.h"`
- 2.0.1：`#include "ocpp201.h"`
- 公共 port：`#include "ocpp_port.h"`

### 必须编译的源文件

公共（任何版本都要）：

| 文件 | 说明 |
| --- | --- |
| `third_party/cjson/cJSON.c` | JSON 树，内存走 `ocpp_port_malloc` |
| `layer1/ocpp_json.c` | 定长字符串拷贝、字段读写 |
| `layer1/ocpp_rpc.c` | `[2\|3\|4, uniqueId, …]` |
| `port/ocpp_port.c` | **主机默认实现**；MCU 用自己的 `.c` 替换，头文件仍用 `ocpp_port.h` |

OCPP 1.6 再加：

- `ocpp16/ocpp16_session.c`
- `ocpp16/messages/*.c`（含各 action、`ocpp16_types.c`、`ocpp16_messages.c`）

OCPP 2.0.1 再加：

- `ocpp201/ocpp201_session.c`
- `ocpp201/messages/*.c`（含各 action、`ocpp201_types.c`、`ocpp201_messages.c`）

两套可以同时链进固件（两路运营商各用一个版本），**同一条 WebSocket 只能跑一个版本**。`port` / `layer1` / `cJSON` 只编一份（CMake 目标 `c_ocpp_core`），不要把这些 `.c` 各链两遍。不要把 `tests/*.c`、`c_ocpp/build/` 编进镜像。

### 1.6 与 2.0.1 会不会文件名冲突

**不会。** 消息 `.c` / `.h` 都带版本前缀，Keil 按文件名生成 `.o` 时不会把两路编成同一个 `authorize.o`：

- `ocpp16/messages/ocpp16_authorize.c` / `ocpp16_authorize.h`
- `ocpp201/messages/ocpp201_authorize.c` / `ocpp201_authorize.h`

C 符号同样是 `ocpp16_*` / `ocpp201_*`。对外仍只 `#include "ocpp16.h"` / `#include "ocpp201.h"`。`port` / `layer1` / `cJSON` 只编一份（`c_ocpp_core`）。同一 `.c` 里可以同时持有两种 session（见 `tests/test_ocpp_both.c`）。编译 `messages/*.c` 时仍建议只加**这一路**的 `messages/` 到 Include。

### Include 路径

全局（应用 + 两个版本一起用时）：

```
c_ocpp
c_ocpp/port
c_ocpp/layer1
c_ocpp/third_party/cjson
c_ocpp/ocpp16
c_ocpp/ocpp201
```

**不要**把 `ocpp16/messages` 和 `ocpp201/messages` 同时放进全局 Include（即使文件已改名前缀，短 `#include "ocpp16_authorize.h"` 仍只应在对应组里解析）。只在编译该目录下 `.c` 时加自己的 `messages/`。

语言：**C11**（`snprintf`、匿名不强依赖）。不要开 C++ 名修饰去编这些 `.c`。需要 `stddef.h` / `stdint.h` / `string.h` / `stdio.h`（`snprintf`）。MCU 上可把 `ocpp_port_log` 做成空函数，避免拉 `vfprintf`。

### 编译期尺寸（按 RAM 改）

在工程预处理宏里覆盖，不要改业务 `.c`：

| 宏 | 默认 | 含义 |
| --- | --- | --- |
| `OCPP_PORT_ARENA_SIZE` | 8192 | cJSON bump 池，编/解最大一帧要装得下 |
| `OCPP_PAYLOAD_MAX` | 2048 | session 里 payload 缓冲 |
| `OCPP_FRAME_MAX` | 4096 | 整帧 `[2,…,payload]` |
| `OCPP_PORT_TIMER_MAX` | 16 | 软件定时器槽，N 路心跳 id 必须互斥 |
| `OCPP16_PENDING_MAX` / `OCPP201_PENDING_MAX` | 8 | 每路未完成 CALL 数 |

`ocpp16_session_t` / `ocpp201_session_t` 内含 payload+frame，**放 BSS/全局**，不要放任务栈。N 路大约 `N × (PAYLOAD + FRAME)` 再加 arena。

### MCU 替换 `port.c`

保留 `ocpp_port.h` 的函数签名，芯片工程提供自己的 `ocpp_port.c`（或同名函数放到你们的 `board/ocpp_port_mcu.c`，编译列表里拿掉 host 的 `port/ocpp_port.c`）。

最低实现：

1. **`ocpp_port_init`**：把 cJSON hook 指到 arena（可抄 host 里 `cJSON_InitHooks` 那段）。
2. **`ocpp_port_malloc` / `free` / `realloc` / `arena_reset`**：一块静态 `uint8_t arena[OCPP_PORT_ARENA_SIZE]`，bump 分配；`free` 空实现。`session_rx` 入口已 `arena_reset`。**不要并行** encode/rx 两个 session。
3. **`ocpp_port_now_ms`**：`HAL_GetTick` / SysTick 毫秒。
4. **定时器**：要么实现 `timer_start/stop` 接硬件周期中断，要么在 1 ms（或 10 ms）节拍里调 `ocpp_port_timer_tick(elapsed_ms)`（可继续用 host 文件里的软件定时器数组，只改时钟源）。
5. **发送**：不要依赖全局 `ocpp_port_set_send`。每条 CSMS 在 `ocpp_link_t.send` 里写 **一条 WebSocket text**（或你们已有的链路）。返回 0 成功、非 0 为 `OCPP_ERR_IO`。
6. **`ocpp_port_log`**：RTT / UART，或空。

Host 的 `ocpp_port_now_ms` 用了 `clock_gettime`，**不能**原样链到裸机。

启动顺序：`ocpp_port_init()` → `ocpp_link_init`（每路 send + 唯一 `heartbeat_timer_id`）→ `ocpp16_session_init` / `ocpp201_session_init` → 连接成功后 `send_boot_notification`。WS 收齐一帧 JSON 后 `session_rx`。

### 嵌进现有固件 CMake（交叉编译）

不要 `add_subdirectory` 后还 `enable_testing` 到设备镜像。推荐自列源文件，并 **排除** host `port/ocpp_port.c`：

```cmake
set(C_OCPP ${CMAKE_SOURCE_DIR}/c_ocpp)

add_library(c_ocpp_core STATIC
    ${C_OCPP}/third_party/cjson/cJSON.c
    ${C_OCPP}/layer1/ocpp_json.c
    ${C_OCPP}/layer1/ocpp_rpc.c
    ${CMAKE_SOURCE_DIR}/port/ocpp_port_mcu.c)
target_include_directories(c_ocpp_core PUBLIC
    ${C_OCPP} ${C_OCPP}/port ${C_OCPP}/layer1 ${C_OCPP}/third_party/cjson)

add_library(c_ocpp16 STATIC
    ${C_OCPP}/ocpp16/ocpp16_session.c
    ${C_OCPP}/ocpp16/messages/ocpp16_authorize.c
    # … 其余 ocpp16/messages/*.c
)
target_include_directories(c_ocpp16 PUBLIC ${C_OCPP}/ocpp16
    PRIVATE ${C_OCPP}/ocpp16/messages)
target_link_libraries(c_ocpp16 PUBLIC c_ocpp_core)
target_compile_definitions(c_ocpp_core PUBLIC
    OCPP_PORT_ARENA_SIZE=4096
    OCPP_PAYLOAD_MAX=1536
    OCPP_FRAME_MAX=3072)
```

交叉编译工具链文件示例（ARM GCC）：

```cmake
# toolchain-arm-none-eabi.cmake
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
```

```bash
cmake -S . -B build-mcu -DCMAKE_TOOLCHAIN_FILE=toolchain-arm-none-eabi.cmake
cmake --build build-mcu
```

主机回归仍用：

```bash
cmake -S c_ocpp -B c_ocpp/build
cmake --build c_ocpp/build
ctest --test-dir c_ocpp/build --output-on-failure
```

### Makefile / Keil / IAR

**Makefile**（摘录）：

```makefile
C_OCPP := c_ocpp
INCLUDES := -I$(C_OCPP) -I$(C_OCPP)/port -I$(C_OCPP)/layer1 -I$(C_OCPP)/third_party/cjson \
            -I$(C_OCPP)/ocpp16
# 编译 ocpp16/messages/*.c 时再加： -I$(C_OCPP)/ocpp16/messages
# 同时编 2.0.1 时：公共 INCLUDES 加 -I$(C_OCPP)/ocpp201，
# 且 messages 的 -I 只加在对应那一组 .c 上，不要两套 messages 同时进全局 -I
CFLAGS += -std=c11 -Wall -Wextra -DOCPP_PORT_ARENA_SIZE=4096
PORT_SRC := board/ocpp_port_mcu.c
CORE_SRC := $(C_OCPP)/third_party/cjson/cJSON.c \
            $(C_OCPP)/layer1/ocpp_json.c $(C_OCPP)/layer1/ocpp_rpc.c
LIB16_SRC := $(C_OCPP)/ocpp16/ocpp16_session.c \
             $(wildcard $(C_OCPP)/ocpp16/messages/*.c)
```

**Keil / IAR：** 建组 `c_ocpp_core` / `c_ocpp16_msg` / `c_ocpp201_msg` / `port`。两组 messages 用**不同**的组 Include（各自的 `messages/`）。应用组不要加两个 `messages/`。

### 移植检查单

- [ ] MCU `port` 已替换，`clock_gettime` / `vfprintf` 不再进镜像（除非你自愿）
- [ ] `ocpp_port_init` 在任何 encode/rx 之前调用
- [ ] 每路 `heartbeat_timer_id` 唯一，且 `< OCPP_PORT_TIMER_MAX`
- [ ] WS text 完整一帧再 `session_rx`（不要半包）
- [ ] session 对象在 BSS；arena 只单线程/单任务使用
- [ ] 子协议与库一致：`ocpp1.6` 配 `c_ocpp16`，`ocpp2.0.1` 配 `c_ocpp201`
- [ ] 同时用 1.6 和 2.0.1 时 `cJSON`/`port`/`layer1` 只编一份；全局 Include 不含两套 `messages/`
- [ ] 主机 `ctest` 仍通过后再切交叉编译
