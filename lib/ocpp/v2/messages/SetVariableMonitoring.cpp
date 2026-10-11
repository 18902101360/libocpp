// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/SetVariableMonitoring.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * SetVariableMonitoringRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string SetVariableMonitoringRequest::get_type() const {
    return "SetVariableMonitoring";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const SetVariableMonitoringRequest& k) {
    // the required parts of the message
    j = json{
        {"setMonitoringData", k.setMonitoringData},
    };
    // the optional parts of the message
    if (k.customData) {
        j["customData"] = k.customData.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, SetVariableMonitoringRequest& k) {
    // the required parts of the message
    for (const auto& val : j.at("setMonitoringData")) {
        k.setMonitoringData.push_back(val);
    }

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given SetVariableMonitoringRequest \p k to the given output stream \p
/// os
/// \returns an output stream with the SetVariableMonitoringRequest written to
std::ostream& operator<<(std::ostream& os, const SetVariableMonitoringRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * SetVariableMonitoringResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string SetVariableMonitoringResponse::get_type() const {
    return "SetVariableMonitoringResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const SetVariableMonitoringResponse& k) {
    // the required parts of the message
    j = json{
        {"setMonitoringResult", k.setMonitoringResult},
    };
    // the optional parts of the message
    if (k.customData) {
        j["customData"] = k.customData.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, SetVariableMonitoringResponse& k) {
    // the required parts of the message
    for (const auto& val : j.at("setMonitoringResult")) {
        k.setMonitoringResult.push_back(val);
    }

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given SetVariableMonitoringResponse \p k to the given output stream
/// \p os
/// \returns an output stream with the SetVariableMonitoringResponse written to
std::ostream& operator<<(std::ostream& os, const SetVariableMonitoringResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
