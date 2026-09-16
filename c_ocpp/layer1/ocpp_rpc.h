/* SPDX-License-Identifier: Apache-2.0
 * Layer 1: OCPP JSON-RPC frame pack/unpack. No session, no timers.
 */
#ifndef OCPP_RPC_H
#define OCPP_RPC_H

#include "cJSON.h"
#include "ocpp_err.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP_RPC_CALL 2
#define OCPP_RPC_CALLRESULT 3
#define OCPP_RPC_CALLERROR 4

#define OCPP_UID_MAX 36
#define OCPP_ACTION_MAX 48
#define OCPP_ERROR_CODE_MAX 32

typedef struct ocpp_rpc_msg {
    int type;
    char unique_id[OCPP_UID_MAX + 1];
    char action[OCPP_ACTION_MAX + 1];
    char error_code[OCPP_ERROR_CODE_MAX + 1];
    char error_description[64];
    cJSON *payload; /* arena-backed; invalid after ocpp_port_arena_reset() */
} ocpp_rpc_msg_t;

ocpp_err_t ocpp_rpc_pack_call(const char *unique_id, const char *action, const char *payload_json, char *out,
                              size_t outlen);
ocpp_err_t ocpp_rpc_pack_callresult(const char *unique_id, const char *payload_json, char *out, size_t outlen);
ocpp_err_t ocpp_rpc_pack_callerror(const char *unique_id, const char *code, const char *desc, char *out, size_t outlen);

ocpp_err_t ocpp_rpc_unpack(const char *frame, size_t len, ocpp_rpc_msg_t *out);

#ifdef __cplusplus
}
#endif

#endif
