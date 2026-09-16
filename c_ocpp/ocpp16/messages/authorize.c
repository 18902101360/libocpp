/* Generated OCPP message: Authorize */
#include "authorize.h"
#include <string.h>


cJSON *ocpp16_authorize_req_to_json(const ocpp16_authorize_req_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    if (ocpp_json_add_str(obj, "idTag", in->idTag) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp16_authorize_req_from_json(const cJSON *obj, ocpp16_authorize_req_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    if (ocpp_json_get_str(obj, "idTag", out->idTag, sizeof(out->idTag), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp16_authorize_req_encode(const ocpp16_authorize_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_authorize_req_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_authorize_req_decode(const char *json, ocpp16_authorize_req_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_authorize_req_from_json(o, out);
    return rc;
}
void ocpp16_authorize_req_example(ocpp16_authorize_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->idTag, sizeof(out->idTag), "TAG001");
}


cJSON *ocpp16_authorize_conf_to_json(const ocpp16_authorize_conf_t *in) {
    if (in == NULL) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (obj == NULL) return NULL;
    { cJSON *ch = ocpp16_id_tag_info_to_json(&in->idTagInfo); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "idTagInfo", ch); }
    return obj;
}
ocpp_err_t ocpp16_authorize_conf_from_json(const cJSON *obj, ocpp16_authorize_conf_t *out) {
    if (obj == NULL || out == NULL) return OCPP_ERR_ARG;
    memset(out, 0, sizeof(*out));
    { cJSON *ch = ocpp_json_get_obj(obj, "idTagInfo", 1);
      if (ch == NULL) return OCPP_ERR_PARSE;
      if (ocpp16_id_tag_info_from_json(ch, &out->idTagInfo) != OCPP_OK) return OCPP_ERR_PARSE;
    }
    return OCPP_OK;
}
ocpp_err_t ocpp16_authorize_conf_encode(const ocpp16_authorize_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp16_authorize_conf_to_json(in);
    if (o == NULL) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp16_authorize_conf_decode(const char *json, ocpp16_authorize_conf_t *out) {
    if (json == NULL || out == NULL) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (o == NULL) return OCPP_ERR_PARSE;
    ocpp_err_t rc = ocpp16_authorize_conf_from_json(o, out);
    return rc;
}
void ocpp16_authorize_conf_example(ocpp16_authorize_conf_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp16_id_tag_info_example(&out->idTagInfo);
}

