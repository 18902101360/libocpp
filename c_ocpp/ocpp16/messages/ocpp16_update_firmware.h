/* Generated OCPP message: UpdateFirmware */
#ifndef OCPP16_UPDATE_FIRMWARE_H
#define OCPP16_UPDATE_FIRMWARE_H

#include "ocpp16_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OCPP16_UPDATE_FIRMWARE_ACTION "UpdateFirmware"

typedef struct ocpp16_update_firmware_req {
    char location[513];
    char retrieveDate[33];
} ocpp16_update_firmware_req_t;

typedef struct ocpp16_update_firmware_conf {
    int unused;
} ocpp16_update_firmware_conf_t;

cJSON *ocpp16_update_firmware_req_to_json(const ocpp16_update_firmware_req_t *in);
ocpp_err_t ocpp16_update_firmware_req_from_json(const cJSON *obj, ocpp16_update_firmware_req_t *out);
ocpp_err_t ocpp16_update_firmware_req_encode(const ocpp16_update_firmware_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_update_firmware_req_decode(const char *json, ocpp16_update_firmware_req_t *out);
void ocpp16_update_firmware_req_example(ocpp16_update_firmware_req_t *out);

cJSON *ocpp16_update_firmware_conf_to_json(const ocpp16_update_firmware_conf_t *in);
ocpp_err_t ocpp16_update_firmware_conf_from_json(const cJSON *obj, ocpp16_update_firmware_conf_t *out);
ocpp_err_t ocpp16_update_firmware_conf_encode(const ocpp16_update_firmware_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp16_update_firmware_conf_decode(const char *json, ocpp16_update_firmware_conf_t *out);
void ocpp16_update_firmware_conf_example(ocpp16_update_firmware_conf_t *out);

#ifdef __cplusplus
}
#endif

#endif
