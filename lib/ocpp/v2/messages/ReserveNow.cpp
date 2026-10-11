// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/ReserveNow.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * ReserveNowRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ReserveNowRequest::get_type() const {
    return "ReserveNow";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ReserveNowRequest& k) {
    // the required parts of the message
    j = json{
        {"id", k.id},
        {"expiryDateTime", k.expiryDateTime.to_rfc3339()},
        {"idToken", k.idToken},
    };
    // the optional parts of the message
    if (k.connectorType) {
        j["connectorType"] = k.connectorType.value();
    }
    if (k.evseId) {
        j["evseId"] = k.evseId.value();
    }
    if (k.groupIdToken) {
        j["groupIdToken"] = k.groupIdToken.value();
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
void from_json(const json& j, ReserveNowRequest& k) {
    // the required parts of the message
    k.id = j.at("id");
    k.expiryDateTime = ocpp::DateTime(std::string(j.at("expiryDateTime")));
    k.idToken = j.at("idToken");

    // the optional parts of the message
    if (j.contains("connectorType")) {
        k.connectorType.emplace(j.at("connectorType"));
    }
    if (j.contains("evseId")) {
        k.evseId.emplace(j.at("evseId"));
    }
    if (j.contains("groupIdToken")) {
        k.groupIdToken.emplace(j.at("groupIdToken"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ReserveNowRequest \p k to the given output stream \p os
/// \returns an output stream with the ReserveNowRequest written to
std::ostream& operator<<(std::ostream& os, const ReserveNowRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * ReserveNowResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ReserveNowResponse::get_type() const {
    return "ReserveNowResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ReserveNowResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::reserve_now_status_enum_to_string(k.status)},
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
void from_json(const json& j, ReserveNowResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_reserve_now_status_enum(j.at("status"));

    // the optional parts of the message
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ReserveNowResponse \p k to the given output stream \p os
/// \returns an output stream with the ReserveNowResponse written to
std::ostream& operator<<(std::ostream& os, const ReserveNowResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
