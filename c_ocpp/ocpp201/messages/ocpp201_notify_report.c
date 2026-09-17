#include "ocpp201_notify_report.h"
#include <string.h>

cJSON *ocpp201_notify_report_req_to_json(const ocpp201_notify_report_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "requestId", in->requestId);
    if (ocpp_json_add_str(obj, "generatedAt", in->generatedAt) < 0) { cJSON_Delete(obj); return NULL; }
    if (1) ocpp_json_add_int(obj, "seqNo", in->seqNo);
    return obj;
}
ocpp_err_t ocpp201_notify_report_req_from_json(const cJSON *obj, ocpp201_notify_report_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "requestId", &out->requestId, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "generatedAt", out->generatedAt, sizeof(out->generatedAt), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "seqNo", &out->seqNo, 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp201_notify_report_req_encode(const ocpp201_notify_report_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_notify_report_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_notify_report_req_decode(const char *json, ocpp201_notify_report_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_notify_report_req_from_json(o, out);
}
void ocpp201_notify_report_req_example(ocpp201_notify_report_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->requestId = 1;
    ocpp_str_copy(out->generatedAt, sizeof(out->generatedAt), "2024-01-01T00:00:00Z");
    out->seqNo = 0;
}

cJSON *ocpp201_notify_report_conf_to_json(const ocpp201_notify_report_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    (void)in; return obj;
}
ocpp_err_t ocpp201_notify_report_conf_from_json(const cJSON *obj, ocpp201_notify_report_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp201_notify_report_conf_encode(const ocpp201_notify_report_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_notify_report_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_notify_report_conf_decode(const char *json, ocpp201_notify_report_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_notify_report_conf_from_json(o, out);
}
void ocpp201_notify_report_conf_example(ocpp201_notify_report_conf_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}
