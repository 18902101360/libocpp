// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/messages/GetConfiguration.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v16 {

/**
 * GetConfigurationRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetConfigurationRequest::get_type() const {
    return "GetConfiguration";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetConfigurationRequest& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    if (k.key) {
        if (j.empty()) {
            j = json{{"key", json::array()}};
        } else {
            j["key"] = json::array();
        }
        for (const auto& val : k.key.value()) {
            j["key"].push_back(val);
        }
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, GetConfigurationRequest& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("key")) {
        const json& arr = j.at("key");
        std::vector<CiString<50>> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.key.emplace(vec);
    }
}

/// \brief Writes the string representation of the given GetConfigurationRequest \p k to the given output stream \p os
/// \returns an output stream with the GetConfigurationRequest written to
std::ostream& operator<<(std::ostream& os, const GetConfigurationRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * GetConfigurationResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetConfigurationResponse::get_type() const {
    return "GetConfigurationResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetConfigurationResponse& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    if (k.configurationKey) {
        if (j.empty()) {
            j = json{{"configurationKey", json::array()}};
        } else {
            j["configurationKey"] = json::array();
        }
        for (const auto& val : k.configurationKey.value()) {
            j["configurationKey"].push_back(val);
        }
    }
    if (k.unknownKey) {
        if (j.empty()) {
            j = json{{"unknownKey", json::array()}};
        } else {
            j["unknownKey"] = json::array();
        }
        for (const auto& val : k.unknownKey.value()) {
            j["unknownKey"].push_back(val);
        }
    }
}

/**
 * from_json - 从 JSON 填回 C++ 对象。缺必填字段时 nlohmann::json 会抛异常。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void from_json(const json& j, GetConfigurationResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("configurationKey")) {
        const json& arr = j.at("configurationKey");
        std::vector<KeyValue> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.configurationKey.emplace(vec);
    }
    if (j.contains("unknownKey")) {
        const json& arr = j.at("unknownKey");
        std::vector<CiString<50>> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.unknownKey.emplace(vec);
    }
}

/// \brief Writes the string representation of the given GetConfigurationResponse \p k to the given output stream \p os
/// \returns an output stream with the GetConfigurationResponse written to
std::ostream& operator<<(std::ostream& os, const GetConfigurationResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v16
} // namespace ocpp
