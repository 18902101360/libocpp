#ifndef OCPP201_NOTIFY_EVENT_H
#define OCPP201_NOTIFY_EVENT_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_NOTIFY_EVENT_ACTION "NotifyEvent"
typedef struct ocpp201_notify_event_req {
    char generatedAt[33];
    int seqNo;
    int eventData_count;
    ocpp201_event_data_t eventData[4];
} ocpp201_notify_event_req_t;
typedef struct ocpp201_notify_event_conf {
    int unused;
} ocpp201_notify_event_conf_t;
cJSON *ocpp201_notify_event_req_to_json(const ocpp201_notify_event_req_t *in);
ocpp_err_t ocpp201_notify_event_req_from_json(const cJSON *obj, ocpp201_notify_event_req_t *out);
ocpp_err_t ocpp201_notify_event_req_encode(const ocpp201_notify_event_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_notify_event_req_decode(const char *json, ocpp201_notify_event_req_t *out);
void ocpp201_notify_event_req_example(ocpp201_notify_event_req_t *out);
cJSON *ocpp201_notify_event_conf_to_json(const ocpp201_notify_event_conf_t *in);
ocpp_err_t ocpp201_notify_event_conf_from_json(const cJSON *obj, ocpp201_notify_event_conf_t *out);
ocpp_err_t ocpp201_notify_event_conf_encode(const ocpp201_notify_event_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_notify_event_conf_decode(const char *json, ocpp201_notify_event_conf_t *out);
void ocpp201_notify_event_conf_example(ocpp201_notify_event_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif
