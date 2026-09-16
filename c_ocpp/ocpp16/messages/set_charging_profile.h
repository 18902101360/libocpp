/* Generated OCPP message: SetChargingProfile */
#ifndef OCPP16_SET_CHARGING_PROFILE_H
#define OCPP16_SET_CHARGING_PROFILE_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_SET_CHARGING_PROFILE_ACTION "SetChargingProfile"

typedef struct ocpp16_set_charging_profile_req {
    int connectorId;
    ocpp16_charging_profile_t csChargingProfiles;
} ocpp16_set_charging_profile_req_t;

typedef struct ocpp16_set_charging_profile_conf {
    char status[17];
} ocpp16_set_charging_profile_conf_t;

cJSON *ocpp16_set_charging_profile_req_to_json(const ocpp16_set_charging_profile_req_t *in);
ocpp_err_t ocpp16_set_charging_profile_req_from_json(const cJSON *obj, ocpp16_set_charging_profile_req_t *out);
ocpp_err_t ocpp16_set_charging_profile_req_encode(const ocpp16_set_charging_profile_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_set_charging_profile_req_decode(const char *json, ocpp16_set_charging_profile_req_t *out);
void ocpp16_set_charging_profile_req_example(ocpp16_set_charging_profile_req_t *out);

cJSON *ocpp16_set_charging_profile_conf_to_json(const ocpp16_set_charging_profile_conf_t *in);
ocpp_err_t ocpp16_set_charging_profile_conf_from_json(const cJSON *obj, ocpp16_set_charging_profile_conf_t *out);
ocpp_err_t ocpp16_set_charging_profile_conf_encode(const ocpp16_set_charging_profile_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_set_charging_profile_conf_decode(const char *json, ocpp16_set_charging_profile_conf_t *out);
void ocpp16_set_charging_profile_conf_example(ocpp16_set_charging_profile_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif
