// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v21/messages/GetPeriodicEventStream.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v21 {

/**
 * GetPeriodicEventStreamRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetPeriodicEventStreamRequest::get_type() const {
    return "GetPeriodicEventStream";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetPeriodicEventStreamRequest& k) {
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
void from_json(const json& j, GetPeriodicEventStreamRequest& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetPeriodicEventStreamRequest \p k to the given output stream
/// \p os
/// \returns an output stream with the GetPeriodicEventStreamRequest written to
std::ostream& operator<<(std::ostream& os, const GetPeriodicEventStreamRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * GetPeriodicEventStreamResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetPeriodicEventStreamResponse::get_type() const {
    return "GetPeriodicEventStreamResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetPeriodicEventStreamResponse& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    if (k.constantStreamData) {
        if (j.empty()) {
            j = json{{"constantStreamData", json::array()}};
        } else {
            j["constantStreamData"] = json::array();
        }
        for (const auto& val : k.constantStreamData.value()) {
            j["constantStreamData"].push_back(val);
        }
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
void from_json(const json& j, GetPeriodicEventStreamResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("constantStreamData")) {
        const json& arr = j.at("constantStreamData");
        std::vector<ConstantStreamData> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.constantStreamData.emplace(vec);
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetPeriodicEventStreamResponse \p k to the given output stream
/// \p os
/// \returns an output stream with the GetPeriodicEventStreamResponse written to
std::ostream& operator<<(std::ostream& os, const GetPeriodicEventStreamResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v21
} // namespace ocpp
