#include "change_availability.h"
#include <string.h>

cJSON *ocpp201_change_availability_req_to_json(const ocpp201_change_availability_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "operationalStatus", in->operationalStatus) < 0) { cJSON_Delete(obj); return NULL; }
    if (in->has_evse) { cJSON *ch=ocpp201_evse_to_json(&in->evse); if (ch) cJSON_AddItemToObject(obj, "evse", ch); }
    return obj;
}
ocpp_err_t ocpp201_change_availability_req_from_json(const cJSON *obj, ocpp201_change_availability_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "operationalStatus", out->operationalStatus, sizeof(out->operationalStatus), 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "evse", 0); if (ch) { out->has_evse=1; if (ocpp201_evse_from_json(ch, &out->evse) != OCPP_OK) return OCPP_ERR_PARSE; } else out->has_evse=0; }
    return OCPP_OK;
}
ocpp_err_t ocpp201_change_availability_req_encode(const ocpp201_change_availability_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_change_availability_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_change_availability_req_decode(const char *json, ocpp201_change_availability_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_change_availability_req_from_json(o, out);
}
void ocpp201_change_availability_req_example(ocpp201_change_availability_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->operationalStatus, sizeof(out->operationalStatus), "Operative");
}

cJSON *ocpp201_change_availability_conf_to_json(const ocpp201_change_availability_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_change_availability_conf_from_json(const cJSON *obj, ocpp201_change_availability_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp201_change_availability_conf_encode(const ocpp201_change_availability_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_change_availability_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_change_availability_conf_decode(const char *json, ocpp201_change_availability_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_change_availability_conf_from_json(o, out);
}
void ocpp201_change_availability_conf_example(ocpp201_change_availability_conf_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Accepted");
}
