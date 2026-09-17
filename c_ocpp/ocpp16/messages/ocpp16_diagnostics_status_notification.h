/* Generated OCPP message: DiagnosticsStatusNotification */
#ifndef OCPP16_DIAGNOSTICS_STATUS_NOTIFICATION_H
#define OCPP16_DIAGNOSTICS_STATUS_NOTIFICATION_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_DIAGNOSTICS_STATUS_NOTIFICATION_ACTION "DiagnosticsStatusNotification"

typedef struct ocpp16_diagnostics_status_notification_req {
    char status[21];
} ocpp16_diagnostics_status_notification_req_t;

typedef struct ocpp16_diagnostics_status_notification_conf {
    int unused;
} ocpp16_diagnostics_status_notification_conf_t;

cJSON *ocpp16_diagnostics_status_notification_req_to_json(const ocpp16_diagnostics_status_notification_req_t *in);
ocpp_err_t ocpp16_diagnostics_status_notification_req_from_json(const cJSON *obj, ocpp16_diagnostics_status_notification_req_t *out);
ocpp_err_t ocpp16_diagnostics_status_notification_req_encode(const ocpp16_diagnostics_status_notification_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_diagnostics_status_notification_req_decode(const char *json, ocpp16_diagnostics_status_notification_req_t *out);
void ocpp16_diagnostics_status_notification_req_example(ocpp16_diagnostics_status_notification_req_t *out);

cJSON *ocpp16_diagnostics_status_notification_conf_to_json(const ocpp16_diagnostics_status_notification_conf_t *in);
ocpp_err_t ocpp16_diagnostics_status_notification_conf_from_json(const cJSON *obj, ocpp16_diagnostics_status_notification_conf_t *out);
ocpp_err_t ocpp16_diagnostics_status_notification_conf_encode(const ocpp16_diagnostics_status_notification_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_diagnostics_status_notification_conf_decode(const char *json, ocpp16_diagnostics_status_notification_conf_t *out);
void ocpp16_diagnostics_status_notification_conf_example(ocpp16_diagnostics_status_notification_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif
