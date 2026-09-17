/* SPDX-License-Identifier: Apache-2.0
 * 第 1 层：OCPP JSON-RPC 外壳 [2|3|4, uniqueId, …]。不管业务 payload 语义。
 */
#ifndef OCPP_RPC_H
#define OCPP_RPC_H

#include "cJSON.h"
#include "ocpp_err.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP_RPC_CALL 2       /* Charge Point 或 CSMS 发起的请求 */
#define OCPP_RPC_CALLRESULT 3 /* 对 CALL 的成功应答 */
#define OCPP_RPC_CALLERROR 4  /* 对 CALL 的错误应答 */

#define OCPP_UID_MAX 36
#define OCPP_ACTION_MAX 48
#define OCPP_ERROR_CODE_MAX 32

typedef struct ocpp_rpc_msg {
    int type; /* OCPP_RPC_CALL / CALLRESULT / CALLERROR */
    char unique_id[OCPP_UID_MAX + 1];
    char action[OCPP_ACTION_MAX + 1];                 /* 仅 CALL */
    char error_code[OCPP_ERROR_CODE_MAX + 1];         /* 仅 CALLERROR */
    char error_description[64];
    cJSON *payload; /* 来自 arena；ocpp_port_arena_reset 后不可再用 */
} ocpp_rpc_msg_t;

ocpp_err_t ocpp_rpc_pack_call(const char *unique_id, const char *action, const char *payload_json, char *out,
                              size_t outlen);
ocpp_err_t ocpp_rpc_pack_callresult(const char *unique_id, const char *payload_json, char *out, size_t outlen);
ocpp_err_t ocpp_rpc_pack_callerror(const char *unique_id, const char *code, const char *desc, char *out, size_t outlen);

/** 解析一整帧文本。payload 指向 cJSON 树，调用方须在下次 arena_reset 前用完。 */
ocpp_err_t ocpp_rpc_unpack(const char *frame, size_t len, ocpp_rpc_msg_t *out);

#ifdef __cplusplus
}
#endif

#endif
