// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/GetCompositeSchedule.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * GetCompositeScheduleRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetCompositeScheduleRequest::get_type() const {
    return "GetCompositeSchedule";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetCompositeScheduleRequest& k) {
    // the required parts of the message
    j = json{
        {"duration", k.duration},
        {"evseId", k.evseId},
    };
    // the optional parts of the message
    if (k.chargingRateUnit) {
        j["chargingRateUnit"] = conversions::charging_rate_unit_enum_to_string(k.chargingRateUnit.value());
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
void from_json(const json& j, GetCompositeScheduleRequest& k) {
    // the required parts of the message
    k.duration = j.at("duration");
    k.evseId = j.at("evseId");

    // the optional parts of the message
    if (j.contains("chargingRateUnit")) {
        k.chargingRateUnit.emplace(conversions::string_to_charging_rate_unit_enum(j.at("chargingRateUnit")));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetCompositeScheduleRequest \p k to the given output stream \p
/// os
/// \returns an output stream with the GetCompositeScheduleRequest written to
std::ostream& operator<<(std::ostream& os, const GetCompositeScheduleRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * GetCompositeScheduleResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetCompositeScheduleResponse::get_type() const {
    return "GetCompositeScheduleResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetCompositeScheduleResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::generic_status_enum_to_string(k.status)},
    };
    // the optional parts of the message
    if (k.statusInfo) {
        j["statusInfo"] = k.statusInfo.value();
    }
    if (k.schedule) {
        j["schedule"] = k.schedule.value();
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
void from_json(const json& j, GetCompositeScheduleResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_generic_status_enum(j.at("status"));

    // the optional parts of the message
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("schedule")) {
        k.schedule.emplace(j.at("schedule"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetCompositeScheduleResponse \p k to the given output stream \p
/// os
/// \returns an output stream with the GetCompositeScheduleResponse written to
std::ostream& operator<<(std::ostream& os, const GetCompositeScheduleResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
