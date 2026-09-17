#ifndef OCPP201_BOOT_NOTIFICATION_H
#define OCPP201_BOOT_NOTIFICATION_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_BOOT_NOTIFICATION_ACTION "BootNotification"
typedef struct ocpp201_boot_notification_req {
    char reason[21];
    ocpp201_charging_station_t chargingStation;
} ocpp201_boot_notification_req_t;
typedef struct ocpp201_boot_notification_conf {
    char currentTime[33];
    int interval;
    char status[17];
} ocpp201_boot_notification_conf_t;
cJSON *ocpp201_boot_notification_req_to_json(const ocpp201_boot_notification_req_t *in);
ocpp_err_t ocpp201_boot_notification_req_from_json(const cJSON *obj, ocpp201_boot_notification_req_t *out);
ocpp_err_t ocpp201_boot_notification_req_encode(const ocpp201_boot_notification_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_boot_notification_req_decode(const char *json, ocpp201_boot_notification_req_t *out);
void ocpp201_boot_notification_req_example(ocpp201_boot_notification_req_t *out);
cJSON *ocpp201_boot_notification_conf_to_json(const ocpp201_boot_notification_conf_t *in);
ocpp_err_t ocpp201_boot_notification_conf_from_json(const cJSON *obj, ocpp201_boot_notification_conf_t *out);
ocpp_err_t ocpp201_boot_notification_conf_encode(const ocpp201_boot_notification_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_boot_notification_conf_decode(const char *json, ocpp201_boot_notification_conf_t *out);
void ocpp201_boot_notification_conf_example(ocpp201_boot_notification_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif
