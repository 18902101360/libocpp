#include "ocpp201_get_transaction_status.h"
#include <string.h>

cJSON *ocpp201_get_transaction_status_req_to_json(const ocpp201_get_transaction_status_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (in->has_transactionId) ocpp_json_add_str(obj, "transactionId", in->transactionId);
    return obj;
}
ocpp_err_t ocpp201_get_transaction_status_req_from_json(const cJSON *obj, ocpp201_get_transaction_status_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    out->has_transactionId = ocpp_json_get_str(obj, "transactionId", out->transactionId, sizeof(out->transactionId), 0) > 0;
    return OCPP_OK;
}
ocpp_err_t ocpp201_get_transaction_status_req_encode(const ocpp201_get_transaction_status_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_get_transaction_status_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_get_transaction_status_req_decode(const char *json, ocpp201_get_transaction_status_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_get_transaction_status_req_from_json(o, out);
}
void ocpp201_get_transaction_status_req_example(ocpp201_get_transaction_status_req_t *out) {
    memset(out, 0, sizeof(*out));
}

cJSON *ocpp201_get_transaction_status_conf_to_json(const ocpp201_get_transaction_status_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_bool(obj, "messagesInQueue", in->messagesInQueue);
    return obj;
}
ocpp_err_t ocpp201_get_transaction_status_conf_from_json(const cJSON *obj, ocpp201_get_transaction_status_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_bool(obj, "messagesInQueue", &out->messagesInQueue, 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp201_get_transaction_status_conf_encode(const ocpp201_get_transaction_status_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_get_transaction_status_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_get_transaction_status_conf_decode(const char *json, ocpp201_get_transaction_status_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_get_transaction_status_conf_from_json(o, out);
}
void ocpp201_get_transaction_status_conf_example(ocpp201_get_transaction_status_conf_t *out) {
    memset(out, 0, sizeof(*out));
    out->messagesInQueue = 0;
}
