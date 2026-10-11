// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v21/messages/ClearTariffs.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v21 {

/**
 * ClearTariffsRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ClearTariffsRequest::get_type() const {
    return "ClearTariffs";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ClearTariffsRequest& k) {
    // the required parts of the message
    j = json({}, true);
    // the optional parts of the message
    if (k.tariffIds) {
        if (j.empty()) {
            j = json{{"tariffIds", json::array()}};
        } else {
            j["tariffIds"] = json::array();
        }
        for (const auto& val : k.tariffIds.value()) {
            j["tariffIds"].push_back(val);
        }
    }
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
void from_json(const json& j, ClearTariffsRequest& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("tariffIds")) {
        const json& arr = j.at("tariffIds");
        std::vector<CiString<60>> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.tariffIds.emplace(vec);
    }
    if (j.contains("evseId")) {
        k.evseId.emplace(j.at("evseId"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ClearTariffsRequest \p k to the given output stream \p os
/// \returns an output stream with the ClearTariffsRequest written to
std::ostream& operator<<(std::ostream& os, const ClearTariffsRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * ClearTariffsResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string ClearTariffsResponse::get_type() const {
    return "ClearTariffsResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const ClearTariffsResponse& k) {
    // the required parts of the message
    j = json{
        {"clearTariffsResult", k.clearTariffsResult},
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
void from_json(const json& j, ClearTariffsResponse& k) {
    // the required parts of the message
    for (const auto& val : j.at("clearTariffsResult")) {
        k.clearTariffsResult.push_back(val);
    }

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given ClearTariffsResponse \p k to the given output stream \p os
/// \returns an output stream with the ClearTariffsResponse written to
std::ostream& operator<<(std::ostream& os, const ClearTariffsResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v21
} // namespace ocpp
