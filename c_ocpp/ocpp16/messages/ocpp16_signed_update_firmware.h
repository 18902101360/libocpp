/* Generated OCPP message: SignedUpdateFirmware */
#ifndef OCPP16_SIGNED_UPDATE_FIRMWARE_H
#define OCPP16_SIGNED_UPDATE_FIRMWARE_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_SIGNED_UPDATE_FIRMWARE_ACTION "SignedUpdateFirmware"

typedef struct ocpp16_signed_update_firmware_req {
    int requestId;
    ocpp16_firmware_signed_t firmware;
} ocpp16_signed_update_firmware_req_t;

typedef struct ocpp16_signed_update_firmware_conf {
    char status[17];
} ocpp16_signed_update_firmware_conf_t;

cJSON *ocpp16_signed_update_firmware_req_to_json(const ocpp16_signed_update_firmware_req_t *in);
ocpp_err_t ocpp16_signed_update_firmware_req_from_json(const cJSON *obj, ocpp16_signed_update_firmware_req_t *out);
ocpp_err_t ocpp16_signed_update_firmware_req_encode(const ocpp16_signed_update_firmware_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_signed_update_firmware_req_decode(const char *json, ocpp16_signed_update_firmware_req_t *out);
void ocpp16_signed_update_firmware_req_example(ocpp16_signed_update_firmware_req_t *out);

cJSON *ocpp16_signed_update_firmware_conf_to_json(const ocpp16_signed_update_firmware_conf_t *in);
ocpp_err_t ocpp16_signed_update_firmware_conf_from_json(const cJSON *obj, ocpp16_signed_update_firmware_conf_t *out);
ocpp_err_t ocpp16_signed_update_firmware_conf_encode(const ocpp16_signed_update_firmware_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_signed_update_firmware_conf_decode(const char *json, ocpp16_signed_update_firmware_conf_t *out);
void ocpp16_signed_update_firmware_conf_example(ocpp16_signed_update_firmware_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif
