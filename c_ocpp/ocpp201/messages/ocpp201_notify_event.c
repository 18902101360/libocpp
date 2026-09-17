#include "ocpp201_notify_event.h"
#include <string.h>

cJSON *ocpp201_notify_event_req_to_json(const ocpp201_notify_event_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "generatedAt", in->generatedAt) < 0) { cJSON_Delete(obj); return NULL; }
    if (1) ocpp_json_add_int(obj, "seqNo", in->seqNo);
    { cJSON *arr=cJSON_CreateArray(); int n=in->eventData_count; if(n>4) n=4; for(int i=0;i<n;i++){ cJSON *ch=ocpp201_event_data_to_json(&in->eventData[i]); if(ch) cJSON_AddItemToArray(arr,ch); } cJSON_AddItemToObject(obj,"eventData",arr); }
    return obj;
}
ocpp_err_t ocpp201_notify_event_req_from_json(const cJSON *obj, ocpp201_notify_event_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "generatedAt", out->generatedAt, sizeof(out->generatedAt), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "seqNo", &out->seqNo, 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *arr = ocpp_json_get_arr(obj, "eventData", 1); out->eventData_count=0; if (!arr) return OCPP_ERR_PARSE; if (arr) { int n=cJSON_GetArraySize(arr); if (n>4) n=4; for (int i=0;i<n;i++) { if (ocpp201_event_data_from_json(cJSON_GetArrayItem(arr,i), &out->eventData[i])!=OCPP_OK) return OCPP_ERR_PARSE; out->eventData_count++; } } }
    return OCPP_OK;
}
ocpp_err_t ocpp201_notify_event_req_encode(const ocpp201_notify_event_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_notify_event_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_notify_event_req_decode(const char *json, ocpp201_notify_event_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_notify_event_req_from_json(o, out);
}
void ocpp201_notify_event_req_example(ocpp201_notify_event_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->generatedAt, sizeof(out->generatedAt), "2024-01-01T00:00:00Z");
    out->seqNo = 0;
    out->eventData_count = 1;
    ocpp201_event_data_example(&out->eventData[0]);
}

cJSON *ocpp201_notify_event_conf_to_json(const ocpp201_notify_event_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    (void)in; return obj;
}
ocpp_err_t ocpp201_notify_event_conf_from_json(const cJSON *obj, ocpp201_notify_event_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp201_notify_event_conf_encode(const ocpp201_notify_event_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_notify_event_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_notify_event_conf_decode(const char *json, ocpp201_notify_event_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_notify_event_conf_from_json(o, out);
}
void ocpp201_notify_event_conf_example(ocpp201_notify_event_conf_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}
