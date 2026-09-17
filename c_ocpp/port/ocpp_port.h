/* SPDX-License-Identifier: Apache-2.0
 *
 * MCU 移植层。协议代码不直接 malloc / 读时钟 / 发网络。
 * 芯片工程保留本头文件，替换 ocpp_port.c（或提供同名函数并排除 host 实现）。
 *
 * 多路 CSMS：每个 session 绑自己的 ocpp_link_t；cJSON arena 全局一份，
 * encode / session_rx 不要并行。
 */
#ifndef OCPP_PORT_H
#define OCPP_PORT_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef OCPP_PORT_ARENA_SIZE
#define OCPP_PORT_ARENA_SIZE 8192u /* cJSON bump 池字节数，按最大一帧加大 */
#endif

#ifndef OCPP_PORT_TIMER_MAX
#define OCPP_PORT_TIMER_MAX 16 /* 软件定时器槽个数，心跳 id 必须互斥 */
#endif

/* 单路默认槽位。多路时请自己编号，例如第 i 路心跳用 timer id = i，不要每路都用 0。 */
#define OCPP_PORT_TIMER_HEARTBEAT 0
#define OCPP_PORT_TIMER_BOOT_RETRY 1
#define OCPP_PORT_TIMER_CALL 2

/** 定时器到期回调。timer_id 即 start 时传入的槽号；ctx 一般是 session 指针。 */
typedef void (*ocpp_port_timer_fn)(int timer_id, void *ctx);
/** 发一帧 JSON 文本。成功返回 0，失败非 0（session 映射为 OCPP_ERR_IO）。user 为 send_user。 */
typedef int (*ocpp_port_send_fn)(const void *data, size_t len, void *user);

/**
 * 一条到 CSMS 的传输与策略，嵌入 session。
 * id：固件自己编号（0,1,2…），便于 handler 里区分运营商。
 * send / send_user：写到该路 WebSocket text（或你们已有链路）。
 * heartbeat_timer_id：Boot 被 Accepted 后启动的周期心跳槽，全工程唯一。
 * accept_control：1=执行 Reset/RemoteStart 等；0=遥测路，控制类 CALL 回 SecurityError。
 */
typedef struct ocpp_link {
    int id;
    ocpp_port_send_fn send;
    void *send_user;
    int heartbeat_timer_id;
    int accept_control;
} ocpp_link_t;

void ocpp_link_init(ocpp_link_t *link, int id, ocpp_port_send_fn send, void *user,
                    int heartbeat_timer_id, int accept_control);
/** 优先 link->send；未绑定时回落到全局 ocpp_port_send。 */
int ocpp_link_send(const ocpp_link_t *link, const void *data, size_t len);
/** 1=会改桩状态的 CSMS action（Reset、RemoteStart、SetChargingProfile…）。 */
int ocpp_action_is_control(const char *action);

/** 启动时调用一次：把 cJSON 钩到 arena，并清定时器表。 */
void ocpp_port_init(void);

/** cJSON 用的 bump 分配。free 可为 no-op；每轮编解码前 reset。 */
void *ocpp_port_malloc(size_t size);
void ocpp_port_free(void *ptr);
void *ocpp_port_realloc(void *ptr, size_t size);
void ocpp_port_arena_reset(void);
size_t ocpp_port_arena_used(void);

/** 单调毫秒。MCU 用 SysTick / HAL_GetTick。 */
uint32_t ocpp_port_now_ms(void);

int ocpp_port_timer_start(int timer_id, uint32_t delay_ms, int periodic, ocpp_port_timer_fn fn, void *ctx);
void ocpp_port_timer_stop(int timer_id);
/** 推进软件定时器。MCU 可在节拍中断里调，elapsed_ms 为距上次的间隔。 */
void ocpp_port_timer_tick(uint32_t elapsed_ms);

/** 仅单路、且 link.send 为空时使用。多路请走 ocpp_link_t.send。 */
void ocpp_port_set_send(ocpp_port_send_fn fn, void *user);
int ocpp_port_send(const void *data, size_t len);

void ocpp_port_log(const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* OCPP_PORT_H */
