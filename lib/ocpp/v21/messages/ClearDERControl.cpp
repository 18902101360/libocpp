// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v21/messages/ClearDERControl.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v21 {

/**
 * ClearDERControlRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ClearDERControlRequest::get_type() const {
    return "ClearDERControl";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ClearDERControlRequest& k) {
    // the required parts of the message
    j = json{
        {"isDefault", k.isDefault},
    };
    // the optional parts of the message
    if (k.controlType) {
        j["controlType"] = ocpp::v2::conversions::dercontrol_enum_to_string(k.controlType.value());
    }
    if (k.controlId) {
        j["controlId"] = k.controlId.value();
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
void from_json(const json& j, ClearDERControlRequest& k) {
    // the required parts of the message
    k.isDefault = j.at("isDefault");

    // the optional parts of the message
    if (j.contains("controlType")) {
        k.controlType.emplace(ocpp::v2::conversions::string_to_dercontrol_enum(j.at("controlType")));
    }
    if (j.contains("controlId")) {
        k.controlId.emplace(j.at("controlId"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ClearDERControlRequest \p k to the given output stream \p os
/// \returns an output stream with the ClearDERControlRequest written to
std::ostream& operator<<(std::ostream& os, const ClearDERControlRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * ClearDERControlResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ClearDERControlResponse::get_type() const {
    return "ClearDERControlResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ClearDERControlResponse& k) {
    // the required parts of the message
    j = json{
        {"status", ocpp::v2::conversions::dercontrol_status_enum_to_string(k.status)},
    };
    // the optional parts of the message
    if (k.statusInfo) {
        j["statusInfo"] = k.statusInfo.value();
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
void from_json(const json& j, ClearDERControlResponse& k) {
    // the required parts of the message
    k.status = ocpp::v2::conversions::string_to_dercontrol_status_enum(j.at("status"));

    // the optional parts of the message
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ClearDERControlResponse \p k to the given output stream \p os
/// \returns an output stream with the ClearDERControlResponse written to
std::ostream& operator<<(std::ostream& os, const ClearDERControlResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v21
} // namespace ocpp
