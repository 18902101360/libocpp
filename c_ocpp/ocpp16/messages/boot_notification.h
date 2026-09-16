/* Generated OCPP message: BootNotification */
#ifndef OCPP16_BOOT_NOTIFICATION_H
#define OCPP16_BOOT_NOTIFICATION_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_BOOT_NOTIFICATION_ACTION "BootNotification"

typedef struct ocpp16_boot_notification_req {
    char chargePointVendor[21];
    char chargePointModel[21];
    int has_firmwareVersion;
    char firmwareVersion[51];
} ocpp16_boot_notification_req_t;

typedef struct ocpp16_boot_notification_conf {
    char status[17];
    char currentTime[33];
    int interval;
} ocpp16_boot_notification_conf_t;

cJSON *ocpp16_boot_notification_req_to_json(const ocpp16_boot_notification_req_t *in);
ocpp_err_t ocpp16_boot_notification_req_from_json(const cJSON *obj, ocpp16_boot_notification_req_t *out);
ocpp_err_t ocpp16_boot_notification_req_encode(const ocpp16_boot_notification_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_boot_notification_req_decode(const char *json, ocpp16_boot_notification_req_t *out);
void ocpp16_boot_notification_req_example(ocpp16_boot_notification_req_t *out);

cJSON *ocpp16_boot_notification_conf_to_json(const ocpp16_boot_notification_conf_t *in);
ocpp_err_t ocpp16_boot_notification_conf_from_json(const cJSON *obj, ocpp16_boot_notification_conf_t *out);
ocpp_err_t ocpp16_boot_notification_conf_encode(const ocpp16_boot_notification_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_boot_notification_conf_decode(const char *json, ocpp16_boot_notification_conf_t *out);
void ocpp16_boot_notification_conf_example(ocpp16_boot_notification_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif
