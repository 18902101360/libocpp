// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2024 Pionix GmbH and Contributors to EVerest

#pragma once

#include <ocpp/v2/ocpp_types.hpp>

namespace ocpp {
namespace v2 {

/**
 * operator== - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
inline bool operator==(const EVSE& lhs, const EVSE& rhs) {
    return lhs.id == rhs.id and lhs.connectorId == rhs.connectorId;
};

/**
 * operator< - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
inline bool operator<(const EVSE& lhs, const EVSE& rhs) {
    if (lhs.id != rhs.id) {
        return lhs.id < rhs.id;
    }
    return lhs.connectorId < rhs.connectorId;
}

/**
 * operator== - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
inline bool operator==(const Component& lhs, const Component& rhs) {
    return lhs.name.get() == rhs.name.get() and lhs.instance == rhs.instance and lhs.evse == rhs.evse;
};

/**
 * operator< - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
inline bool operator<(const Component& lhs, const Component& rhs) {
    if (lhs.name != rhs.name) {
        return lhs.name < rhs.name;
    }
    if (lhs.instance != rhs.instance) {
        return lhs.instance < rhs.instance;
    }
    return lhs.evse < rhs.evse;
};

/**
 * operator== - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
inline bool operator==(const Variable& lhs, const Variable& rhs) {
    return lhs.name.get() == rhs.name.get() and lhs.instance == rhs.instance;
};

/**
 * operator< - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
inline bool operator<(const Variable& lhs, const Variable& rhs) {
    if (lhs.name != rhs.name) {
        return lhs.name < rhs.name;
    }
    return lhs.instance < rhs.instance;
};

/**
 * operator== - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
inline bool operator==(const ComponentVariable& lhs, const ComponentVariable& rhs) {
    return lhs.component == rhs.component and lhs.variable == rhs.variable;
}

/**
 * operator< - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
inline bool operator<(const ComponentVariable& lhs, const ComponentVariable& rhs) {
    if (lhs.component == rhs.component) {
        return lhs.variable < rhs.variable;
    }
    return lhs.component < rhs.component;
}

/**
 * operator== - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
inline bool operator==(const SetVariableData& lhs, const SetVariableData& rhs) {
    return lhs.component == rhs.component and lhs.variable == rhs.variable and
           lhs.attributeValue.get() == rhs.attributeValue.get() and lhs.attributeType == rhs.attributeType;
}

/**
 * operator< - 供日志或容器使用的比较、输出运算符。
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
inline bool operator<(const SetVariableData& lhs, const SetVariableData& rhs) {
    if (lhs.component == rhs.component) {
        return lhs.variable < rhs.variable;
    }
    return lhs.component < rhs.component;
}

} // namespace v2
} // namespace ocpp
