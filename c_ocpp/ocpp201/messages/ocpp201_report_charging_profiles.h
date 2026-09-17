#ifndef OCPP201_REPORT_CHARGING_PROFILES_H
#define OCPP201_REPORT_CHARGING_PROFILES_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_REPORT_CHARGING_PROFILES_ACTION "ReportChargingProfiles"
typedef struct ocpp201_report_charging_profiles_req {
    int requestId;
    char chargingLimitSource[21];
    int evseId;
    int chargingProfile_count;
    ocpp201_charging_profile_t chargingProfile[2];
} ocpp201_report_charging_profiles_req_t;
typedef struct ocpp201_report_charging_profiles_conf {
    int unused;
} ocpp201_report_charging_profiles_conf_t;
cJSON *ocpp201_report_charging_profiles_req_to_json(const ocpp201_report_charging_profiles_req_t *in);
ocpp_err_t ocpp201_report_charging_profiles_req_from_json(const cJSON *obj, ocpp201_report_charging_profiles_req_t *out);
ocpp_err_t ocpp201_report_charging_profiles_req_encode(const ocpp201_report_charging_profiles_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_report_charging_profiles_req_decode(const char *json, ocpp201_report_charging_profiles_req_t *out);
void ocpp201_report_charging_profiles_req_example(ocpp201_report_charging_profiles_req_t *out);
cJSON *ocpp201_report_charging_profiles_conf_to_json(const ocpp201_report_charging_profiles_conf_t *in);
ocpp_err_t ocpp201_report_charging_profiles_conf_from_json(const cJSON *obj, ocpp201_report_charging_profiles_conf_t *out);
ocpp_err_t ocpp201_report_charging_profiles_conf_encode(const ocpp201_report_charging_profiles_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_report_charging_profiles_conf_decode(const char *json, ocpp201_report_charging_profiles_conf_t *out);
void ocpp201_report_charging_profiles_conf_example(ocpp201_report_charging_profiles_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif
