#include "ocpp201_get15118_ev_certificate.h"
#include <string.h>

cJSON *ocpp201_get15118_ev_certificate_req_to_json(const ocpp201_get15118_ev_certificate_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "iso15118SchemaVersion", in->iso15118SchemaVersion) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "action", in->action) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "exiRequest", in->exiRequest) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_get15118_ev_certificate_req_from_json(const cJSON *obj, ocpp201_get15118_ev_certificate_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "iso15118SchemaVersion", out->iso15118SchemaVersion, sizeof(out->iso15118SchemaVersion), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "action", out->action, sizeof(out->action), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "exiRequest", out->exiRequest, sizeof(out->exiRequest), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp201_get15118_ev_certificate_req_encode(const ocpp201_get15118_ev_certificate_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_get15118_ev_certificate_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_get15118_ev_certificate_req_decode(const char *json, ocpp201_get15118_ev_certificate_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_get15118_ev_certificate_req_from_json(o, out);
}
void ocpp201_get15118_ev_certificate_req_example(ocpp201_get15118_ev_certificate_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->iso15118SchemaVersion, sizeof(out->iso15118SchemaVersion), "urn:iso:15118:2:2013:MsgDef");
    ocpp_str_copy(out->action, sizeof(out->action), "Install");
    ocpp_str_copy(out->exiRequest, sizeof(out->exiRequest), "ZXhp");
}

cJSON *ocpp201_get15118_ev_certificate_conf_to_json(const ocpp201_get15118_ev_certificate_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    if (ocpp_json_add_str(obj, "exiResponse", in->exiResponse) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_get15118_ev_certificate_conf_from_json(const cJSON *obj, ocpp201_get15118_ev_certificate_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "exiResponse", out->exiResponse, sizeof(out->exiResponse), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp201_get15118_ev_certificate_conf_encode(const ocpp201_get15118_ev_certificate_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_get15118_ev_certificate_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_get15118_ev_certificate_conf_decode(const char *json, ocpp201_get15118_ev_certificate_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_get15118_ev_certificate_conf_from_json(o, out);
}
void ocpp201_get15118_ev_certificate_conf_example(ocpp201_get15118_ev_certificate_conf_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Accepted");
    ocpp_str_copy(out->exiResponse, sizeof(out->exiResponse), "ZXhp");
}
