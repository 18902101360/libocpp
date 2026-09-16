#ifndef OCPP201_CHANGE_AVAILABILITY_H
#define OCPP201_CHANGE_AVAILABILITY_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_CHANGE_AVAILABILITY_ACTION "ChangeAvailability"
typedef struct ocpp201_change_availability_req {
    char operationalStatus[17];
    int has_evse;
    ocpp201_evse_t evse;
} ocpp201_change_availability_req_t;
typedef struct ocpp201_change_availability_conf {
    char status[17];
} ocpp201_change_availability_conf_t;
cJSON *ocpp201_change_availability_req_to_json(const ocpp201_change_availability_req_t *in);
ocpp_err_t ocpp201_change_availability_req_from_json(const cJSON *obj, ocpp201_change_availability_req_t *out);
ocpp_err_t ocpp201_change_availability_req_encode(const ocpp201_change_availability_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_change_availability_req_decode(const char *json, ocpp201_change_availability_req_t *out);
void ocpp201_change_availability_req_example(ocpp201_change_availability_req_t *out);
cJSON *ocpp201_change_availability_conf_to_json(const ocpp201_change_availability_conf_t *in);
ocpp_err_t ocpp201_change_availability_conf_from_json(const cJSON *obj, ocpp201_change_availability_conf_t *out);
ocpp_err_t ocpp201_change_availability_conf_encode(const ocpp201_change_availability_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_change_availability_conf_decode(const char *json, ocpp201_change_availability_conf_t *out);
void ocpp201_change_availability_conf_example(ocpp201_change_availability_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif
