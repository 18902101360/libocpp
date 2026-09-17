/* Generated OCPP message: TriggerMessage */
#ifndef OCPP16_TRIGGER_MESSAGE_H
#define OCPP16_TRIGGER_MESSAGE_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_TRIGGER_MESSAGE_ACTION "TriggerMessage"

typedef struct ocpp16_trigger_message_req {
    char requestedMessage[33];
    int has_connectorId;
    int connectorId;
} ocpp16_trigger_message_req_t;

typedef struct ocpp16_trigger_message_conf {
    char status[17];
} ocpp16_trigger_message_conf_t;

cJSON *ocpp16_trigger_message_req_to_json(const ocpp16_trigger_message_req_t *in);
ocpp_err_t ocpp16_trigger_message_req_from_json(const cJSON *obj, ocpp16_trigger_message_req_t *out);
ocpp_err_t ocpp16_trigger_message_req_encode(const ocpp16_trigger_message_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_trigger_message_req_decode(const char *json, ocpp16_trigger_message_req_t *out);
void ocpp16_trigger_message_req_example(ocpp16_trigger_message_req_t *out);

cJSON *ocpp16_trigger_message_conf_to_json(const ocpp16_trigger_message_conf_t *in);
ocpp_err_t ocpp16_trigger_message_conf_from_json(const cJSON *obj, ocpp16_trigger_message_conf_t *out);
ocpp_err_t ocpp16_trigger_message_conf_encode(const ocpp16_trigger_message_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_trigger_message_conf_decode(const char *json, ocpp16_trigger_message_conf_t *out);
void ocpp16_trigger_message_conf_example(ocpp16_trigger_message_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif
