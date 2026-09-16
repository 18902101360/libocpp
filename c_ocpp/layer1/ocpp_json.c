/* SPDX-License-Identifier: Apache-2.0 */
#include "ocpp_json.h"

#include <string.h>

void ocpp_str_copy(char *dst, size_t dst_size, const char *src) {
    if (dst == NULL || dst_size == 0) {
        return;
    }
    if (src == NULL) {
        dst[0] = '\0';
        return;
    }
    size_t n = strlen(src);
    if (n >= dst_size) {
        n = dst_size - 1;
    }
    memcpy(dst, src, n);
    dst[n] = '\0';
}

ocpp_err_t ocpp_json_dump(const cJSON *obj, char *buf, size_t buflen) {
    if (obj == NULL || buf == NULL || buflen < 3) {
        return OCPP_ERR_ARG;
    }
    if (!cJSON_PrintPreallocated((cJSON *)obj, buf, (int)buflen, 0)) {
        return OCPP_ERR_OVERFLOW;
    }
    return OCPP_OK;
}

int ocpp_json_get_str(const cJSON *obj, const char *key, char *dst, size_t dst_size, int required) {
    cJSON *it = cJSON_GetObjectItemCaseSensitive((cJSON *)obj, key);
    if (it == NULL) {
        if (dst && dst_size) {
            dst[0] = '\0';
        }
        return required ? -1 : 0;
    }
    if (!cJSON_IsString(it) || it->valuestring == NULL) {
        return -1;
    }
    ocpp_str_copy(dst, dst_size, it->valuestring);
    return 1;
}

int ocpp_json_get_int(const cJSON *obj, const char *key, int *out, int required) {
    cJSON *it = cJSON_GetObjectItemCaseSensitive((cJSON *)obj, key);
    if (it == NULL) {
        return required ? -1 : 0;
    }
    if (!cJSON_IsNumber(it)) {
        return -1;
    }
    if (out) {
        *out = it->valueint;
    }
    return 1;
}

int ocpp_json_get_bool(const cJSON *obj, const char *key, int *out, int required) {
    cJSON *it = cJSON_GetObjectItemCaseSensitive((cJSON *)obj, key);
    if (it == NULL) {
        return required ? -1 : 0;
    }
    if (!cJSON_IsBool(it)) {
        return -1;
    }
    if (out) {
        *out = cJSON_IsTrue(it) ? 1 : 0;
    }
    return 1;
}

int ocpp_json_get_double(const cJSON *obj, const char *key, double *out, int required) {
    cJSON *it = cJSON_GetObjectItemCaseSensitive((cJSON *)obj, key);
    if (it == NULL) {
        return required ? -1 : 0;
    }
    if (!cJSON_IsNumber(it)) {
        return -1;
    }
    if (out) {
        *out = it->valuedouble;
    }
    return 1;
}

cJSON *ocpp_json_get_obj(const cJSON *obj, const char *key, int required) {
    cJSON *it = cJSON_GetObjectItemCaseSensitive((cJSON *)obj, key);
    if (it == NULL) {
        return required ? NULL : NULL;
    }
    if (!cJSON_IsObject(it)) {
        return NULL;
    }
    (void)required;
    return it;
}

cJSON *ocpp_json_get_arr(const cJSON *obj, const char *key, int required) {
    cJSON *it = cJSON_GetObjectItemCaseSensitive((cJSON *)obj, key);
    if (it == NULL) {
        return NULL;
    }
    (void)required;
    return cJSON_IsArray(it) ? it : NULL;
}

int ocpp_json_add_str(cJSON *obj, const char *key, const char *value) {
    if (obj == NULL || key == NULL || value == NULL || value[0] == '\0') {
        return 0;
    }
    return cJSON_AddStringToObject(obj, key, value) ? 1 : -1;
}

int ocpp_json_add_int(cJSON *obj, const char *key, int value) {
    return cJSON_AddNumberToObject(obj, key, value) ? 1 : -1;
}

int ocpp_json_add_bool(cJSON *obj, const char *key, int value) {
    return cJSON_AddBoolToObject(obj, key, value ? 1 : 0) ? 1 : -1;
}

int ocpp_json_add_double(cJSON *obj, const char *key, double value) {
    return cJSON_AddNumberToObject(obj, key, value) ? 1 : -1;
}
