/* Generated OCPP message: RemoteStartTransaction */
#ifndef OCPP16_REMOTE_START_TRANSACTION_H
#define OCPP16_REMOTE_START_TRANSACTION_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_REMOTE_START_TRANSACTION_ACTION "RemoteStartTransaction"

typedef struct ocpp16_remote_start_transaction_req {
    char idTag[22];
    int has_connectorId;
    int connectorId;
} ocpp16_remote_start_transaction_req_t;

typedef struct ocpp16_remote_start_transaction_conf {
    char status[17];
} ocpp16_remote_start_transaction_conf_t;

cJSON *ocpp16_remote_start_transaction_req_to_json(const ocpp16_remote_start_transaction_req_t *in);
ocpp_err_t ocpp16_remote_start_transaction_req_from_json(const cJSON *obj, ocpp16_remote_start_transaction_req_t *out);
ocpp_err_t ocpp16_remote_start_transaction_req_encode(const ocpp16_remote_start_transaction_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_remote_start_transaction_req_decode(const char *json, ocpp16_remote_start_transaction_req_t *out);
void ocpp16_remote_start_transaction_req_example(ocpp16_remote_start_transaction_req_t *out);

cJSON *ocpp16_remote_start_transaction_conf_to_json(const ocpp16_remote_start_transaction_conf_t *in);
ocpp_err_t ocpp16_remote_start_transaction_conf_from_json(const cJSON *obj, ocpp16_remote_start_transaction_conf_t *out);
ocpp_err_t ocpp16_remote_start_transaction_conf_encode(const ocpp16_remote_start_transaction_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_remote_start_transaction_conf_decode(const char *json, ocpp16_remote_start_transaction_conf_t *out);
void ocpp16_remote_start_transaction_conf_example(ocpp16_remote_start_transaction_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif
