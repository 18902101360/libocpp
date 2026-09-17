#ifndef OCPP201_UPDATE_FIRMWARE_H
#define OCPP201_UPDATE_FIRMWARE_H
#include "ocpp201_types.h"
#include "ocpp_err.h"
#include "ocpp_port.h"
#include "ocpp_json.h"
#ifdef __cplusplus
extern "C" {
#endif
#define OCPP201_UPDATE_FIRMWARE_ACTION "UpdateFirmware"
typedef struct ocpp201_update_firmware_req {
    int requestId;
    ocpp201_firmware_t firmware;
} ocpp201_update_firmware_req_t;
typedef struct ocpp201_update_firmware_conf {
    char status[17];
} ocpp201_update_firmware_conf_t;
cJSON *ocpp201_update_firmware_req_to_json(const ocpp201_update_firmware_req_t *in);
ocpp_err_t ocpp201_update_firmware_req_from_json(const cJSON *obj, ocpp201_update_firmware_req_t *out);
ocpp_err_t ocpp201_update_firmware_req_encode(const ocpp201_update_firmware_req_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_update_firmware_req_decode(const char *json, ocpp201_update_firmware_req_t *out);
void ocpp201_update_firmware_req_example(ocpp201_update_firmware_req_t *out);
cJSON *ocpp201_update_firmware_conf_to_json(const ocpp201_update_firmware_conf_t *in);
ocpp_err_t ocpp201_update_firmware_conf_from_json(const cJSON *obj, ocpp201_update_firmware_conf_t *out);
ocpp_err_t ocpp201_update_firmware_conf_encode(const ocpp201_update_firmware_conf_t *in, char *buf, size_t buflen);
ocpp_err_t ocpp201_update_firmware_conf_decode(const char *json, ocpp201_update_firmware_conf_t *out);
void ocpp201_update_firmware_conf_example(ocpp201_update_firmware_conf_t *out);
#ifdef __cplusplus
}
#endif
#endif
