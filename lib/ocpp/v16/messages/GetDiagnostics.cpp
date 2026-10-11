// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/GetDiagnostics.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * GetDiagnosticsRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetDiagnosticsRequest::get_type() const {
    return "GetDiagnostics";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetDiagnosticsRequest& k) {
    // the required parts of the message
    j = json{
        {"location", k.location},
    };
    // the optional parts of the message
    if (k.retries) {
        j["retries"] = k.retries.value();
    }
    if (k.retryInterval) {
        j["retryInterval"] = k.retryInterval.value();
    }
    if (k.startTime) {
        j["startTime"] = k.startTime.value().to_rfc3339();
    }
    if (k.stopTime) {
        j["stopTime"] = k.stopTime.value().to_rfc3339();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, GetDiagnosticsRequest& k) {
    // the required parts of the message
    k.location = j.at("location");

    // the optional parts of the message
    if (j.contains("retries")) {
        k.retries.emplace(j.at("retries"));
    }
    if (j.contains("retryInterval")) {
        k.retryInterval.emplace(j.at("retryInterval"));
    }
    if (j.contains("startTime")) {
        k.startTime.emplace(ocpp::DateTime(std::string(j.at("startTime"))));
    }
    if (j.contains("stopTime")) {
        k.stopTime.emplace(ocpp::DateTime(std::string(j.at("stopTime"))));
    }
}

/// \brief Writes the string representation of the given GetDiagnosticsRequest \p k to the given output stream \p os
/// \returns an output stream with the GetDiagnosticsRequest written to
std::ostream& operator<<(std::ostream& os, const GetDiagnosticsRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * GetDiagnosticsResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetDiagnosticsResponse::get_type() const {
    return "GetDiagnosticsResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetDiagnosticsResponse& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    if (k.fileName) {
        j["fileName"] = k.fileName.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, GetDiagnosticsResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("fileName")) {
        k.fileName.emplace(j.at("fileName"));
    }
}

/// \brief Writes the string representation of the given GetDiagnosticsResponse \p k to the given output stream \p os
/// \returns an output stream with the GetDiagnosticsResponse written to
std::ostream& operator<<(std::ostream& os, const GetDiagnosticsResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp
