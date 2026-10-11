// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/ExtendedTriggerMessage.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * ExtendedTriggerMessageRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ExtendedTriggerMessageRequest::get_type() const {
    return "ExtendedTriggerMessage";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ExtendedTriggerMessageRequest& k) {
    // the required parts of the message
    j = json{
        {"requestedMessage", conversions::message_trigger_enum_type_to_string(k.requestedMessage)},
    };
    // the optional parts of the message
    if (k.connectorId) {
        j["connectorId"] = k.connectorId.value();
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, ExtendedTriggerMessageRequest& k) {
    // the required parts of the message
    k.requestedMessage = conversions::string_to_message_trigger_enum_type(j.at("requestedMessage"));

    // the optional parts of the message
    if (j.contains("connectorId")) {
        k.connectorId.emplace(j.at("connectorId"));
    }
}

/// \brief Writes the string representation of the given ExtendedTriggerMessageRequest \p k to the given output stream
/// \p os
/// \returns an output stream with the ExtendedTriggerMessageRequest written to
std::ostream& operator<<(std::ostream& os, const ExtendedTriggerMessageRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * ExtendedTriggerMessageResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ExtendedTriggerMessageResponse::get_type() const {
    return "ExtendedTriggerMessageResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ExtendedTriggerMessageResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::trigger_message_status_enum_type_to_string(k.status)},
    };
    // the optional parts of the message
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, ExtendedTriggerMessageResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_trigger_message_status_enum_type(j.at("status"));

    // the optional parts of the message
}

/// \brief Writes the string representation of the given ExtendedTriggerMessageResponse \p k to the given output stream
/// \p os
/// \returns an output stream with the ExtendedTriggerMessageResponse written to
std::ostream& operator<<(std::ostream& os, const ExtendedTriggerMessageResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp
