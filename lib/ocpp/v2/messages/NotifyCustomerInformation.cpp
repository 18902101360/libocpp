// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/NotifyCustomerInformation.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * NotifyCustomerInformationRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifyCustomerInformationRequest::get_type() const {
    return "NotifyCustomerInformation";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifyCustomerInformationRequest& k) {
    // the required parts of the message
    j = json{
        {"data", k.data},
        {"seqNo", k.seqNo},
        {"generatedAt", k.generatedAt.to_rfc3339()},
        {"requestId", k.requestId},
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
void from_json(const json& j, NotifyCustomerInformationRequest& k) {
    // the required parts of the message
    k.data = j.at("data");
    k.seqNo = j.at("seqNo");
    k.generatedAt = ocpp::DateTime(std::string(j.at("generatedAt")));
    k.requestId = j.at("requestId");

    // the optional parts of the message
    if (j.contains("tbc")) {
        k.tbc.emplace(j.at("tbc"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifyCustomerInformationRequest \p k to the given output
/// stream \p os
/// \returns an output stream with the NotifyCustomerInformationRequest written to
std::ostream& operator<<(std::ostream& os, const NotifyCustomerInformationRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * NotifyCustomerInformationResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifyCustomerInformationResponse::get_type() const {
    return "NotifyCustomerInformationResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifyCustomerInformationResponse& k) {
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
void from_json(const json& j, NotifyCustomerInformationResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifyCustomerInformationResponse \p k to the given output
/// stream \p os
/// \returns an output stream with the NotifyCustomerInformationResponse written to
std::ostream& operator<<(std::ostream& os, const NotifyCustomerInformationResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
