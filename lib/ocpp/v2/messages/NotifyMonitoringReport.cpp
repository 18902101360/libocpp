// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/NotifyMonitoringReport.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * NotifyMonitoringReportRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifyMonitoringReportRequest::get_type() const {
    return "NotifyMonitoringReport";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifyMonitoringReportRequest& k) {
    // the required parts of the message
    j = json{
        {"requestId", k.requestId},
        {"seqNo", k.seqNo},
        {"generatedAt", k.generatedAt.to_rfc3339()},
    };
    // the optional parts of the message
    if (k.monitor) {
        j["monitor"] = json::array();
        for (const auto& val : k.monitor.value()) {
            j["monitor"].push_back(val);
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
void from_json(const json& j, NotifyMonitoringReportRequest& k) {
    // the required parts of the message
    k.requestId = j.at("requestId");
    k.seqNo = j.at("seqNo");
    k.generatedAt = ocpp::DateTime(std::string(j.at("generatedAt")));

    // the optional parts of the message
    if (j.contains("monitor")) {
        const json& arr = j.at("monitor");
        std::vector<MonitoringData> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.monitor.emplace(vec);
    }
    if (j.contains("tbc")) {
        k.tbc.emplace(j.at("tbc"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifyMonitoringReportRequest \p k to the given output stream
/// \p os
/// \returns an output stream with the NotifyMonitoringReportRequest written to
std::ostream& operator<<(std::ostream& os, const NotifyMonitoringReportRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * NotifyMonitoringReportResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string NotifyMonitoringReportResponse::get_type() const {
    return "NotifyMonitoringReportResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const NotifyMonitoringReportResponse& k) {
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
void from_json(const json& j, NotifyMonitoringReportResponse& k) {
    // the required parts of the message

    // the optional parts of the message
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given NotifyMonitoringReportResponse \p k to the given output stream
/// \p os
/// \returns an output stream with the NotifyMonitoringReportResponse written to
std::ostream& operator<<(std::ostream& os, const NotifyMonitoringReportResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
