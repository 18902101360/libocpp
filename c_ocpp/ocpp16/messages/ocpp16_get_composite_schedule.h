/* Generated OCPP message: GetCompositeSchedule */
#ifndef OCPP16_GET_COMPOSITE_SCHEDULE_H
#define OCPP16_GET_COMPOSITE_SCHEDULE_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_GET_COMPOSITE_SCHEDULE_ACTION "GetCompositeSchedule"

typedef struct ocpp16_get_composite_schedule_req {
    int connectorId;
    int duration;
    int has_chargingRateUnit;
    char chargingRateUnit[9];
} ocpp16_get_composite_schedule_req_t;

typedef struct ocpp16_get_composite_schedule_conf {
    char status[17];
    int has_connectorId;
    int connectorId;
    int has_chargingSchedule;
    ocpp16_charging_schedule_t chargingSchedule;
} ocpp16_get_composite_schedule_conf_t;

cJSON *ocpp16_get_composite_schedule_req_to_json(const ocpp16_get_composite_schedule_req_t *in);
ocpp_err_t ocpp16_get_composite_schedule_req_from_json(const cJSON *obj, ocpp16_get_composite_schedule_req_t *out);
ocpp_err_t ocpp16_get_composite_schedule_req_encode(const ocpp16_get_composite_schedule_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_get_composite_schedule_req_decode(const char *json, ocpp16_get_composite_schedule_req_t *out);
void ocpp16_get_composite_schedule_req_example(ocpp16_get_composite_schedule_req_t *out);

cJSON *ocpp16_get_composite_schedule_conf_to_json(const ocpp16_get_composite_schedule_conf_t *in);
ocpp_err_t ocpp16_get_composite_schedule_conf_from_json(const cJSON *obj, ocpp16_get_composite_schedule_conf_t *out);
ocpp_err_t ocpp16_get_composite_schedule_conf_encode(const ocpp16_get_composite_schedule_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_get_composite_schedule_conf_decode(const char *json, ocpp16_get_composite_schedule_conf_t *out);
void ocpp16_get_composite_schedule_conf_example(ocpp16_get_composite_schedule_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif
