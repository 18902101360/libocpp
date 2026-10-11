// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/SecurityEventNotification.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * SecurityEventNotificationRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string SecurityEventNotificationRequest::get_type() const {
    return "SecurityEventNotification";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const SecurityEventNotificationRequest& k) {
    // the required parts of the message
    j = json{
        {"type", k.type},
        {"timestamp", k.timestamp.to_rfc3339()},
    };
    // the optional parts of the message
    if (k.techInfo) {
        j["techInfo"] = k.techInfo.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, SecurityEventNotificationRequest& k) {
    // the required parts of the message
    k.type = j.at("type");
    k.timestamp = ocpp::DateTime(std::string(j.at("timestamp")));

    // the optional parts of the message
    if (j.contains("techInfo")) {
        k.techInfo.emplace(j.at("techInfo"));
    }
}

/// \brief Writes the string representation of the given SecurityEventNotificationRequest \p k to the given output
/// stream \p os
/// \returns an output stream with the SecurityEventNotificationRequest written to
std::ostream& operator<<(std::ostream& os, const SecurityEventNotificationRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * SecurityEventNotificationResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string SecurityEventNotificationResponse::get_type() const {
    return "SecurityEventNotificationResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const SecurityEventNotificationResponse& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    (void)k; // no elements to unpack, silence unused parameter warning
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, SecurityEventNotificationResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    // no elements to unpack, silence unused parameter warning
    (void)j;
    (void)k;
}

/// \brief Writes the string representation of the given SecurityEventNotificationResponse \p k to the given output
/// stream \p os
/// \returns an output stream with the SecurityEventNotificationResponse written to
std::ostream& operator<<(std::ostream& os, const SecurityEventNotificationResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp
