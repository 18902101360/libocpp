#include "transaction_event.h"
#include <string.h>

cJSON *ocpp201_transaction_event_req_to_json(const ocpp201_transaction_event_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "eventType", in->eventType) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "timestamp", in->timestamp) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "triggerReason", in->triggerReason) < 0) { cJSON_Delete(obj); return NULL; }
    if (1) ocpp_json_add_int(obj, "seqNo", in->seqNo);
    { cJSON *ch=ocpp201_transaction_info_to_json(&in->transactionInfo); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "transactionInfo", ch); }
    return obj;
}
ocpp_err_t ocpp201_transaction_event_req_from_json(const cJSON *obj, ocpp201_transaction_event_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "eventType", out->eventType, sizeof(out->eventType), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "timestamp", out->timestamp, sizeof(out->timestamp), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "triggerReason", out->triggerReason, sizeof(out->triggerReason), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "seqNo", &out->seqNo, 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "transactionInfo", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_transaction_info_from_json(ch, &out->transactionInfo) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
ocpp_err_t ocpp201_transaction_event_req_encode(const ocpp201_transaction_event_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_transaction_event_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_transaction_event_req_decode(const char *json, ocpp201_transaction_event_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_transaction_event_req_from_json(o, out);
}
void ocpp201_transaction_event_req_example(ocpp201_transaction_event_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->eventType, sizeof(out->eventType), "Started");
    ocpp_str_copy(out->timestamp, sizeof(out->timestamp), "2024-01-01T00:00:00Z");
    ocpp_str_copy(out->triggerReason, sizeof(out->triggerReason), "Authorized");
    out->seqNo = 0;
    ocpp201_transaction_info_example(&out->transactionInfo);
}

cJSON *ocpp201_transaction_event_conf_to_json(const ocpp201_transaction_event_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    (void)in; return obj;
}
ocpp_err_t ocpp201_transaction_event_conf_from_json(const cJSON *obj, ocpp201_transaction_event_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp201_transaction_event_conf_encode(const ocpp201_transaction_event_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_transaction_event_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_transaction_event_conf_decode(const char *json, ocpp201_transaction_event_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_transaction_event_conf_from_json(o, out);
}
void ocpp201_transaction_event_conf_example(ocpp201_transaction_event_conf_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}
