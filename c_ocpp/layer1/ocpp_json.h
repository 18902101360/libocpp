/* SPDX-License-Identifier: Apache-2.0 */
#ifndef OCPP_JSON_H
#define OCPP_JSON_H

#include "cJSON.h"
#include "ocpp_err.h"

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void ocpp_str_copy(char *dst, size_t dst_size, const char *src);

ocpp_err_t ocpp_json_dump(const cJSON *obj, char *buf, size_t buflen);

int ocpp_json_get_str(const cJSON *obj, const char *key, char *dst, size_t dst_size, int required);
int ocpp_json_get_int(const cJSON *obj, const char *key, int *out, int required);
int ocpp_json_get_bool(const cJSON *obj, const char *key, int *out, int required);
int ocpp_json_get_double(const cJSON *obj, const char *key, double *out, int required);
cJSON *ocpp_json_get_obj(const cJSON *obj, const char *key, int required);
cJSON *ocpp_json_get_arr(const cJSON *obj, const char *key, int required);

int ocpp_json_add_str(cJSON *obj, const char *key, const char *value);
int ocpp_json_add_int(cJSON *obj, const char *key, int value);
int ocpp_json_add_bool(cJSON *obj, const char *key, int value);
int ocpp_json_add_double(cJSON *obj, const char *key, double value);

#ifdef __cplusplus
}
#endif

#endif
