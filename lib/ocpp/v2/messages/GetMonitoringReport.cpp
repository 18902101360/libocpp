// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v2/messages/GetMonitoringReport.hpp>

#include <optional>
#include <ostream>
#include <string>

using json = nlohmann::json;

namespace ocpp {
namespace v2 {

/**
 * GetMonitoringReportRequest::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetMonitoringReportRequest::get_type() const {
    return "GetMonitoringReport";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetMonitoringReportRequest& k) {
    // the required parts of the message
    j = json{
        {"requestId", k.requestId},
    };
    // the optional parts of the message
    if (k.componentVariable) {
        j["componentVariable"] = json::array();
        for (const auto& val : k.componentVariable.value()) {
            j["componentVariable"].push_back(val);
        }
    }
    if (k.monitoringCriteria) {
        j["monitoringCriteria"] = json::array();
        for (const auto& val : k.monitoringCriteria.value()) {
            j["monitoringCriteria"].push_back(conversions::monitoring_criterion_enum_to_string(val));
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
void from_json(const json& j, GetMonitoringReportRequest& k) {
    // the required parts of the message
    k.requestId = j.at("requestId");

    // the optional parts of the message
    if (j.contains("componentVariable")) {
        const json& arr = j.at("componentVariable");
        std::vector<ComponentVariable> vec;
        for (const auto& val : arr) {
            vec.push_back(val);
        }
        k.componentVariable.emplace(vec);
    }
    if (j.contains("monitoringCriteria")) {
        const json& arr = j.at("monitoringCriteria");
        std::vector<MonitoringCriterionEnum> vec;
        for (const auto& val : arr) {
            vec.push_back(conversions::string_to_monitoring_criterion_enum(val));
        }
        k.monitoringCriteria.emplace(vec);
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetMonitoringReportRequest \p k to the given output stream \p
/// os
/// \returns an output stream with the GetMonitoringReportRequest written to
std::ostream& operator<<(std::ostream& os, const GetMonitoringReportRequest& k) {
    os << json(k).dump(4);
    return os;
}

/**
 * GetMonitoringReportResponse::get_type - 返回这条 OCPP 报文的 action 名，分发器靠它识别报文类型。
 *
 * 返回 std::string。
 */
std::string GetMonitoringReportResponse::get_type() const {
    return "GetMonitoringReportResponse";
}

/**
 * to_json - 把 C++ 对象写成 JSON。必填字段总是写出，可选字段只在有值时写出。
 * @j: JSON 对象。写出时作为目标，读入时作为来源
 * @k: 对应的 OCPP 结构体
 */
void to_json(json& j, const GetMonitoringReportResponse& k) {
    // the required parts of the message
    j = json{
        {"status", conversions::generic_device_model_status_enum_to_string(k.status)},
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
void from_json(const json& j, GetMonitoringReportResponse& k) {
    // the required parts of the message
    k.status = conversions::string_to_generic_device_model_status_enum(j.at("status"));

    // the optional parts of the message
    if (j.contains("statusInfo")) {
        k.statusInfo.emplace(j.at("statusInfo"));
    }
    if (j.contains("customData")) {
        k.customData.emplace(j.at("customData"));
    }
}

/// \brief Writes the string representation of the given GetMonitoringReportResponse \p k to the given output stream \p
/// os
/// \returns an output stream with the GetMonitoringReportResponse written to
std::ostream& operator<<(std::ostream& os, const GetMonitoringReportResponse& k) {
    os << json(k).dump(4);
    return os;
}

} // namespace v2
} // namespace ocpp
