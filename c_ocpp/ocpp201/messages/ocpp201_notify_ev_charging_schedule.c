#include "ocpp201_notify_ev_charging_schedule.h"
#include <string.h>

cJSON *ocpp201_notify_ev_charging_schedule_req_to_json(const ocpp201_notify_ev_charging_schedule_req_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "timeBase", in->timeBase) < 0) { cJSON_Delete(obj); return NULL; }
    if (1) ocpp_json_add_int(obj, "evseId", in->evseId);
    { cJSON *ch=ocpp201_charging_schedule_to_json(&in->chargingSchedule); if (!ch) { cJSON_Delete(obj); return NULL; } cJSON_AddItemToObject(obj, "chargingSchedule", ch); }
    return obj;
}
ocpp_err_t ocpp201_notify_ev_charging_schedule_req_from_json(const cJSON *obj, ocpp201_notify_ev_charging_schedule_req_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "timeBase", out->timeBase, sizeof(out->timeBase), 1) < 0) return OCPP_ERR_PARSE;
    if (ocpp_json_get_int(obj, "evseId", &out->evseId, 1) < 0) return OCPP_ERR_PARSE;
    { cJSON *ch = ocpp_json_get_obj(obj, "chargingSchedule", 1); if (!ch) return OCPP_ERR_PARSE; if (ocpp201_charging_schedule_from_json(ch, &out->chargingSchedule) != OCPP_OK) return OCPP_ERR_PARSE; }
    return OCPP_OK;
}
ocpp_err_t ocpp201_notify_ev_charging_schedule_req_encode(const ocpp201_notify_ev_charging_schedule_req_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_notify_ev_charging_schedule_req_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_notify_ev_charging_schedule_req_decode(const char *json, ocpp201_notify_ev_charging_schedule_req_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_notify_ev_charging_schedule_req_from_json(o, out);
}
void ocpp201_notify_ev_charging_schedule_req_example(ocpp201_notify_ev_charging_schedule_req_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->timeBase, sizeof(out->timeBase), "2024-01-01T00:00:00Z");
    out->evseId = 1;
    ocpp201_charging_schedule_example(&out->chargingSchedule);
}

cJSON *ocpp201_notify_ev_charging_schedule_conf_to_json(const ocpp201_notify_ev_charging_schedule_conf_t *in) {
    if (!in) return NULL;
    cJSON *obj = cJSON_CreateObject();
    if (!obj) return NULL;
    if (ocpp_json_add_str(obj, "status", in->status) < 0) { cJSON_Delete(obj); return NULL; }
    return obj;
}
ocpp_err_t ocpp201_notify_ev_charging_schedule_conf_from_json(const cJSON *obj, ocpp201_notify_ev_charging_schedule_conf_t *out) {
    if (!obj||!out) return OCPP_ERR_ARG;
    memset(out,0,sizeof(*out));
    if (ocpp_json_get_str(obj, "status", out->status, sizeof(out->status), 1) < 0) return OCPP_ERR_PARSE;
    return OCPP_OK;
}
ocpp_err_t ocpp201_notify_ev_charging_schedule_conf_encode(const ocpp201_notify_ev_charging_schedule_conf_t *in, char *buf, size_t buflen) {
    ocpp_port_arena_reset();
    cJSON *o = ocpp201_notify_ev_charging_schedule_conf_to_json(in);
    if (!o) return OCPP_ERR_NOMEM;
    return ocpp_json_dump(o, buf, buflen);
}
ocpp_err_t ocpp201_notify_ev_charging_schedule_conf_decode(const char *json, ocpp201_notify_ev_charging_schedule_conf_t *out) {
    if (!json||!out) return OCPP_ERR_ARG;
    ocpp_port_arena_reset();
    cJSON *o = cJSON_Parse(json);
    if (!o) return OCPP_ERR_PARSE;
    return ocpp201_notify_ev_charging_schedule_conf_from_json(o, out);
}
void ocpp201_notify_ev_charging_schedule_conf_example(ocpp201_notify_ev_charging_schedule_conf_t *out) {
    memset(out, 0, sizeof(*out));
    ocpp_str_copy(out->status, sizeof(out->status), "Accepted");
}
