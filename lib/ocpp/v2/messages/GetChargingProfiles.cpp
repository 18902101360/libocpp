// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/GetChargingProfiles.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * GetChargingProfilesRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetChargingProfilesRequest::get_type() const {
    return "GetChargingProfiles";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetChargingProfilesRequest& k) {
    // the required parts of the message
    j = json{
        {"requestId", k.requestId},
        {"chargingProfile", k.chargingProfile},
    };
    // the optional parts of the message
    if (k.evseId) {
        j["evseId"] = k.evseId.value();
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
void from_json(const json& j, GetChargingProfilesRequest& k) {
    // the required parts of the message
    k.requestId = j.at("requestId");
    k.chargingProfile = j.at("chargingProfile");

    // the optional parts of the message
    if (j.contains("evseId")) {
        k.evseId.emplace(j.at("evseId"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetChargingProfilesRequest \p k to the given output stream \p
/// os
/// \returns an output stream with the GetChargingProfilesRequest written to
std::ostream& operator<<(std::ostream& os, const GetChargingProfilesRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * GetChargingProfilesResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetChargingProfilesResponse::get_type() const {
    return "GetChargingProfilesResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetChargingProfilesResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::get_charging_profile_status_enum_to_string(k.status)},
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
void from_json(const json& j, GetChargingProfilesResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_get_charging_profile_status_enum(j.at("status"));

    // the optional parts of the message
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetChargingProfilesResponse \p k to the given output stream \p
/// os
/// \returns an output stream with the GetChargingProfilesResponse written to
std::ostream& operator<<(std::ostream& os, const GetChargingProfilesResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
