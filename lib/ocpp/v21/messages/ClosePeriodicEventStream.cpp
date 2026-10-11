// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v21/messages/ClosePeriodicEventStream.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v21 {

/**
 * ClosePeriodicEventStreamRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ClosePeriodicEventStreamRequest::get_type() const {
    return "ClosePeriodicEventStream";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ClosePeriodicEventStreamRequest& k) {
    // the required parts of the message
    j = json{
        {"id", k.id},
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
void from_json(const json& j, ClosePeriodicEventStreamRequest& k) {
    // the required parts of the message
    k.id = j.at("id");

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ClosePeriodicEventStreamRequest \p k to the given output stream
/// \p os
/// \returns an output stream with the ClosePeriodicEventStreamRequest written to
std::ostream& operator<<(std::ostream& os, const ClosePeriodicEventStreamRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * ClosePeriodicEventStreamResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ClosePeriodicEventStreamResponse::get_type() const {
    return "ClosePeriodicEventStreamResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ClosePeriodicEventStreamResponse& k) {
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
void from_json(const json& j, ClosePeriodicEventStreamResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ClosePeriodicEventStreamResponse \p k to the given output
/// stream \p os
/// \returns an output stream with the ClosePeriodicEventStreamResponse written to
std::ostream& operator<<(std::ostream& os, const ClosePeriodicEventStreamResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v21
} // namespace ocpp
