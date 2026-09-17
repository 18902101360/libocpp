/* Generated OCPP message: SecurityEventNotification */
#ifndef OCPP16_SECURITY_EVENT_NOTIFICATION_H
#define OCPP16_SECURITY_EVENT_NOTIFICATION_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_SECURITY_EVENT_NOTIFICATION_ACTION "SecurityEventNotification"

typedef struct ocpp16_security_event_notification_req {
    char type[51];
    char timestamp[33];
    int has_techInfo;
    char techInfo[256];
} ocpp16_security_event_notification_req_t;

typedef struct ocpp16_security_event_notification_conf {
    int unused;
} ocpp16_security_event_notification_conf_t;

cJSON *ocpp16_security_event_notification_req_to_json(const ocpp16_security_event_notification_req_t *in);
ocpp_err_t ocpp16_security_event_notification_req_from_json(const cJSON *obj, ocpp16_security_event_notification_req_t *out);
ocpp_err_t ocpp16_security_event_notification_req_encode(const ocpp16_security_event_notification_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_security_event_notification_req_decode(const char *json, ocpp16_security_event_notification_req_t *out);
void ocpp16_security_event_notification_req_example(ocpp16_security_event_notification_req_t *out);

cJSON *ocpp16_security_event_notification_conf_to_json(const ocpp16_security_event_notification_conf_t *in);
ocpp_err_t ocpp16_security_event_notification_conf_from_json(const cJSON *obj, ocpp16_security_event_notification_conf_t *out);
ocpp_err_t ocpp16_security_event_notification_conf_encode(const ocpp16_security_event_notification_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_security_event_notification_conf_decode(const char *json, ocpp16_security_event_notification_conf_t *out);
void ocpp16_security_event_notification_conf_example(ocpp16_security_event_notification_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif
