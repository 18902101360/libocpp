// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest

#include <ocpp/common/utils.hpp>

#include <boost/algorithm/string/predicate.hpp>
#include <cmath>
#include <cstdlib>
#include <mutex>
#include <regex>
#include <sstream>

namespace ocpp {

/**
 * iequals - iequals
 * @lhs: 传入的 lhs
 * @rhs: 传入的 rhs
 *
 * 返回 bool。
 */
bool iequals(const std::string& lhs, const std::string rhs) {
    return boost::algorithm::iequals(lhs, rhs);
}

/**
 * is_integer - is integer
 * @value: 传入的 value
 *
 * 返回 bool。
 */
bool is_integer(const std::string& value) {
    if (value.empty()) {
        return false;
    }

    // Check for + or - in the beginning
    auto value_it = value.begin();
    if (value[0] == '+' or value[0] == '-') {
        value_it += 1;
    }

    return std::all_of(value_it, value.end(), ::isdigit);
}

/**
 * is_positive_integer - is positive integer
 * @value: 传入的 value
 *
 * 返回 std::tuple<bool, int>。
 */
std::tuple<bool, int> is_positive_integer(const std::string& value) {
    bool valid = is_integer(value);
    auto value_int = 0;
    if (valid) {
        value_int = std::stoi(value);
        if (value_int < 0) {
            valid = false;
        }
    }
    return {valid, value_int};
}

/**
 * is_decimal_number - is decimal number
 * @value: 传入的 value
 *
 * 返回 bool。
 */
bool is_decimal_number(const std::string& value) {
    if (value.empty()) {
        return false;
    }

    // Check for + or - in the beginning
    size_t start_pos = 0;
    if (value[0] == '+' || value[0] == '-') {
        start_pos = 1;
    }
    int decimal_point_count = 0;

    for (size_t i = start_pos; i < value.length(); ++i) {
        if (value[i] == '.') {
            // Allow at most one decimal point
            if (++decimal_point_count > 1) {
                return false;
            }
        } else if (std::isdigit(value[i]) == 0) {
            return false;
        }
    }
    return true;
}

/**
 * is_rfc3339_datetime - is rfc3339 datetime
 * @value: 传入的 value
 *
 * 返回 bool。
 */
bool is_rfc3339_datetime(const std::string& value) {
    static std::regex datetime_pattern{};
    static std::once_flag datetime_regex_once;
    std::call_once(datetime_regex_once, []() {
        datetime_pattern =
            std::regex{"\\d{4}-(?:0[1-9]|1[0-2])-(?:0[1-9]|[1-2]\\d|3[0-1])T(?:[0-1]\\d|2[0-3]):[0-5]\\d:["
                       "0-5]\\d(?:\\.\\d{0,3}|)(?:Z|(?:\\+|\\-)(?:\\d{2}):?(?:\\d{2}))"};
    });
    return std::regex_match(value, datetime_pattern);
}

/**
 * split_string - split string
 * @string_to_split: 传入的 string_to_split
 * @c: 传入的 c
 * @trim: 传入的 trim
 *
 * 返回 std::vector<std::string>。
 */
std::vector<std::string> split_string(const std::string& string_to_split, const char c, const bool trim) {
    std::stringstream input(string_to_split);
    std::string temp;
    std::vector<std::string> result;

    while (std::getline(input, temp, c)) {
        if (trim) {
            temp = trim_string(temp);
        }
        result.push_back(temp);
    }

    return result;
}

/**
 * trim_string - trim string
 * @string_to_trim: 传入的 string_to_trim
 *
 * 返回 std::string。
 */
std::string trim_string(const std::string& string_to_trim) {
    const size_t first = string_to_trim.find_first_not_of(' ');
    if (std::string::npos == first) {
        return string_to_trim;
    }
    const size_t last = string_to_trim.find_last_not_of(' ');
    return string_to_trim.substr(first, (last - first + 1));
}

/**
 * is_boolean - is boolean
 * @value: 传入的 value
 *
 * 返回 bool。
 */
bool is_boolean(const std::string& value) {
    return iequals(value, "true") || iequals(value, "false");
}

/**
 * is_equal - is equal
 * @value1: 传入的 value1
 * @value2: 传入的 value2
 * @epsilon: 传入的 epsilon
 *
 * 返回 bool。
 */
bool is_equal(const float& value1, const float& value2, const double& epsilon) {
    return is_equal(static_cast<double>(value1), static_cast<double>(value2), epsilon);
}

/**
 * is_equal - is equal
 * @value1: 传入的 value1
 * @value2: 传入的 value2
 * @epsilon: 传入的 epsilon
 *
 * 返回 bool。
 */
bool is_equal(const double& value1, const double& value2, const double& epsilon) {
    return fabs(value1 - value2) < epsilon;
}

/**
 * convert_to_positive_size_t - convert to positive size t
 * @value: 传入的 value
 *
 * 返回 std::size_t。
 */
std::size_t convert_to_positive_size_t(float value) {
    if (value < 0) {
        return 0;
    }
    return clamp_to<std::size_t>(std::llround(std::ceil(value)));
}

} // namespace ocpp
