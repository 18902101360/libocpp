/* Generated OCPP message: MeterValues */
#include "ocpp16_meter_values.h"
#include <string.h>


cJSON *ocpp16_meter_values_req_to_json(const ocpp16_meter_values_req_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    ocpp_json_add_int(obj, "connectorId", in->connectorId);
    { cJSON *arr = cJSON_CreateArray();
      int n = in->meterValue_count; if (n > 4) n = 4;
      for (int i = 0; i < n; i++) {
        cJSON *ch = ocpp16_meter_value_to_json(&in->meterValue[i]); if (ch) cJSON_AddItemToArray(arr, ch);
      }
      cJSON_AddItemToObject(obj, "meterValue", arr); }
    if (in->has_transactionId) ocpp_json_add_int(obj, "transactionId", in->transactionId);
    return obj;
}
ocpp_err_t ocpp16_meter_values_req_from_json(const cJSON *obj, ocpp16_meter_values_req_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    if (ocpp_json_get_int(obj, "connectorId", &out->connectorId, 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *arr = ocpp_json_get_arr(obj, "meterValue", 1); out->meterValue_count = 0;
      if (arr == NULL) return OCPP_ERR_PARSE;
      if (arr) {
        int n = cJSON_GetArraySize(arr); if (n > 4) n = 4;
        for (int i = 0; i < n; i++) {
          if (ocpp16_meter_value_from_json(cJSON_GetArrayItem(arr, i), &out->meterValue[i]) != OCPP_OK) return OCPP_ERR_PARSE;
          out->meterValue_count++;
        }
      }
    }
    out->has_transactionId = ocpp_json_get_int(obj, "transactionId", &out->transactionId, 0) > 0;
    return OCPP_OK;
}
ocpp_err_t ocpp16_meter_values_req_encode(const ocpp16_meter_values_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_meter_values_req_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_meter_values_req_decode(const char *json, ocpp16_meter_values_req_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_meter_values_req_from_json(o, out);
    return rc;
}
void ocpp16_meter_values_req_example(ocpp16_meter_values_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->connectorId = 1;
    out->meterValue_count = 1;
    ocpp16_meter_value_example(&out->meterValue[0]);
}


cJSON *ocpp16_meter_values_conf_to_json(const ocpp16_meter_values_conf_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    (void)in;
    return obj;
}
ocpp_err_t ocpp16_meter_values_conf_from_json(const cJSON *obj, ocpp16_meter_values_conf_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp16_meter_values_conf_encode(const ocpp16_meter_values_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_meter_values_conf_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_meter_values_conf_decode(const char *json, ocpp16_meter_values_conf_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_meter_values_conf_from_json(o, out);
    return rc;
}
void ocpp16_meter_values_conf_example(ocpp16_meter_values_conf_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}

