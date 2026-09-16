/* Generated OCPP message: GetConfiguration */
#include "get_configuration.h"
#include <string.h>


cJSON *ocpp16_get_configuration_req_to_json(const ocpp16_get_configuration_req_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    (void)in;
    return obj;
}
ocpp_err_t ocpp16_get_configuration_req_from_json(const cJSON *obj, ocpp16_get_configuration_req_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp16_get_configuration_req_encode(const ocpp16_get_configuration_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_get_configuration_req_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_get_configuration_req_decode(const char *json, ocpp16_get_configuration_req_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_get_configuration_req_from_json(o, out);
    return rc;
}
void ocpp16_get_configuration_req_example(ocpp16_get_configuration_req_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}


cJSON *ocpp16_get_configuration_conf_to_json(const ocpp16_get_configuration_conf_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    { cJSON *arr = cJSON_CreateArray();
      int n = in->configurationKey_count; if (n > 8) n = 8;
      for (int i = 0; i < n; i++) {
        cJSON *ch = ocpp16_key_value_to_json(&in->configurationKey[i]); if (ch) cJSON_AddItemToArray(arr, ch);
      }
      cJSON_AddItemToObject(obj, "configurationKey", arr); }
    return obj;
}
ocpp_err_t ocpp16_get_configuration_conf_from_json(const cJSON *obj, ocpp16_get_configuration_conf_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    { cJSON *arr = ocpp_json_get_arr(obj, "configurationKey", 0); out->configurationKey_count = 0;
      if (arr) {
        int n = cJSON_GetArraySize(arr); if (n > 8) n = 8;
        for (int i = 0; i < n; i++) {
          if (ocpp16_key_value_from_json(cJSON_GetArrayItem(arr, i), &out->configurationKey[i]) != OCPP_OK) return OCPP_ERR_PARSE;
          out->configurationKey_count++;
        }
      }
    }
    return OCPP_OK;
}
ocpp_err_t ocpp16_get_configuration_conf_encode(const ocpp16_get_configuration_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_get_configuration_conf_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_get_configuration_conf_decode(const char *json, ocpp16_get_configuration_conf_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_get_configuration_conf_from_json(o, out);
    return rc;
}
void ocpp16_get_configuration_conf_example(ocpp16_get_configuration_conf_t *out) {
    memset(out, 0, sizeof(*out));
}

