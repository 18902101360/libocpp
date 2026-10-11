// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/ReportChargingProfiles.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * ReportChargingProfilesRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ReportChargingProfilesRequest::get_type() const {
    return "ReportChargingProfiles";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ReportChargingProfilesRequest& k) {
    // the required parts of the message
    j = json{
        {"requestId", k.requestId},
        {"chargingLimitSource", k.chargingLimitSource},
        {"chargingProfile", k.chargingProfile},
        {"evseId", k.evseId},
    };
    // the optional parts of the message
    if (k.tbc) {
        j["tbc"] = k.tbc.value();
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
void from_json(const json& j, ReportChargingProfilesRequest& k) {
    // the required parts of the message
    k.requestId = j.at("requestId");
    k.chargingLimitSource = j.at("chargingLimitSource");
    for (const auto& val : j.at("chargingProfile")) {
        k.chargingProfile.push_back(val);
    }
    k.evseId = j.at("evseId");

    // the optional parts of the message
    if (j.contains("tbc")) {
        k.tbc.emplace(j.at("tbc"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ReportChargingProfilesRequest \p k to the given output stream
/// \p os
/// \returns an output stream with the ReportChargingProfilesRequest written to
std::ostream& operator<<(std::ostream& os, const ReportChargingProfilesRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * ReportChargingProfilesResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ReportChargingProfilesResponse::get_type() const {
    return "ReportChargingProfilesResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ReportChargingProfilesResponse& k) {
    // the required parts of the message
    j = json({}, true);
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
void from_json(const json& j, ReportChargingProfilesResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ReportChargingProfilesResponse \p k to the given output stream
/// \p os
/// \returns an output stream with the ReportChargingProfilesResponse written to
std::ostream& operator<<(std::ostream& os, const ReportChargingProfilesResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
