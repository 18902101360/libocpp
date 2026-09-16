#include "reservation_status_update.h"
#include <string.h>

cJSON *ocpp201_reservation_status_update_req_to_json(const ocpp201_reservation_status_update_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (1) ocpp_json_add_int(obj, "reservationId", in->reservationId);
    if (ocpp_json_add_str(obj, "reservationUpdateStatus", in->reservationUpdateStatus) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_reservation_status_update_req_from_json(const cJSON *obj, ocpp201_reservation_status_update_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_int(obj, "reservationId", &out->reservationId, 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_str(obj, "reservationUpdateStatus", out->reservationUpdateStatus, sizeof(out->reservationUpdateStatus), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp201_reservation_status_update_req_encode(const ocpp201_reservation_status_update_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_reservation_status_update_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_reservation_status_update_req_decode(const char *json, ocpp201_reservation_status_update_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_reservation_status_update_req_from_json(o, out);
}
void ocpp201_reservation_status_update_req_example(ocpp201_reservation_status_update_req_t *out) {
    memset(out, 0, sizeof(*out));
    out->reservationId = 1;
    ocpp_str_copy(out->reservationUpdateStatus, sizeof(out->reservationUpdateStatus), "Expired");
}

cJSON *ocpp201_reservation_status_update_conf_to_json(const ocpp201_reservation_status_update_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    (void)in; return obj;
}
ocpp_err_t ocpp201_reservation_status_update_conf_from_json(const cJSON *obj, ocpp201_reservation_status_update_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    (void)obj;
    (void)out;
    return OCPP_OK;
}
ocpp_err_t ocpp201_reservation_status_update_conf_encode(const ocpp201_reservation_status_update_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_reservation_status_update_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_reservation_status_update_conf_decode(const char *json, ocpp201_reservation_status_update_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_reservation_status_update_conf_from_json(o, out);
}
void ocpp201_reservation_status_update_conf_example(ocpp201_reservation_status_update_conf_t *out) {
    memset(out, 0, sizeof(*out));
    (void)out;
}
