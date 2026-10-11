// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v21/messages/GetCertificateChainStatus.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v21 {

/**
 * GetCertificateChainStatusRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetCertificateChainStatusRequest::get_type() const {
    return "GetCertificateChainStatus";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetCertificateChainStatusRequest& k) {
    // the required parts of the message
    j = json{
        {"certificateStatusRequests", k.certificateStatusRequests},
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
void from_json(const json& j, GetCertificateChainStatusRequest& k) {
    // the required parts of the message
    for (const auto& val : j.at("certificateStatusRequests")) {
        k.certificateStatusRequests.push_back(val);
    }

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetCertificateChainStatusRequest \p k to the given output
/// stream \p os
/// \returns an output stream with the GetCertificateChainStatusRequest written to
std::ostream& operator<<(std::ostream& os, const GetCertificateChainStatusRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * GetCertificateChainStatusResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetCertificateChainStatusResponse::get_type() const {
    return "GetCertificateChainStatusResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetCertificateChainStatusResponse& k) {
    // the required parts of the message
    j = json{
        {"certificateStatus", k.certificateStatus},
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
void from_json(const json& j, GetCertificateChainStatusResponse& k) {
    // the required parts of the message
    for (const auto& val : j.at("certificateStatus")) {
        k.certificateStatus.push_back(val);
    }

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetCertificateChainStatusResponse \p k to the given output
/// stream \p os
/// \returns an output stream with the GetCertificateChainStatusResponse written to
std::ostream& operator<<(std::ostream& os, const GetCertificateChainStatusResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v21
} // namespace ocpp
