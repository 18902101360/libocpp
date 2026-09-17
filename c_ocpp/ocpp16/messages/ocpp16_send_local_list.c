/* Generated OCPP message: SendLocalList */
#include "ocpp16_send_local_list.h"
#include <string.h>


cJSON *ocpp16_send_local_list_req_to_json(const ocpp16_send_local_list_req_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    ocpp_json_add_int(obj, "listVersion", in->listVersion);
    if (ocpp_json_add_str(obj, "updateType", in->updateType) < 0) { cJSON_Delete(obj); return NULL; }
    { cJSON *arr = cJSON_CreateArray();
      int n = in->localAuthorizationList_count; if (n > 8) n = 8;
      for (int i = 0; i < n; i++) {
        cJSON *ch = ocpp16_auth_data_to_json(&in->localAuthorizationList[i]); if (ch) cJSON_AddItemToArray(arr, ch);
      }
      cJSON_AddItemToObject(obj, "localAuthorizationList", arr); }
    return obj;
}
ocpp_err_t ocpp16_send_local_list_req_from_json(const cJSON *obj, ocpp16_send_local_list_req_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    if (ocpp_json_get_int(obj, "listVersion", &out->listVersion, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "updateType", out->updateType, sizeof(out->updateType), 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *arr = ocpp_json_get_arr(obj, "localAuthorizationList", 0); out->localAuthorizationList_count = 0;
      if (arr) {
        int n = cJSON_GetArraySize(arr); if (n > 8) n = 8;
        for (int i = 0; i < n; i++) {
          if (ocpp16_auth_data_from_json(cJSON_GetArrayItem(arr, i), &out->localAuthorizationList[i]) != OCPP_OK) return OCPP_ERR_PARSE;
          out->localAuthorizationList_count++;
        }
      }
    }
    return OCPP_OK;
}
ocpp_err_t ocpp16_send_local_list_req_encode(const ocpp16_send_local_list_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_send_local_list_req_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_send_local_list_req_decode(const char *json, ocpp16_send_local_list_req_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_send_local_list_req_from_json(o, out);
    return rc;
}
void ocpp16_send_local_list_req_example(ocpp16_send_local_list_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->listVersion = 2;
    ocpp_str_copy(out->updateType, sizeof(out->updateType), "Full");
}


cJSON *ocpp16_send_local_list_conf_to_json(const ocpp16_send_local_list_conf_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp16_send_local_list_conf_from_json(const cJSON *obj, ocpp16_send_local_list_conf_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp16_send_local_list_conf_encode(const ocpp16_send_local_list_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_send_local_list_conf_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_send_local_list_conf_decode(const char *json, ocpp16_send_local_list_conf_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_send_local_list_conf_from_json(o, out);
    return rc;
}
void ocpp16_send_local_list_conf_example(ocpp16_send_local_list_conf_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Accepted");
}

