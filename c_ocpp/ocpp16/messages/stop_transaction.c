/* Generated OCPP message: StopTransaction */
#include "stop_transaction.h"
#include <string.h>


cJSON *ocpp16_stop_transaction_req_to_json(const ocpp16_stop_transaction_req_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    ocpp_json_add_int(obj, "transactionId", in->transactionId);
    if (ocpp_json_add_str(obj, "timestamp", in->timestamp) < 0) { cJSON_Delete(obj); return NULL; }
    ocpp_json_add_int(obj, "meterStop", in->meterStop);
    if (in->has_idTag) ocpp_json_add_str(obj, "idTag", in->idTag);
    if (in->has_reason) ocpp_json_add_str(obj, "reason", in->reason);
    return obj;
}
ocpp_err_t ocpp16_stop_transaction_req_from_json(const cJSON *obj, ocpp16_stop_transaction_req_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    if (ocpp_json_get_int(obj, "transactionId", &out->transactionId, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "timestamp", out->timestamp, sizeof(out->timestamp), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "meterStop", &out->meterStop, 1) < 0) return OCPP_ERR_PARSE;
    out->has_idTag = ocpp_json_get_str(obj, "idTag", out->idTag, sizeof(out->idTag), 0) > 0;
    out->has_reason = ocpp_json_get_str(obj, "reason", out->reason, sizeof(out->reason), 0) > 0;
    return OCPP_OK;
}
ocpp_err_t ocpp16_stop_transaction_req_encode(const ocpp16_stop_transaction_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_stop_transaction_req_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_stop_transaction_req_decode(const char *json, ocpp16_stop_transaction_req_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_stop_transaction_req_from_json(o, out);
    return rc;
}
void ocpp16_stop_transaction_req_example(ocpp16_stop_transaction_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->transactionId = 42;
    ocpp_str_copy(out->timestamp, sizeof(out->timestamp), "2024-01-01T00:10:00Z");
    out->meterStop = 1500;
}


cJSON *ocpp16_stop_transaction_conf_to_json(const ocpp16_stop_transaction_conf_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    if (in->has_idTagInfo) { cJSON *ch = ocpp16_id_tag_info_to_json(&in->idTagInfo); if (ch) cJSON_AddItemToObject(obj, "idTagInfo", ch); }
    return obj;
}
ocpp_err_t ocpp16_stop_transaction_conf_from_json(const cJSON *obj, ocpp16_stop_transaction_conf_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    { cJSON *ch = ocpp_json_get_obj(obj, "idTagInfo", 0);
      if (ch) { out->has_idTagInfo = 1; if (ocpp16_id_tag_info_from_json(ch, &out->idTagInfo) != OCPP_OK) return OCPP_ERR_PARSE; }
      else { out->has_idTagInfo = 0; }
    }
    return OCPP_OK;
}
ocpp_err_t ocpp16_stop_transaction_conf_encode(const ocpp16_stop_transaction_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_stop_transaction_conf_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_stop_transaction_conf_decode(const char *json, ocpp16_stop_transaction_conf_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_stop_transaction_conf_from_json(o, out);
    return rc;
}
void ocpp16_stop_transaction_conf_example(ocpp16_stop_transaction_conf_t *out) {
    memset(out, 0, sizeof(*out));
}

