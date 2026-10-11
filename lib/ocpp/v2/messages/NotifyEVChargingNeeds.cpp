// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/NotifyEVChargingNeeds.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * NotifyEVChargingNeedsRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifyEVChargingNeedsRequest::get_type() const {
    return "NotifyEVChargingNeeds";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifyEVChargingNeedsRequest& k) {
    // the required parts of the message
    j = json{
        {"evseId", k.evseId},
        {"chargingNeeds", k.chargingNeeds},
    };
    // the optional parts of the message
    if (k.maxScheduleTuples) {
        j["maxScheduleTuples"] = k.maxScheduleTuples.value();
    }
    if (k.timestamp) {
        j["timestamp"] = k.timestamp.value().to_rfc3339();
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
void from_json(const json& j, NotifyEVChargingNeedsRequest& k) {
    // the required parts of the message
    k.evseId = j.at("evseId");
    k.chargingNeeds = j.at("chargingNeeds");

    // the optional parts of the message
    if (j.contains("maxScheduleTuples")) {
        k.maxScheduleTuples.emplace(j.at("maxScheduleTuples"));
    }
    if (j.contains("timestamp")) {
        k.timestamp.emplace(ocpp::DateTime(std::string(j.at("timestamp"))));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifyEVChargingNeedsRequest \p k to the given output stream \p
/// os
/// \returns an output stream with the NotifyEVChargingNeedsRequest written to
std::ostream& operator<<(std::ostream& os, const NotifyEVChargingNeedsRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * NotifyEVChargingNeedsResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifyEVChargingNeedsResponse::get_type() const {
    return "NotifyEVChargingNeedsResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifyEVChargingNeedsResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::notify_evcharging_needs_status_enum_to_string(k.status)},
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
void from_json(const json& j, NotifyEVChargingNeedsResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_notify_evcharging_needs_status_enum(j.at("status"));

    // the optional parts of the message
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifyEVChargingNeedsResponse \p k to the given output stream
/// \p os
/// \returns an output stream with the NotifyEVChargingNeedsResponse written to
std::ostream& operator<<(std::ostream& os, const NotifyEVChargingNeedsResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
