// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/NotifyReport.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * NotifyReportRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifyReportRequest::get_type() const {
    return "NotifyReport";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifyReportRequest& k) {
    // the required parts of the message
    j = json{
        {"requestId", k.requestId},
        {"generatedAt", k.generatedAt.to_rfc3339()},
        {"seqNo", k.seqNo},
    };
    // the optional parts of the message
    if (k.reportData) {
        j["reportData"] = json::array();
        for (const auto& val : k.reportData.value()) {
            j["reportData"].push_back(val);
        }
    }
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
void from_json(const json& j, NotifyReportRequest& k) {
    // the required parts of the message
    k.requestId = j.at("requestId");
    k.generatedAt = ocpp::DateTime(std::string(j.at("generatedAt")));
    k.seqNo = j.at("seqNo");

    // the optional parts of the message
    if (j.contains("reportData")) {
        const json& arr = j.at("reportData");
        std::vector<ReportData> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.reportData.emplace(vec);
    }
    if (j.contains("tbc")) {
        k.tbc.emplace(j.at("tbc"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifyReportRequest \p k to the given output stream \p os
/// \returns an output stream with the NotifyReportRequest written to
std::ostream& operator<<(std::ostream& os, const NotifyReportRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * NotifyReportResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifyReportResponse::get_type() const {
    return "NotifyReportResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifyReportResponse& k) {
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
void from_json(const json& j, NotifyReportResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifyReportResponse \p k to the given output stream \p os
/// \returns an output stream with the NotifyReportResponse written to
std::ostream& operator<<(std::ostream& os, const NotifyReportResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
