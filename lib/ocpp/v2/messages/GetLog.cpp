// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/GetLog.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * GetLogRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetLogRequest::get_type() const {
    return "GetLog";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetLogRequest& k) {
    // the required parts of the message
    j = json{
        {"log", k.log},
        {"logType", conversions::log_enum_to_string(k.logType)},
        {"requestId", k.requestId},
    };
    // the optional parts of the message
    if (k.retries) {
        j["retries"] = k.retries.value();
    }
    if (k.retryInterval) {
        j["retryInterval"] = k.retryInterval.value();
    }
    if (k.customData) {
        j["customData"] = k.customData.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, GetLogRequest& k) {
    // the required parts of the message
    k.log = j.at("log");
    k.logType = conversions::string_to_log_enum(j.at("logType"));
    k.requestId = j.at("requestId");

    // the optional parts of the message
    if (j.contains("retries")) {
        k.retries.emplace(j.at("retries"));
    }
    if (j.contains("retryInterval")) {
        k.retryInterval.emplace(j.at("retryInterval"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetLogRequest \p k to the given output stream \p os
/// \returns an output stream with the GetLogRequest written to
std::ostream& operator<<(std::ostream& os, const GetLogRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * GetLogResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetLogResponse::get_type() const {
    return "GetLogResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetLogResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::log_status_enum_to_string(k.status)},
    };
    // the optional parts of the message
    if (k.statusInfo) {
        j["statusInfo"] = k.statusInfo.value();
    }
    if (k.filename) {
        j["filename"] = k.filename.value();
    }
    if (k.customData) {
        j["customData"] = k.customData.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, GetLogResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_log_status_enum(j.at("status"));

    // the optional parts of the message
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("filename")) {
        k.filename.emplace(j.at("filename"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetLogResponse \p k to the given output stream \p os
/// \returns an output stream with the GetLogResponse written to
std::ostream& operator<<(std::ostream& os, const GetLogResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
