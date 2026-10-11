// SPDX-License-Identifier: Apache-2.0
// Copyright Pionix GmbH and Contributors to EVerest

#include <everest/logging.hpp>

#include <algorithm>
#include <openssl/evp.h>
#include <openssl/sha.h>

#include <ocpp/common/utils.hpp>
#include <ocpp/v2/utils.hpp>

namespace ocpp {
namespace v2 {
namespace utils {

/**
 * get_measurands_vec - get measurands vec
 * @measurands_csv: 传入的 measurands_csv
 *
 * 返回 std::vector<MeasurandEnum>。
 */
std::vector<MeasurandEnum> get_measurands_vec(const std::string& measurands_csv) {
    std::vector<MeasurandEnum> measurands;
    const std::vector<std::string> measurands_strings = ocpp::split_string(measurands_csv, ',');

    for (const auto& measurand_string : measurands_strings) {
        try {
            measurands.push_back(conversions::string_to_measurand_enum(measurand_string));
        } catch (const StringToEnumException& e) {
            EVLOG_warning << "Could not convert string: " << measurand_string << " to MeasurandEnum";
        }
    }
    return measurands;
}

/**
 * meter_value_has_any_measurand - meter value has any measurand
 * @_meter_value: 传入的 _meter_value
 * @measurands: 传入的 measurands
 *
 * 返回 bool。
 */
bool meter_value_has_any_measurand(const MeterValue& _meter_value, const std::vector<MeasurandEnum>& measurands) {
    auto compare = [](const SampledValue& a, MeasurandEnum b) { return a.measurand == b; };

    return std::find_first_of(_meter_value.sampledValue.begin(), _meter_value.sampledValue.end(), measurands.begin(),
                              measurands.end(), compare) != _meter_value.sampledValue.end();
}

/**
 * get_meter_value_with_measurands_applied - get meter value with measurands applied
 * @_meter_value: 传入的 _meter_value
 * @measurands: 传入的 measurands
 * @include_signed: 传入的 include_signed
 *
 * 返回 MeterValue。
 */
MeterValue get_meter_value_with_measurands_applied(const MeterValue& _meter_value,
                                                   const std::vector<MeasurandEnum>& measurands, bool include_signed) {
    auto meter_value = _meter_value;
    for (auto it = meter_value.sampledValue.begin(); it != meter_value.sampledValue.end();) {
        auto measurand = it->measurand;
        if (measurand.has_value()) {
            if (std::find(measurands.begin(), measurands.end(), measurand.value()) == measurands.end()) {
                it = meter_value.sampledValue.erase(it);
            } else {
                if (not include_signed) {
                    it->signedMeterValue.reset();
                }
                ++it;
            }
        } else {
            it = meter_value.sampledValue.erase(it);
        }
    }

    return meter_value;
}

/**
 * get_meter_values_with_measurands_applied - get meter values with measurands applied
 * @meter_values: 传入的 meter_values
 * @sampled_tx_ended_measurands: 传入的 sampled_tx_ended_measurands
 * @aligned_tx_ended_measurands: 传入的 aligned_tx_ended_measurands
 * @max_timestamp: 传入的 max_timestamp
 * @include_sampled_signed: 传入的 include_sampled_signed
 * @include_aligned_signed: 传入的 include_aligned_signed
 *
 * 返回 std::vector<MeterValue>。
 */
std::vector<MeterValue> get_meter_values_with_measurands_applied(
    const std::vector<MeterValue>& meter_values, const std::vector<MeasurandEnum>& sampled_tx_ended_measurands,
    const std::vector<MeasurandEnum>& aligned_tx_ended_measurands, ocpp::DateTime max_timestamp,
    bool include_sampled_signed, bool include_aligned_signed) {
    std::vector<MeterValue> meter_values_result;

    for (const auto& meter_value : meter_values) {
        if (meter_value.sampledValue.empty() or meter_value.timestamp > max_timestamp) {
            continue;
        }

        auto context = meter_value.sampledValue.at(0).context;
        if (!context.has_value()) {
            continue;
        }

        switch (context.value()) {
        case ReadingContextEnum::Transaction_Begin:
        case ReadingContextEnum::Interruption_Begin:
        case ReadingContextEnum::Transaction_End:
        case ReadingContextEnum::Interruption_End:
        case ReadingContextEnum::Sample_Periodic:
            if (meter_value_has_any_measurand(meter_value, sampled_tx_ended_measurands)) {
                meter_values_result.push_back(get_meter_value_with_measurands_applied(
                    meter_value, sampled_tx_ended_measurands, include_sampled_signed));
            }
            break;

        case ReadingContextEnum::Sample_Clock:
            if (meter_value_has_any_measurand(meter_value, aligned_tx_ended_measurands)) {
                meter_values_result.push_back(get_meter_value_with_measurands_applied(
                    meter_value, aligned_tx_ended_measurands, include_aligned_signed));
            }
            break;

        case ReadingContextEnum::Other:
        case ReadingContextEnum::Trigger:
            // Nothing to do for these
            break;
        }
    }

    return meter_values_result;
}

/**
 * set_meter_value_reading_context - set meter value reading context
 * @meter_value: 传入的 meter_value
 * @reading_context: 传入的 reading_context
 *
 * 返回 MeterValue。
 */
MeterValue set_meter_value_reading_context(const MeterValue& meter_value, const ReadingContextEnum reading_context) {
    MeterValue return_value = meter_value;
    for (auto& sampled_value : return_value.sampledValue) {
        sampled_value.context = reading_context;
    }

    return return_value;
}

/**
 * sha256 - sha256
 * @str: 传入的 str
 *
 * 返回 std::string。
 */
std::string sha256(const std::string& str) {
    std::array<unsigned char, SHA256_DIGEST_LENGTH> hash;
    EVP_Digest(str.c_str(), str.size(), hash.data(), nullptr, EVP_sha256(), nullptr);
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (const auto& byte : hash) {
        ss << std::setw(2) << (int)byte;
    }
    return ss.str();
}

/**
 * generate_token_hash - generate token hash
 * @token: 传入的 token
 *
 * 返回 std::string。
 */
std::string generate_token_hash(const IdToken& token) {
    return sha256(token.type.get() + token.idToken.get());
}

/**
 * align_timestamp - align timestamp
 * @timestamp: 传入的 timestamp
 * @align_interval: 传入的 align_interval
 *
 * 返回 ocpp::DateTime。
 */
ocpp::DateTime align_timestamp(const DateTime timestamp, std::chrono::seconds align_interval) {
    if (align_interval.count() < 0) {
        EVLOG_warning << "Invalid align interval value";
        return timestamp;
    }

    auto timestamp_sys = date::utc_clock::to_sys(timestamp.to_time_point());
    // get the current midnight
    auto midnight = std::chrono::floor<date::days>(timestamp_sys);
    auto seconds_since_midnight = std::chrono::duration_cast<std::chrono::seconds>(timestamp_sys - midnight);
    auto rounded_seconds = ((seconds_since_midnight + align_interval / 2) / align_interval) * align_interval;
    auto rounded_time = ocpp::DateTime(date::utc_clock::from_sys(midnight + rounded_seconds));

    // Output the original and rounded timestamps
    EVLOG_debug << "Original Timestamp: " << timestamp.to_rfc3339() << std::endl;
    EVLOG_debug << "Interval: " << align_interval.count() << std::endl;
    EVLOG_debug << "Rounded Timestamp: " << rounded_time;

    return rounded_time;
}

/**
 * get_total_power_active_import - get total power active import
 * @meter_value: 传入的 meter_value
 *
 * 返回 std::optional<float>。
 */
std::optional<float> get_total_power_active_import(const MeterValue& meter_value) {
    for (const auto& sampled_value : meter_value.sampledValue) {
        if (sampled_value.measurand == MeasurandEnum::Power_Active_Import and !sampled_value.phase.has_value()) {
            return sampled_value.value;
        }
    }
    return std::nullopt;
}

/**
 * is_critical - is critical
 * @security_event: 传入的 security_event
 *
 * 返回 bool。
 */
bool is_critical(const std::string& security_event) {
    if (security_event == ocpp::security_events::FIRMWARE_UPDATED) {
        return true;
    }
    if (security_event == ocpp::security_events::SETTINGSYSTEMTIME) {
        return true;
    }
    if (security_event == ocpp::security_events::STARTUP_OF_THE_DEVICE) {
        return true;
    }
    if (security_event == ocpp::security_events::RESET_OR_REBOOT) {
        return true;
    }
    if (security_event == ocpp::security_events::SECURITYLOGWASCLEARED) {
        return true;
    }
    if (security_event == ocpp::security_events::MEMORYEXHAUSTION) {
        return true;
    }
    if (security_event == ocpp::security_events::TAMPERDETECTIONACTIVATED) {
        return true;
    }
    if (security_event == ocpp::security_events::INVALIDFIRMWARESIGNATURE) {
        return true;
    }
    if (security_event == ocpp::security_events::INVALIDFIRMWARESIGNINGCERTIFICATE) {
        return true;
    }
    if (security_event == ocpp::security_events::INVALIDCSMSCERTIFICATE) {
        return true;
    }
    if (security_event == ocpp::security_events::INVALIDCHARGINGSTATIONCERTIFICATE) {
        return true;
    }
    if (security_event == ocpp::security_events::INVALIDTLSVERSION) {
        return true;
    }
    if (security_event == ocpp::security_events::INVALIDTLSCIPHERSUITE) {
        return true;
    }
    if (security_event == ocpp::security_events::MAINTENANCELOGINACCEPTED) {
        return true;
    }
    if (security_event == ocpp::security_events::MAINTENANCELOGINFAILED) {
        return true;
    }

    return false;
}

/**
 * get_charging_profile_purposes - get charging profile purposes
 * @csl: 传入的 csl
 *
 * 返回 std::vector<ChargingProfilePurposeEnum>。
 */
std::vector<ChargingProfilePurposeEnum> get_charging_profile_purposes(const std::string& csl) {
    std::vector<ChargingProfilePurposeEnum> purposes;
    const auto purposes_vec = split_string(csl, ',');

    for (const auto& purpose : purposes_vec) {
        try {
            purposes.push_back(conversions::string_to_charging_profile_purpose_enum(purpose));
        } catch (std::out_of_range& e) {
            EVLOG_warning << "Error while converting charging profile purpose to ignore: " << purpose;
        }
    }
    return purposes;
}

/**
 * get_purposes_to_ignore - get purposes to ignore
 * @csl: 传入的 csl
 * @is_offline: 传入的 is_offline
 *
 * 返回 std::vector<ChargingProfilePurposeEnum>。
 */
std::vector<ChargingProfilePurposeEnum> get_purposes_to_ignore(const std::string& csl, const bool is_offline) {
    if (not is_offline or csl.empty()) {
        return {};
    }

    return get_charging_profile_purposes(csl);
}

/**
 * get_ocpp_protocol_versions - get ocpp protocol versions
 * @csl: 传入的 csl
 *
 * 返回 std::vector<OcppProtocolVersion>。
 */
std::vector<OcppProtocolVersion> get_ocpp_protocol_versions(const std::string& csl) {
    if (csl.empty()) {
        return {};
    }

    std::vector<OcppProtocolVersion> ocpp_versions;
    const auto ocpp_versions_str = ocpp::split_string(csl, ',');
    for (const auto& ocpp_version_str : ocpp_versions_str) {
        try {
            ocpp_versions.push_back(ocpp::conversions::string_to_ocpp_protocol_version(ocpp_version_str));
        } catch (std::out_of_range& e) {
            EVLOG_warning << "Error while converting ocpp protocol version: " << ocpp_version_str;
        }
    }
    return ocpp_versions;
}

} // namespace utils
} // namespace v2
} // namespace ocpp
