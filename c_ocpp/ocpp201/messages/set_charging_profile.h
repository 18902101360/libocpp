#ifndef OCPP201_SET_CHARGING_PROFILE_H
#define OCPP201_SET_CHARGING_PROFILE_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_SET_CHARGING_PROFILE_ACTION "SetChargingProfile"
typedef struct ocpp201_set_charging_profile_req {
    int evseId;
    ocpp201_charging_profile_t chargingProfile;
} ocpp201_set_charging_profile_req_t;
typedef struct ocpp201_set_charging_profile_conf {
    char status[17];
} ocpp201_set_charging_profile_conf_t;
cJSON *ocpp201_set_charging_profile_req_to_json(const ocpp201_set_charging_profile_req_t *in);
ocpp_err_t ocpp201_set_charging_profile_req_from_json(const cJSON *obj, ocpp201_set_charging_profile_req_t *out);
ocpp_err_t ocpp201_set_charging_profile_req_encode(const ocpp201_set_charging_profile_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_set_charging_profile_req_decode(const char *json, ocpp201_set_charging_profile_req_t *out);
void ocpp201_set_charging_profile_req_example(ocpp201_set_charging_profile_req_t *out);
cJSON *ocpp201_set_charging_profile_conf_to_json(const ocpp201_set_charging_profile_conf_t *in);
ocpp_err_t ocpp201_set_charging_profile_conf_from_json(const cJSON *obj, ocpp201_set_charging_profile_conf_t *out);
ocpp_err_t ocpp201_set_charging_profile_conf_encode(const ocpp201_set_charging_profile_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_set_charging_profile_conf_decode(const char *json, ocpp201_set_charging_profile_conf_t *out);
void ocpp201_set_charging_profile_conf_example(ocpp201_set_charging_profile_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif
