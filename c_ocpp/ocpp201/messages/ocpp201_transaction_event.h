#ifndef OCPP201_TRANSACTION_EVENT_H
#define OCPP201_TRANSACTION_EVENT_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_TRANSACTION_EVENT_ACTION "TransactionEvent"
typedef struct ocpp201_transaction_event_req {
    char eventType[17];
    char timestamp[33];
    char triggerReason[25];
    int seqNo;
    ocpp201_transaction_info_t transactionInfo;
} ocpp201_transaction_event_req_t;
typedef struct ocpp201_transaction_event_conf {
    int unused;
} ocpp201_transaction_event_conf_t;
cJSON *ocpp201_transaction_event_req_to_json(const ocpp201_transaction_event_req_t *in);
ocpp_err_t ocpp201_transaction_event_req_from_json(const cJSON *obj, ocpp201_transaction_event_req_t *out);
ocpp_err_t ocpp201_transaction_event_req_encode(const ocpp201_transaction_event_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_transaction_event_req_decode(const char *json, ocpp201_transaction_event_req_t *out);
void ocpp201_transaction_event_req_example(ocpp201_transaction_event_req_t *out);
cJSON *ocpp201_transaction_event_conf_to_json(const ocpp201_transaction_event_conf_t *in);
ocpp_err_t ocpp201_transaction_event_conf_from_json(const cJSON *obj, ocpp201_transaction_event_conf_t *out);
ocpp_err_t ocpp201_transaction_event_conf_encode(const ocpp201_transaction_event_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_transaction_event_conf_decode(const char *json, ocpp201_transaction_event_conf_t *out);
void ocpp201_transaction_event_conf_example(ocpp201_transaction_event_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif
