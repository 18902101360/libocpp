#ifndef OCPP201_SECURITY_EVENT_NOTIFICATION_H
#define OCPP201_SECURITY_EVENT_NOTIFICATION_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_SECURITY_EVENT_NOTIFICATION_ACTION "SecurityEventNotification"
typedef struct ocpp201_security_event_notification_req {
    char type[51];
    char timestamp[33];
} ocpp201_security_event_notification_req_t;
typedef struct ocpp201_security_event_notification_conf {
    int unused;
} ocpp201_security_event_notification_conf_t;
cJSON *ocpp201_security_event_notification_req_to_json(const ocpp201_security_event_notification_req_t *in);
ocpp_err_t ocpp201_security_event_notification_req_from_json(const cJSON *obj, ocpp201_security_event_notification_req_t *out);
ocpp_err_t ocpp201_security_event_notification_req_encode(const ocpp201_security_event_notification_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_security_event_notification_req_decode(const char *json, ocpp201_security_event_notification_req_t *out);
void ocpp201_security_event_notification_req_example(ocpp201_security_event_notification_req_t *out);
cJSON *ocpp201_security_event_notification_conf_to_json(const ocpp201_security_event_notification_conf_t *in);
ocpp_err_t ocpp201_security_event_notification_conf_from_json(const cJSON *obj, ocpp201_security_event_notification_conf_t *out);
ocpp_err_t ocpp201_security_event_notification_conf_encode(const ocpp201_security_event_notification_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_security_event_notification_conf_decode(const char *json, ocpp201_security_event_notification_conf_t *out);
void ocpp201_security_event_notification_conf_example(ocpp201_security_event_notification_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif
