/* Generated OCPP message: StartTransaction */
#ifndef OCPP16_START_TRANSACTION_H
#define OCPP16_START_TRANSACTION_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_START_TRANSACTION_ACTION "StartTransaction"

typedef struct ocpp16_start_transaction_req {
    int connectorId;
    char idTag[22];
    int meterStart;
    char timestamp[33];
    int has_reservationId;
    int reservationId;
} ocpp16_start_transaction_req_t;

typedef struct ocpp16_start_transaction_conf {
    ocpp16_id_tag_info_t idTagInfo;
    int transactionId;
} ocpp16_start_transaction_conf_t;

cJSON *ocpp16_start_transaction_req_to_json(const ocpp16_start_transaction_req_t *in);
ocpp_err_t ocpp16_start_transaction_req_from_json(const cJSON *obj, ocpp16_start_transaction_req_t *out);
ocpp_err_t ocpp16_start_transaction_req_encode(const ocpp16_start_transaction_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_start_transaction_req_decode(const char *json, ocpp16_start_transaction_req_t *out);
void ocpp16_start_transaction_req_example(ocpp16_start_transaction_req_t *out);

cJSON *ocpp16_start_transaction_conf_to_json(const ocpp16_start_transaction_conf_t *in);
ocpp_err_t ocpp16_start_transaction_conf_from_json(const cJSON *obj, ocpp16_start_transaction_conf_t *out);
ocpp_err_t ocpp16_start_transaction_conf_encode(const ocpp16_start_transaction_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_start_transaction_conf_decode(const char *json, ocpp16_start_transaction_conf_t *out);
void ocpp16_start_transaction_conf_example(ocpp16_start_transaction_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif
