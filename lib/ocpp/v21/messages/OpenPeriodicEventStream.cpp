// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v21/messages/OpenPeriodicEventStream.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v21 {

/**
 * OpenPeriodicEventStreamRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string OpenPeriodicEventStreamRequest::get_type() const {
    return "OpenPeriodicEventStream";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const OpenPeriodicEventStreamRequest& k) {
    // the required parts of the message
    j = json{
        {"constantStreamData", k.constantStreamData},
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
void from_json(const json& j, OpenPeriodicEventStreamRequest& k) {
    // the required parts of the message
    k.constantStreamData = j.at("constantStreamData");

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given OpenPeriodicEventStreamRequest \p k to the given output stream
/// \p os
/// \returns an output stream with the OpenPeriodicEventStreamRequest written to
std::ostream& operator<<(std::ostream& os, const OpenPeriodicEventStreamRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * OpenPeriodicEventStreamResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string OpenPeriodicEventStreamResponse::get_type() const {
    return "OpenPeriodicEventStreamResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const OpenPeriodicEventStreamResponse& k) {
    // the required parts of the message
    j = json{
        {"status", ocpp::v2::conversions::generic_status_enum_to_string(k.status)},
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
void from_json(const json& j, OpenPeriodicEventStreamResponse& k) {
    // the required parts of the message
    k.status = ocpp::v2::conversions::string_to_generic_status_enum(j.at("status"));

    // the optional parts of the message
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given OpenPeriodicEventStreamResponse \p k to the given output stream
/// \p os
/// \returns an output stream with the OpenPeriodicEventStreamResponse written to
std::ostream& operator<<(std::ostream& os, const OpenPeriodicEventStreamResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v21
} // namespace ocpp
