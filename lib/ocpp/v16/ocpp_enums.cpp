// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2025 Pionix GmbH and Contributors to EVerest
// This code is generated using the generator in 'src/code_generator/common`, please do not edit manually

#include <ocpp/v16/ocpp_enums.hpp>

#include <string>

#include <ocpp/common/types.hpp>

namespace ocpp {
namespace v16 {

// from: AuthorizeResponse
namespace conversions {
/**
 * authorization_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string authorization_status_to_string(AuthorizationStatus e) {
    switch (e) {
    case AuthorizationStatus::Accepted:
        return "Accepted";
    case AuthorizationStatus::Blocked:
        return "Blocked";
    case AuthorizationStatus::Expired:
        return "Expired";
    case AuthorizationStatus::Invalid:
        return "Invalid";
    case AuthorizationStatus::ConcurrentTx:
        return "ConcurrentTx";
    }

    throw EnumToStringException{e, "AuthorizationStatus"};
}

/**
 * string_to_authorization_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 AuthorizationStatus。
 */
AuthorizationStatus string_to_authorization_status(const std::string& s) {
    if (s == "Accepted") {
        return AuthorizationStatus::Accepted;
    }
    if (s == "Blocked") {
        return AuthorizationStatus::Blocked;
    }
    if (s == "Expired") {
        return AuthorizationStatus::Expired;
    }
    if (s == "Invalid") {
        return AuthorizationStatus::Invalid;
    }
    if (s == "ConcurrentTx") {
        return AuthorizationStatus::ConcurrentTx;
    }

    throw StringToEnumException{s, "AuthorizationStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @authorization_status: 传入的 authorization_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const AuthorizationStatus& authorization_status) {
    os << conversions::authorization_status_to_string(authorization_status);
    return os;
}

// from: BootNotificationResponse
namespace conversions {
/**
 * registration_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string registration_status_to_string(RegistrationStatus e) {
    switch (e) {
    case RegistrationStatus::Accepted:
        return "Accepted";
    case RegistrationStatus::Pending:
        return "Pending";
    case RegistrationStatus::Rejected:
        return "Rejected";
    }

    throw EnumToStringException{e, "RegistrationStatus"};
}

/**
 * string_to_registration_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 RegistrationStatus。
 */
RegistrationStatus string_to_registration_status(const std::string& s) {
    if (s == "Accepted") {
        return RegistrationStatus::Accepted;
    }
    if (s == "Pending") {
        return RegistrationStatus::Pending;
    }
    if (s == "Rejected") {
        return RegistrationStatus::Rejected;
    }

    throw StringToEnumException{s, "RegistrationStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @registration_status: 传入的 registration_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const RegistrationStatus& registration_status) {
    os << conversions::registration_status_to_string(registration_status);
    return os;
}

// from: CancelReservationResponse
namespace conversions {
/**
 * cancel_reservation_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string cancel_reservation_status_to_string(CancelReservationStatus e) {
    switch (e) {
    case CancelReservationStatus::Accepted:
        return "Accepted";
    case CancelReservationStatus::Rejected:
        return "Rejected";
    }

    throw EnumToStringException{e, "CancelReservationStatus"};
}

/**
 * string_to_cancel_reservation_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 CancelReservationStatus。
 */
CancelReservationStatus string_to_cancel_reservation_status(const std::string& s) {
    if (s == "Accepted") {
        return CancelReservationStatus::Accepted;
    }
    if (s == "Rejected") {
        return CancelReservationStatus::Rejected;
    }

    throw StringToEnumException{s, "CancelReservationStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @cancel_reservation_status: 传入的 cancel_reservation_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const CancelReservationStatus& cancel_reservation_status) {
    os << conversions::cancel_reservation_status_to_string(cancel_reservation_status);
    return os;
}

// from: CertificateSignedResponse
namespace conversions {
/**
 * certificate_signed_status_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string certificate_signed_status_enum_type_to_string(CertificateSignedStatusEnumType e) {
    switch (e) {
    case CertificateSignedStatusEnumType::Accepted:
        return "Accepted";
    case CertificateSignedStatusEnumType::Rejected:
        return "Rejected";
    }

    throw EnumToStringException{e, "CertificateSignedStatusEnumType"};
}

/**
 * string_to_certificate_signed_status_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 CertificateSignedStatusEnumType。
 */
CertificateSignedStatusEnumType string_to_certificate_signed_status_enum_type(const std::string& s) {
    if (s == "Accepted") {
        return CertificateSignedStatusEnumType::Accepted;
    }
    if (s == "Rejected") {
        return CertificateSignedStatusEnumType::Rejected;
    }

    throw StringToEnumException{s, "CertificateSignedStatusEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @certificate_signed_status_enum_type: 传入的 certificate_signed_status_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const CertificateSignedStatusEnumType& certificate_signed_status_enum_type) {
    os << conversions::certificate_signed_status_enum_type_to_string(certificate_signed_status_enum_type);
    return os;
}

// from: ChangeAvailabilityRequest
namespace conversions {
/**
 * availability_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string availability_type_to_string(AvailabilityType e) {
    switch (e) {
    case AvailabilityType::Inoperative:
        return "Inoperative";
    case AvailabilityType::Operative:
        return "Operative";
    }

    throw EnumToStringException{e, "AvailabilityType"};
}

/**
 * string_to_availability_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 AvailabilityType。
 */
AvailabilityType string_to_availability_type(const std::string& s) {
    if (s == "Inoperative") {
        return AvailabilityType::Inoperative;
    }
    if (s == "Operative") {
        return AvailabilityType::Operative;
    }

    throw StringToEnumException{s, "AvailabilityType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @availability_type: 传入的 availability_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const AvailabilityType& availability_type) {
    os << conversions::availability_type_to_string(availability_type);
    return os;
}

// from: ChangeAvailabilityResponse
namespace conversions {
/**
 * availability_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string availability_status_to_string(AvailabilityStatus e) {
    switch (e) {
    case AvailabilityStatus::Accepted:
        return "Accepted";
    case AvailabilityStatus::Rejected:
        return "Rejected";
    case AvailabilityStatus::Scheduled:
        return "Scheduled";
    }

    throw EnumToStringException{e, "AvailabilityStatus"};
}

/**
 * string_to_availability_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 AvailabilityStatus。
 */
AvailabilityStatus string_to_availability_status(const std::string& s) {
    if (s == "Accepted") {
        return AvailabilityStatus::Accepted;
    }
    if (s == "Rejected") {
        return AvailabilityStatus::Rejected;
    }
    if (s == "Scheduled") {
        return AvailabilityStatus::Scheduled;
    }

    throw StringToEnumException{s, "AvailabilityStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @availability_status: 传入的 availability_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const AvailabilityStatus& availability_status) {
    os << conversions::availability_status_to_string(availability_status);
    return os;
}

// from: ChangeConfigurationResponse
namespace conversions {
/**
 * configuration_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string configuration_status_to_string(ConfigurationStatus e) {
    switch (e) {
    case ConfigurationStatus::Accepted:
        return "Accepted";
    case ConfigurationStatus::Rejected:
        return "Rejected";
    case ConfigurationStatus::RebootRequired:
        return "RebootRequired";
    case ConfigurationStatus::NotSupported:
        return "NotSupported";
    }

    throw EnumToStringException{e, "ConfigurationStatus"};
}

/**
 * string_to_configuration_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ConfigurationStatus。
 */
ConfigurationStatus string_to_configuration_status(const std::string& s) {
    if (s == "Accepted") {
        return ConfigurationStatus::Accepted;
    }
    if (s == "Rejected") {
        return ConfigurationStatus::Rejected;
    }
    if (s == "RebootRequired") {
        return ConfigurationStatus::RebootRequired;
    }
    if (s == "NotSupported") {
        return ConfigurationStatus::NotSupported;
    }

    throw StringToEnumException{s, "ConfigurationStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @configuration_status: 传入的 configuration_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ConfigurationStatus& configuration_status) {
    os << conversions::configuration_status_to_string(configuration_status);
    return os;
}

// from: ClearCacheResponse
namespace conversions {
/**
 * clear_cache_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string clear_cache_status_to_string(ClearCacheStatus e) {
    switch (e) {
    case ClearCacheStatus::Accepted:
        return "Accepted";
    case ClearCacheStatus::Rejected:
        return "Rejected";
    }

    throw EnumToStringException{e, "ClearCacheStatus"};
}

/**
 * string_to_clear_cache_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ClearCacheStatus。
 */
ClearCacheStatus string_to_clear_cache_status(const std::string& s) {
    if (s == "Accepted") {
        return ClearCacheStatus::Accepted;
    }
    if (s == "Rejected") {
        return ClearCacheStatus::Rejected;
    }

    throw StringToEnumException{s, "ClearCacheStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @clear_cache_status: 传入的 clear_cache_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ClearCacheStatus& clear_cache_status) {
    os << conversions::clear_cache_status_to_string(clear_cache_status);
    return os;
}

// from: ClearChargingProfileRequest
namespace conversions {
/**
 * charging_profile_purpose_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string charging_profile_purpose_type_to_string(ChargingProfilePurposeType e) {
    switch (e) {
    case ChargingProfilePurposeType::ChargePointMaxProfile:
        return "ChargePointMaxProfile";
    case ChargingProfilePurposeType::TxDefaultProfile:
        return "TxDefaultProfile";
    case ChargingProfilePurposeType::TxProfile:
        return "TxProfile";
    }

    throw EnumToStringException{e, "ChargingProfilePurposeType"};
}

/**
 * string_to_charging_profile_purpose_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ChargingProfilePurposeType。
 */
ChargingProfilePurposeType string_to_charging_profile_purpose_type(const std::string& s) {
    if (s == "ChargePointMaxProfile") {
        return ChargingProfilePurposeType::ChargePointMaxProfile;
    }
    if (s == "TxDefaultProfile") {
        return ChargingProfilePurposeType::TxDefaultProfile;
    }
    if (s == "TxProfile") {
        return ChargingProfilePurposeType::TxProfile;
    }

    throw StringToEnumException{s, "ChargingProfilePurposeType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @charging_profile_purpose_type: 传入的 charging_profile_purpose_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ChargingProfilePurposeType& charging_profile_purpose_type) {
    os << conversions::charging_profile_purpose_type_to_string(charging_profile_purpose_type);
    return os;
}

// from: ClearChargingProfileResponse
namespace conversions {
/**
 * clear_charging_profile_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string clear_charging_profile_status_to_string(ClearChargingProfileStatus e) {
    switch (e) {
    case ClearChargingProfileStatus::Accepted:
        return "Accepted";
    case ClearChargingProfileStatus::Unknown:
        return "Unknown";
    }

    throw EnumToStringException{e, "ClearChargingProfileStatus"};
}

/**
 * string_to_clear_charging_profile_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ClearChargingProfileStatus。
 */
ClearChargingProfileStatus string_to_clear_charging_profile_status(const std::string& s) {
    if (s == "Accepted") {
        return ClearChargingProfileStatus::Accepted;
    }
    if (s == "Unknown") {
        return ClearChargingProfileStatus::Unknown;
    }

    throw StringToEnumException{s, "ClearChargingProfileStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @clear_charging_profile_status: 传入的 clear_charging_profile_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ClearChargingProfileStatus& clear_charging_profile_status) {
    os << conversions::clear_charging_profile_status_to_string(clear_charging_profile_status);
    return os;
}

// from: DataTransferResponse
namespace conversions {
/**
 * data_transfer_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string data_transfer_status_to_string(DataTransferStatus e) {
    switch (e) {
    case DataTransferStatus::Accepted:
        return "Accepted";
    case DataTransferStatus::Rejected:
        return "Rejected";
    case DataTransferStatus::UnknownMessageId:
        return "UnknownMessageId";
    case DataTransferStatus::UnknownVendorId:
        return "UnknownVendorId";
    }

    throw EnumToStringException{e, "DataTransferStatus"};
}

/**
 * string_to_data_transfer_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 DataTransferStatus。
 */
DataTransferStatus string_to_data_transfer_status(const std::string& s) {
    if (s == "Accepted") {
        return DataTransferStatus::Accepted;
    }
    if (s == "Rejected") {
        return DataTransferStatus::Rejected;
    }
    if (s == "UnknownMessageId") {
        return DataTransferStatus::UnknownMessageId;
    }
    if (s == "UnknownVendorId") {
        return DataTransferStatus::UnknownVendorId;
    }

    throw StringToEnumException{s, "DataTransferStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @data_transfer_status: 传入的 data_transfer_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const DataTransferStatus& data_transfer_status) {
    os << conversions::data_transfer_status_to_string(data_transfer_status);
    return os;
}

// from: DeleteCertificateRequest
namespace conversions {
/**
 * hash_algorithm_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string hash_algorithm_enum_type_to_string(HashAlgorithmEnumType e) {
    switch (e) {
    case HashAlgorithmEnumType::SHA256:
        return "SHA256";
    case HashAlgorithmEnumType::SHA384:
        return "SHA384";
    case HashAlgorithmEnumType::SHA512:
        return "SHA512";
    }

    throw EnumToStringException{e, "HashAlgorithmEnumType"};
}

/**
 * string_to_hash_algorithm_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 HashAlgorithmEnumType。
 */
HashAlgorithmEnumType string_to_hash_algorithm_enum_type(const std::string& s) {
    if (s == "SHA256") {
        return HashAlgorithmEnumType::SHA256;
    }
    if (s == "SHA384") {
        return HashAlgorithmEnumType::SHA384;
    }
    if (s == "SHA512") {
        return HashAlgorithmEnumType::SHA512;
    }

    throw StringToEnumException{s, "HashAlgorithmEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @hash_algorithm_enum_type: 传入的 hash_algorithm_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const HashAlgorithmEnumType& hash_algorithm_enum_type) {
    os << conversions::hash_algorithm_enum_type_to_string(hash_algorithm_enum_type);
    return os;
}

// from: DeleteCertificateResponse
namespace conversions {
/**
 * delete_certificate_status_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string delete_certificate_status_enum_type_to_string(DeleteCertificateStatusEnumType e) {
    switch (e) {
    case DeleteCertificateStatusEnumType::Accepted:
        return "Accepted";
    case DeleteCertificateStatusEnumType::Failed:
        return "Failed";
    case DeleteCertificateStatusEnumType::NotFound:
        return "NotFound";
    }

    throw EnumToStringException{e, "DeleteCertificateStatusEnumType"};
}

/**
 * string_to_delete_certificate_status_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 DeleteCertificateStatusEnumType。
 */
DeleteCertificateStatusEnumType string_to_delete_certificate_status_enum_type(const std::string& s) {
    if (s == "Accepted") {
        return DeleteCertificateStatusEnumType::Accepted;
    }
    if (s == "Failed") {
        return DeleteCertificateStatusEnumType::Failed;
    }
    if (s == "NotFound") {
        return DeleteCertificateStatusEnumType::NotFound;
    }

    throw StringToEnumException{s, "DeleteCertificateStatusEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @delete_certificate_status_enum_type: 传入的 delete_certificate_status_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const DeleteCertificateStatusEnumType& delete_certificate_status_enum_type) {
    os << conversions::delete_certificate_status_enum_type_to_string(delete_certificate_status_enum_type);
    return os;
}

// from: DiagnosticsStatusNotificationRequest
namespace conversions {
/**
 * diagnostics_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string diagnostics_status_to_string(DiagnosticsStatus e) {
    switch (e) {
    case DiagnosticsStatus::Idle:
        return "Idle";
    case DiagnosticsStatus::Uploaded:
        return "Uploaded";
    case DiagnosticsStatus::UploadFailed:
        return "UploadFailed";
    case DiagnosticsStatus::Uploading:
        return "Uploading";
    }

    throw EnumToStringException{e, "DiagnosticsStatus"};
}

/**
 * string_to_diagnostics_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 DiagnosticsStatus。
 */
DiagnosticsStatus string_to_diagnostics_status(const std::string& s) {
    if (s == "Idle") {
        return DiagnosticsStatus::Idle;
    }
    if (s == "Uploaded") {
        return DiagnosticsStatus::Uploaded;
    }
    if (s == "UploadFailed") {
        return DiagnosticsStatus::UploadFailed;
    }
    if (s == "Uploading") {
        return DiagnosticsStatus::Uploading;
    }

    throw StringToEnumException{s, "DiagnosticsStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @diagnostics_status: 传入的 diagnostics_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const DiagnosticsStatus& diagnostics_status) {
    os << conversions::diagnostics_status_to_string(diagnostics_status);
    return os;
}

// from: ExtendedTriggerMessageRequest
namespace conversions {
/**
 * message_trigger_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string message_trigger_enum_type_to_string(MessageTriggerEnumType e) {
    switch (e) {
    case MessageTriggerEnumType::BootNotification:
        return "BootNotification";
    case MessageTriggerEnumType::LogStatusNotification:
        return "LogStatusNotification";
    case MessageTriggerEnumType::FirmwareStatusNotification:
        return "FirmwareStatusNotification";
    case MessageTriggerEnumType::Heartbeat:
        return "Heartbeat";
    case MessageTriggerEnumType::MeterValues:
        return "MeterValues";
    case MessageTriggerEnumType::SignChargePointCertificate:
        return "SignChargePointCertificate";
    case MessageTriggerEnumType::StatusNotification:
        return "StatusNotification";
    }

    throw EnumToStringException{e, "MessageTriggerEnumType"};
}

/**
 * string_to_message_trigger_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 MessageTriggerEnumType。
 */
MessageTriggerEnumType string_to_message_trigger_enum_type(const std::string& s) {
    if (s == "BootNotification") {
        return MessageTriggerEnumType::BootNotification;
    }
    if (s == "LogStatusNotification") {
        return MessageTriggerEnumType::LogStatusNotification;
    }
    if (s == "FirmwareStatusNotification") {
        return MessageTriggerEnumType::FirmwareStatusNotification;
    }
    if (s == "Heartbeat") {
        return MessageTriggerEnumType::Heartbeat;
    }
    if (s == "MeterValues") {
        return MessageTriggerEnumType::MeterValues;
    }
    if (s == "SignChargePointCertificate") {
        return MessageTriggerEnumType::SignChargePointCertificate;
    }
    if (s == "StatusNotification") {
        return MessageTriggerEnumType::StatusNotification;
    }

    throw StringToEnumException{s, "MessageTriggerEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @message_trigger_enum_type: 传入的 message_trigger_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const MessageTriggerEnumType& message_trigger_enum_type) {
    os << conversions::message_trigger_enum_type_to_string(message_trigger_enum_type);
    return os;
}

// from: ExtendedTriggerMessageResponse
namespace conversions {
/**
 * trigger_message_status_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string trigger_message_status_enum_type_to_string(TriggerMessageStatusEnumType e) {
    switch (e) {
    case TriggerMessageStatusEnumType::Accepted:
        return "Accepted";
    case TriggerMessageStatusEnumType::Rejected:
        return "Rejected";
    case TriggerMessageStatusEnumType::NotImplemented:
        return "NotImplemented";
    }

    throw EnumToStringException{e, "TriggerMessageStatusEnumType"};
}

/**
 * string_to_trigger_message_status_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 TriggerMessageStatusEnumType。
 */
TriggerMessageStatusEnumType string_to_trigger_message_status_enum_type(const std::string& s) {
    if (s == "Accepted") {
        return TriggerMessageStatusEnumType::Accepted;
    }
    if (s == "Rejected") {
        return TriggerMessageStatusEnumType::Rejected;
    }
    if (s == "NotImplemented") {
        return TriggerMessageStatusEnumType::NotImplemented;
    }

    throw StringToEnumException{s, "TriggerMessageStatusEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @trigger_message_status_enum_type: 传入的 trigger_message_status_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const TriggerMessageStatusEnumType& trigger_message_status_enum_type) {
    os << conversions::trigger_message_status_enum_type_to_string(trigger_message_status_enum_type);
    return os;
}

// from: FirmwareStatusNotificationRequest
namespace conversions {
/**
 * firmware_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string firmware_status_to_string(FirmwareStatus e) {
    switch (e) {
    case FirmwareStatus::Downloaded:
        return "Downloaded";
    case FirmwareStatus::DownloadFailed:
        return "DownloadFailed";
    case FirmwareStatus::Downloading:
        return "Downloading";
    case FirmwareStatus::Idle:
        return "Idle";
    case FirmwareStatus::InstallationFailed:
        return "InstallationFailed";
    case FirmwareStatus::Installing:
        return "Installing";
    case FirmwareStatus::Installed:
        return "Installed";
    }

    throw EnumToStringException{e, "FirmwareStatus"};
}

/**
 * string_to_firmware_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 FirmwareStatus。
 */
FirmwareStatus string_to_firmware_status(const std::string& s) {
    if (s == "Downloaded") {
        return FirmwareStatus::Downloaded;
    }
    if (s == "DownloadFailed") {
        return FirmwareStatus::DownloadFailed;
    }
    if (s == "Downloading") {
        return FirmwareStatus::Downloading;
    }
    if (s == "Idle") {
        return FirmwareStatus::Idle;
    }
    if (s == "InstallationFailed") {
        return FirmwareStatus::InstallationFailed;
    }
    if (s == "Installing") {
        return FirmwareStatus::Installing;
    }
    if (s == "Installed") {
        return FirmwareStatus::Installed;
    }

    throw StringToEnumException{s, "FirmwareStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @firmware_status: 传入的 firmware_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const FirmwareStatus& firmware_status) {
    os << conversions::firmware_status_to_string(firmware_status);
    return os;
}

// from: GetCompositeScheduleRequest
namespace conversions {
/**
 * charging_rate_unit_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string charging_rate_unit_to_string(ChargingRateUnit e) {
    switch (e) {
    case ChargingRateUnit::A:
        return "A";
    case ChargingRateUnit::W:
        return "W";
    }

    throw EnumToStringException{e, "ChargingRateUnit"};
}

/**
 * string_to_charging_rate_unit - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ChargingRateUnit。
 */
ChargingRateUnit string_to_charging_rate_unit(const std::string& s) {
    if (s == "A") {
        return ChargingRateUnit::A;
    }
    if (s == "W") {
        return ChargingRateUnit::W;
    }

    throw StringToEnumException{s, "ChargingRateUnit"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @charging_rate_unit: 传入的 charging_rate_unit
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ChargingRateUnit& charging_rate_unit) {
    os << conversions::charging_rate_unit_to_string(charging_rate_unit);
    return os;
}

// from: GetCompositeScheduleResponse
namespace conversions {
/**
 * get_composite_schedule_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string get_composite_schedule_status_to_string(GetCompositeScheduleStatus e) {
    switch (e) {
    case GetCompositeScheduleStatus::Accepted:
        return "Accepted";
    case GetCompositeScheduleStatus::Rejected:
        return "Rejected";
    }

    throw EnumToStringException{e, "GetCompositeScheduleStatus"};
}

/**
 * string_to_get_composite_schedule_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 GetCompositeScheduleStatus。
 */
GetCompositeScheduleStatus string_to_get_composite_schedule_status(const std::string& s) {
    if (s == "Accepted") {
        return GetCompositeScheduleStatus::Accepted;
    }
    if (s == "Rejected") {
        return GetCompositeScheduleStatus::Rejected;
    }

    throw StringToEnumException{s, "GetCompositeScheduleStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @get_composite_schedule_status: 传入的 get_composite_schedule_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const GetCompositeScheduleStatus& get_composite_schedule_status) {
    os << conversions::get_composite_schedule_status_to_string(get_composite_schedule_status);
    return os;
}

// from: GetInstalledCertificateIdsRequest
namespace conversions {
/**
 * certificate_use_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string certificate_use_enum_type_to_string(CertificateUseEnumType e) {
    switch (e) {
    case CertificateUseEnumType::CentralSystemRootCertificate:
        return "CentralSystemRootCertificate";
    case CertificateUseEnumType::ManufacturerRootCertificate:
        return "ManufacturerRootCertificate";
    }

    throw EnumToStringException{e, "CertificateUseEnumType"};
}

/**
 * string_to_certificate_use_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 CertificateUseEnumType。
 */
CertificateUseEnumType string_to_certificate_use_enum_type(const std::string& s) {
    if (s == "CentralSystemRootCertificate") {
        return CertificateUseEnumType::CentralSystemRootCertificate;
    }
    if (s == "ManufacturerRootCertificate") {
        return CertificateUseEnumType::ManufacturerRootCertificate;
    }

    throw StringToEnumException{s, "CertificateUseEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @certificate_use_enum_type: 传入的 certificate_use_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const CertificateUseEnumType& certificate_use_enum_type) {
    os << conversions::certificate_use_enum_type_to_string(certificate_use_enum_type);
    return os;
}

// from: GetInstalledCertificateIdsResponse
namespace conversions {
/**
 * get_installed_certificate_status_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string get_installed_certificate_status_enum_type_to_string(GetInstalledCertificateStatusEnumType e) {
    switch (e) {
    case GetInstalledCertificateStatusEnumType::Accepted:
        return "Accepted";
    case GetInstalledCertificateStatusEnumType::NotFound:
        return "NotFound";
    }

    throw EnumToStringException{e, "GetInstalledCertificateStatusEnumType"};
}

/**
 * string_to_get_installed_certificate_status_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 GetInstalledCertificateStatusEnumType。
 */
GetInstalledCertificateStatusEnumType string_to_get_installed_certificate_status_enum_type(const std::string& s) {
    if (s == "Accepted") {
        return GetInstalledCertificateStatusEnumType::Accepted;
    }
    if (s == "NotFound") {
        return GetInstalledCertificateStatusEnumType::NotFound;
    }

    throw StringToEnumException{s, "GetInstalledCertificateStatusEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @get_installed_certificate_status_enum_type: 传入的 get_installed_certificate_status_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os,
                         const GetInstalledCertificateStatusEnumType& get_installed_certificate_status_enum_type) {
    os << conversions::get_installed_certificate_status_enum_type_to_string(get_installed_certificate_status_enum_type);
    return os;
}

// from: GetLogRequest
namespace conversions {
/**
 * log_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string log_enum_type_to_string(LogEnumType e) {
    switch (e) {
    case LogEnumType::DiagnosticsLog:
        return "DiagnosticsLog";
    case LogEnumType::SecurityLog:
        return "SecurityLog";
    }

    throw EnumToStringException{e, "LogEnumType"};
}

/**
 * string_to_log_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 LogEnumType。
 */
LogEnumType string_to_log_enum_type(const std::string& s) {
    if (s == "DiagnosticsLog") {
        return LogEnumType::DiagnosticsLog;
    }
    if (s == "SecurityLog") {
        return LogEnumType::SecurityLog;
    }

    throw StringToEnumException{s, "LogEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @log_enum_type: 传入的 log_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const LogEnumType& log_enum_type) {
    os << conversions::log_enum_type_to_string(log_enum_type);
    return os;
}

// from: GetLogResponse
namespace conversions {
/**
 * log_status_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string log_status_enum_type_to_string(LogStatusEnumType e) {
    switch (e) {
    case LogStatusEnumType::Accepted:
        return "Accepted";
    case LogStatusEnumType::Rejected:
        return "Rejected";
    case LogStatusEnumType::AcceptedCanceled:
        return "AcceptedCanceled";
    }

    throw EnumToStringException{e, "LogStatusEnumType"};
}

/**
 * string_to_log_status_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 LogStatusEnumType。
 */
LogStatusEnumType string_to_log_status_enum_type(const std::string& s) {
    if (s == "Accepted") {
        return LogStatusEnumType::Accepted;
    }
    if (s == "Rejected") {
        return LogStatusEnumType::Rejected;
    }
    if (s == "AcceptedCanceled") {
        return LogStatusEnumType::AcceptedCanceled;
    }

    throw StringToEnumException{s, "LogStatusEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @log_status_enum_type: 传入的 log_status_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const LogStatusEnumType& log_status_enum_type) {
    os << conversions::log_status_enum_type_to_string(log_status_enum_type);
    return os;
}

// from: InstallCertificateResponse
namespace conversions {
/**
 * install_certificate_status_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string install_certificate_status_enum_type_to_string(InstallCertificateStatusEnumType e) {
    switch (e) {
    case InstallCertificateStatusEnumType::Accepted:
        return "Accepted";
    case InstallCertificateStatusEnumType::Failed:
        return "Failed";
    case InstallCertificateStatusEnumType::Rejected:
        return "Rejected";
    }

    throw EnumToStringException{e, "InstallCertificateStatusEnumType"};
}

/**
 * string_to_install_certificate_status_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 InstallCertificateStatusEnumType。
 */
InstallCertificateStatusEnumType string_to_install_certificate_status_enum_type(const std::string& s) {
    if (s == "Accepted") {
        return InstallCertificateStatusEnumType::Accepted;
    }
    if (s == "Failed") {
        return InstallCertificateStatusEnumType::Failed;
    }
    if (s == "Rejected") {
        return InstallCertificateStatusEnumType::Rejected;
    }

    throw StringToEnumException{s, "InstallCertificateStatusEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @install_certificate_status_enum_type: 传入的 install_certificate_status_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os,
                         const InstallCertificateStatusEnumType& install_certificate_status_enum_type) {
    os << conversions::install_certificate_status_enum_type_to_string(install_certificate_status_enum_type);
    return os;
}

// from: LogStatusNotificationRequest
namespace conversions {
/**
 * upload_log_status_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string upload_log_status_enum_type_to_string(UploadLogStatusEnumType e) {
    switch (e) {
    case UploadLogStatusEnumType::BadMessage:
        return "BadMessage";
    case UploadLogStatusEnumType::Idle:
        return "Idle";
    case UploadLogStatusEnumType::NotSupportedOperation:
        return "NotSupportedOperation";
    case UploadLogStatusEnumType::PermissionDenied:
        return "PermissionDenied";
    case UploadLogStatusEnumType::Uploaded:
        return "Uploaded";
    case UploadLogStatusEnumType::UploadFailure:
        return "UploadFailure";
    case UploadLogStatusEnumType::Uploading:
        return "Uploading";
    }

    throw EnumToStringException{e, "UploadLogStatusEnumType"};
}

/**
 * string_to_upload_log_status_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 UploadLogStatusEnumType。
 */
UploadLogStatusEnumType string_to_upload_log_status_enum_type(const std::string& s) {
    if (s == "BadMessage") {
        return UploadLogStatusEnumType::BadMessage;
    }
    if (s == "Idle") {
        return UploadLogStatusEnumType::Idle;
    }
    if (s == "NotSupportedOperation") {
        return UploadLogStatusEnumType::NotSupportedOperation;
    }
    if (s == "PermissionDenied") {
        return UploadLogStatusEnumType::PermissionDenied;
    }
    if (s == "Uploaded") {
        return UploadLogStatusEnumType::Uploaded;
    }
    if (s == "UploadFailure") {
        return UploadLogStatusEnumType::UploadFailure;
    }
    if (s == "Uploading") {
        return UploadLogStatusEnumType::Uploading;
    }

    throw StringToEnumException{s, "UploadLogStatusEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @upload_log_status_enum_type: 传入的 upload_log_status_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const UploadLogStatusEnumType& upload_log_status_enum_type) {
    os << conversions::upload_log_status_enum_type_to_string(upload_log_status_enum_type);
    return os;
}

// from: MeterValuesRequest
namespace conversions {
/**
 * reading_context_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string reading_context_to_string(ReadingContext e) {
    switch (e) {
    case ReadingContext::Interruption_Begin:
        return "Interruption.Begin";
    case ReadingContext::Interruption_End:
        return "Interruption.End";
    case ReadingContext::Sample_Clock:
        return "Sample.Clock";
    case ReadingContext::Sample_Periodic:
        return "Sample.Periodic";
    case ReadingContext::Transaction_Begin:
        return "Transaction.Begin";
    case ReadingContext::Transaction_End:
        return "Transaction.End";
    case ReadingContext::Trigger:
        return "Trigger";
    case ReadingContext::Other:
        return "Other";
    }

    throw EnumToStringException{e, "ReadingContext"};
}

/**
 * string_to_reading_context - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ReadingContext。
 */
ReadingContext string_to_reading_context(const std::string& s) {
    if (s == "Interruption.Begin") {
        return ReadingContext::Interruption_Begin;
    }
    if (s == "Interruption.End") {
        return ReadingContext::Interruption_End;
    }
    if (s == "Sample.Clock") {
        return ReadingContext::Sample_Clock;
    }
    if (s == "Sample.Periodic") {
        return ReadingContext::Sample_Periodic;
    }
    if (s == "Transaction.Begin") {
        return ReadingContext::Transaction_Begin;
    }
    if (s == "Transaction.End") {
        return ReadingContext::Transaction_End;
    }
    if (s == "Trigger") {
        return ReadingContext::Trigger;
    }
    if (s == "Other") {
        return ReadingContext::Other;
    }

    throw StringToEnumException{s, "ReadingContext"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @reading_context: 传入的 reading_context
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ReadingContext& reading_context) {
    os << conversions::reading_context_to_string(reading_context);
    return os;
}

// from: MeterValuesRequest
namespace conversions {
/**
 * value_format_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string value_format_to_string(ValueFormat e) {
    switch (e) {
    case ValueFormat::Raw:
        return "Raw";
    case ValueFormat::SignedData:
        return "SignedData";
    }

    throw EnumToStringException{e, "ValueFormat"};
}

/**
 * string_to_value_format - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ValueFormat。
 */
ValueFormat string_to_value_format(const std::string& s) {
    if (s == "Raw") {
        return ValueFormat::Raw;
    }
    if (s == "SignedData") {
        return ValueFormat::SignedData;
    }

    throw StringToEnumException{s, "ValueFormat"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @value_format: 传入的 value_format
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ValueFormat& value_format) {
    os << conversions::value_format_to_string(value_format);
    return os;
}

// from: MeterValuesRequest
namespace conversions {
/**
 * measurand_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string measurand_to_string(Measurand e) {
    switch (e) {
    case Measurand::Energy_Active_Export_Register:
        return "Energy.Active.Export.Register";
    case Measurand::Energy_Active_Import_Register:
        return "Energy.Active.Import.Register";
    case Measurand::Energy_Reactive_Export_Register:
        return "Energy.Reactive.Export.Register";
    case Measurand::Energy_Reactive_Import_Register:
        return "Energy.Reactive.Import.Register";
    case Measurand::Energy_Active_Export_Interval:
        return "Energy.Active.Export.Interval";
    case Measurand::Energy_Active_Import_Interval:
        return "Energy.Active.Import.Interval";
    case Measurand::Energy_Reactive_Export_Interval:
        return "Energy.Reactive.Export.Interval";
    case Measurand::Energy_Reactive_Import_Interval:
        return "Energy.Reactive.Import.Interval";
    case Measurand::Power_Active_Export:
        return "Power.Active.Export";
    case Measurand::Power_Active_Import:
        return "Power.Active.Import";
    case Measurand::Power_Offered:
        return "Power.Offered";
    case Measurand::Power_Reactive_Export:
        return "Power.Reactive.Export";
    case Measurand::Power_Reactive_Import:
        return "Power.Reactive.Import";
    case Measurand::Power_Factor:
        return "Power.Factor";
    case Measurand::Current_Import:
        return "Current.Import";
    case Measurand::Current_Export:
        return "Current.Export";
    case Measurand::Current_Offered:
        return "Current.Offered";
    case Measurand::Voltage:
        return "Voltage";
    case Measurand::Frequency:
        return "Frequency";
    case Measurand::Temperature:
        return "Temperature";
    case Measurand::SoC:
        return "SoC";
    case Measurand::RPM:
        return "RPM";
    }

    throw EnumToStringException{e, "Measurand"};
}

/**
 * string_to_measurand - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 Measurand。
 */
Measurand string_to_measurand(const std::string& s) {
    if (s == "Energy.Active.Export.Register") {
        return Measurand::Energy_Active_Export_Register;
    }
    if (s == "Energy.Active.Import.Register") {
        return Measurand::Energy_Active_Import_Register;
    }
    if (s == "Energy.Reactive.Export.Register") {
        return Measurand::Energy_Reactive_Export_Register;
    }
    if (s == "Energy.Reactive.Import.Register") {
        return Measurand::Energy_Reactive_Import_Register;
    }
    if (s == "Energy.Active.Export.Interval") {
        return Measurand::Energy_Active_Export_Interval;
    }
    if (s == "Energy.Active.Import.Interval") {
        return Measurand::Energy_Active_Import_Interval;
    }
    if (s == "Energy.Reactive.Export.Interval") {
        return Measurand::Energy_Reactive_Export_Interval;
    }
    if (s == "Energy.Reactive.Import.Interval") {
        return Measurand::Energy_Reactive_Import_Interval;
    }
    if (s == "Power.Active.Export") {
        return Measurand::Power_Active_Export;
    }
    if (s == "Power.Active.Import") {
        return Measurand::Power_Active_Import;
    }
    if (s == "Power.Offered") {
        return Measurand::Power_Offered;
    }
    if (s == "Power.Reactive.Export") {
        return Measurand::Power_Reactive_Export;
    }
    if (s == "Power.Reactive.Import") {
        return Measurand::Power_Reactive_Import;
    }
    if (s == "Power.Factor") {
        return Measurand::Power_Factor;
    }
    if (s == "Current.Import") {
        return Measurand::Current_Import;
    }
    if (s == "Current.Export") {
        return Measurand::Current_Export;
    }
    if (s == "Current.Offered") {
        return Measurand::Current_Offered;
    }
    if (s == "Voltage") {
        return Measurand::Voltage;
    }
    if (s == "Frequency") {
        return Measurand::Frequency;
    }
    if (s == "Temperature") {
        return Measurand::Temperature;
    }
    if (s == "SoC") {
        return Measurand::SoC;
    }
    if (s == "RPM") {
        return Measurand::RPM;
    }

    throw StringToEnumException{s, "Measurand"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @measurand: 传入的 measurand
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const Measurand& measurand) {
    os << conversions::measurand_to_string(measurand);
    return os;
}

// from: MeterValuesRequest
namespace conversions {
/**
 * phase_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string phase_to_string(Phase e) {
    switch (e) {
    case Phase::L1:
        return "L1";
    case Phase::L2:
        return "L2";
    case Phase::L3:
        return "L3";
    case Phase::N:
        return "N";
    case Phase::L1_N:
        return "L1-N";
    case Phase::L2_N:
        return "L2-N";
    case Phase::L3_N:
        return "L3-N";
    case Phase::L1_L2:
        return "L1-L2";
    case Phase::L2_L3:
        return "L2-L3";
    case Phase::L3_L1:
        return "L3-L1";
    }

    throw EnumToStringException{e, "Phase"};
}

/**
 * string_to_phase - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 Phase。
 */
Phase string_to_phase(const std::string& s) {
    if (s == "L1") {
        return Phase::L1;
    }
    if (s == "L2") {
        return Phase::L2;
    }
    if (s == "L3") {
        return Phase::L3;
    }
    if (s == "N") {
        return Phase::N;
    }
    if (s == "L1-N") {
        return Phase::L1_N;
    }
    if (s == "L2-N") {
        return Phase::L2_N;
    }
    if (s == "L3-N") {
        return Phase::L3_N;
    }
    if (s == "L1-L2") {
        return Phase::L1_L2;
    }
    if (s == "L2-L3") {
        return Phase::L2_L3;
    }
    if (s == "L3-L1") {
        return Phase::L3_L1;
    }

    throw StringToEnumException{s, "Phase"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @phase: 传入的 phase
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const Phase& phase) {
    os << conversions::phase_to_string(phase);
    return os;
}

// from: MeterValuesRequest
namespace conversions {
/**
 * location_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string location_to_string(Location e) {
    switch (e) {
    case Location::Cable:
        return "Cable";
    case Location::EV:
        return "EV";
    case Location::Inlet:
        return "Inlet";
    case Location::Outlet:
        return "Outlet";
    case Location::Body:
        return "Body";
    }

    throw EnumToStringException{e, "Location"};
}

/**
 * string_to_location - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 Location。
 */
Location string_to_location(const std::string& s) {
    if (s == "Cable") {
        return Location::Cable;
    }
    if (s == "EV") {
        return Location::EV;
    }
    if (s == "Inlet") {
        return Location::Inlet;
    }
    if (s == "Outlet") {
        return Location::Outlet;
    }
    if (s == "Body") {
        return Location::Body;
    }

    throw StringToEnumException{s, "Location"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @location: 传入的 location
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const Location& location) {
    os << conversions::location_to_string(location);
    return os;
}

// from: MeterValuesRequest
namespace conversions {
/**
 * unit_of_measure_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string unit_of_measure_to_string(UnitOfMeasure e) {
    switch (e) {
    case UnitOfMeasure::Wh:
        return "Wh";
    case UnitOfMeasure::kWh:
        return "kWh";
    case UnitOfMeasure::varh:
        return "varh";
    case UnitOfMeasure::kvarh:
        return "kvarh";
    case UnitOfMeasure::W:
        return "W";
    case UnitOfMeasure::kW:
        return "kW";
    case UnitOfMeasure::VA:
        return "VA";
    case UnitOfMeasure::kVA:
        return "kVA";
    case UnitOfMeasure::var:
        return "var";
    case UnitOfMeasure::kvar:
        return "kvar";
    case UnitOfMeasure::A:
        return "A";
    case UnitOfMeasure::V:
        return "V";
    case UnitOfMeasure::K:
        return "K";
    case UnitOfMeasure::Celcius:
        return "Celcius";
    case UnitOfMeasure::Celsius:
        return "Celsius";
    case UnitOfMeasure::Fahrenheit:
        return "Fahrenheit";
    case UnitOfMeasure::Percent:
        return "Percent";
    }

    throw EnumToStringException{e, "UnitOfMeasure"};
}

/**
 * string_to_unit_of_measure - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 UnitOfMeasure。
 */
UnitOfMeasure string_to_unit_of_measure(const std::string& s) {
    if (s == "Wh") {
        return UnitOfMeasure::Wh;
    }
    if (s == "kWh") {
        return UnitOfMeasure::kWh;
    }
    if (s == "varh") {
        return UnitOfMeasure::varh;
    }
    if (s == "kvarh") {
        return UnitOfMeasure::kvarh;
    }
    if (s == "W") {
        return UnitOfMeasure::W;
    }
    if (s == "kW") {
        return UnitOfMeasure::kW;
    }
    if (s == "VA") {
        return UnitOfMeasure::VA;
    }
    if (s == "kVA") {
        return UnitOfMeasure::kVA;
    }
    if (s == "var") {
        return UnitOfMeasure::var;
    }
    if (s == "kvar") {
        return UnitOfMeasure::kvar;
    }
    if (s == "A") {
        return UnitOfMeasure::A;
    }
    if (s == "V") {
        return UnitOfMeasure::V;
    }
    if (s == "K") {
        return UnitOfMeasure::K;
    }
    if (s == "Celcius") {
        return UnitOfMeasure::Celcius;
    }
    if (s == "Celsius") {
        return UnitOfMeasure::Celsius;
    }
    if (s == "Fahrenheit") {
        return UnitOfMeasure::Fahrenheit;
    }
    if (s == "Percent") {
        return UnitOfMeasure::Percent;
    }

    throw StringToEnumException{s, "UnitOfMeasure"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @unit_of_measure: 传入的 unit_of_measure
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const UnitOfMeasure& unit_of_measure) {
    os << conversions::unit_of_measure_to_string(unit_of_measure);
    return os;
}

// from: RemoteStartTransactionRequest
namespace conversions {
/**
 * charging_profile_kind_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string charging_profile_kind_type_to_string(ChargingProfileKindType e) {
    switch (e) {
    case ChargingProfileKindType::Absolute:
        return "Absolute";
    case ChargingProfileKindType::Recurring:
        return "Recurring";
    case ChargingProfileKindType::Relative:
        return "Relative";
    }

    throw EnumToStringException{e, "ChargingProfileKindType"};
}

/**
 * string_to_charging_profile_kind_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ChargingProfileKindType。
 */
ChargingProfileKindType string_to_charging_profile_kind_type(const std::string& s) {
    if (s == "Absolute") {
        return ChargingProfileKindType::Absolute;
    }
    if (s == "Recurring") {
        return ChargingProfileKindType::Recurring;
    }
    if (s == "Relative") {
        return ChargingProfileKindType::Relative;
    }

    throw StringToEnumException{s, "ChargingProfileKindType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @charging_profile_kind_type: 传入的 charging_profile_kind_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ChargingProfileKindType& charging_profile_kind_type) {
    os << conversions::charging_profile_kind_type_to_string(charging_profile_kind_type);
    return os;
}

// from: RemoteStartTransactionRequest
namespace conversions {
/**
 * recurrency_kind_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string recurrency_kind_type_to_string(RecurrencyKindType e) {
    switch (e) {
    case RecurrencyKindType::Daily:
        return "Daily";
    case RecurrencyKindType::Weekly:
        return "Weekly";
    }

    throw EnumToStringException{e, "RecurrencyKindType"};
}

/**
 * string_to_recurrency_kind_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 RecurrencyKindType。
 */
RecurrencyKindType string_to_recurrency_kind_type(const std::string& s) {
    if (s == "Daily") {
        return RecurrencyKindType::Daily;
    }
    if (s == "Weekly") {
        return RecurrencyKindType::Weekly;
    }

    throw StringToEnumException{s, "RecurrencyKindType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @recurrency_kind_type: 传入的 recurrency_kind_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const RecurrencyKindType& recurrency_kind_type) {
    os << conversions::recurrency_kind_type_to_string(recurrency_kind_type);
    return os;
}

// from: RemoteStartTransactionResponse
namespace conversions {
/**
 * remote_start_stop_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string remote_start_stop_status_to_string(RemoteStartStopStatus e) {
    switch (e) {
    case RemoteStartStopStatus::Accepted:
        return "Accepted";
    case RemoteStartStopStatus::Rejected:
        return "Rejected";
    }

    throw EnumToStringException{e, "RemoteStartStopStatus"};
}

/**
 * string_to_remote_start_stop_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 RemoteStartStopStatus。
 */
RemoteStartStopStatus string_to_remote_start_stop_status(const std::string& s) {
    if (s == "Accepted") {
        return RemoteStartStopStatus::Accepted;
    }
    if (s == "Rejected") {
        return RemoteStartStopStatus::Rejected;
    }

    throw StringToEnumException{s, "RemoteStartStopStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @remote_start_stop_status: 传入的 remote_start_stop_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const RemoteStartStopStatus& remote_start_stop_status) {
    os << conversions::remote_start_stop_status_to_string(remote_start_stop_status);
    return os;
}

// from: ReserveNowResponse
namespace conversions {
/**
 * reservation_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string reservation_status_to_string(ReservationStatus e) {
    switch (e) {
    case ReservationStatus::Accepted:
        return "Accepted";
    case ReservationStatus::Faulted:
        return "Faulted";
    case ReservationStatus::Occupied:
        return "Occupied";
    case ReservationStatus::Rejected:
        return "Rejected";
    case ReservationStatus::Unavailable:
        return "Unavailable";
    }

    throw EnumToStringException{e, "ReservationStatus"};
}

/**
 * string_to_reservation_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ReservationStatus。
 */
ReservationStatus string_to_reservation_status(const std::string& s) {
    if (s == "Accepted") {
        return ReservationStatus::Accepted;
    }
    if (s == "Faulted") {
        return ReservationStatus::Faulted;
    }
    if (s == "Occupied") {
        return ReservationStatus::Occupied;
    }
    if (s == "Rejected") {
        return ReservationStatus::Rejected;
    }
    if (s == "Unavailable") {
        return ReservationStatus::Unavailable;
    }

    throw StringToEnumException{s, "ReservationStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @reservation_status: 传入的 reservation_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ReservationStatus& reservation_status) {
    os << conversions::reservation_status_to_string(reservation_status);
    return os;
}

// from: ResetRequest
namespace conversions {
/**
 * reset_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string reset_type_to_string(ResetType e) {
    switch (e) {
    case ResetType::Hard:
        return "Hard";
    case ResetType::Soft:
        return "Soft";
    }

    throw EnumToStringException{e, "ResetType"};
}

/**
 * string_to_reset_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ResetType。
 */
ResetType string_to_reset_type(const std::string& s) {
    if (s == "Hard") {
        return ResetType::Hard;
    }
    if (s == "Soft") {
        return ResetType::Soft;
    }

    throw StringToEnumException{s, "ResetType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @reset_type: 传入的 reset_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ResetType& reset_type) {
    os << conversions::reset_type_to_string(reset_type);
    return os;
}

// from: ResetResponse
namespace conversions {
/**
 * reset_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string reset_status_to_string(ResetStatus e) {
    switch (e) {
    case ResetStatus::Accepted:
        return "Accepted";
    case ResetStatus::Rejected:
        return "Rejected";
    }

    throw EnumToStringException{e, "ResetStatus"};
}

/**
 * string_to_reset_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ResetStatus。
 */
ResetStatus string_to_reset_status(const std::string& s) {
    if (s == "Accepted") {
        return ResetStatus::Accepted;
    }
    if (s == "Rejected") {
        return ResetStatus::Rejected;
    }

    throw StringToEnumException{s, "ResetStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @reset_status: 传入的 reset_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ResetStatus& reset_status) {
    os << conversions::reset_status_to_string(reset_status);
    return os;
}

// from: SendLocalListRequest
namespace conversions {
/**
 * update_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string update_type_to_string(UpdateType e) {
    switch (e) {
    case UpdateType::Differential:
        return "Differential";
    case UpdateType::Full:
        return "Full";
    }

    throw EnumToStringException{e, "UpdateType"};
}

/**
 * string_to_update_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 UpdateType。
 */
UpdateType string_to_update_type(const std::string& s) {
    if (s == "Differential") {
        return UpdateType::Differential;
    }
    if (s == "Full") {
        return UpdateType::Full;
    }

    throw StringToEnumException{s, "UpdateType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @update_type: 传入的 update_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const UpdateType& update_type) {
    os << conversions::update_type_to_string(update_type);
    return os;
}

// from: SendLocalListResponse
namespace conversions {
/**
 * update_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string update_status_to_string(UpdateStatus e) {
    switch (e) {
    case UpdateStatus::Accepted:
        return "Accepted";
    case UpdateStatus::Failed:
        return "Failed";
    case UpdateStatus::NotSupported:
        return "NotSupported";
    case UpdateStatus::VersionMismatch:
        return "VersionMismatch";
    }

    throw EnumToStringException{e, "UpdateStatus"};
}

/**
 * string_to_update_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 UpdateStatus。
 */
UpdateStatus string_to_update_status(const std::string& s) {
    if (s == "Accepted") {
        return UpdateStatus::Accepted;
    }
    if (s == "Failed") {
        return UpdateStatus::Failed;
    }
    if (s == "NotSupported") {
        return UpdateStatus::NotSupported;
    }
    if (s == "VersionMismatch") {
        return UpdateStatus::VersionMismatch;
    }

    throw StringToEnumException{s, "UpdateStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @update_status: 传入的 update_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const UpdateStatus& update_status) {
    os << conversions::update_status_to_string(update_status);
    return os;
}

// from: SetChargingProfileResponse
namespace conversions {
/**
 * charging_profile_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string charging_profile_status_to_string(ChargingProfileStatus e) {
    switch (e) {
    case ChargingProfileStatus::Accepted:
        return "Accepted";
    case ChargingProfileStatus::Rejected:
        return "Rejected";
    case ChargingProfileStatus::NotSupported:
        return "NotSupported";
    }

    throw EnumToStringException{e, "ChargingProfileStatus"};
}

/**
 * string_to_charging_profile_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ChargingProfileStatus。
 */
ChargingProfileStatus string_to_charging_profile_status(const std::string& s) {
    if (s == "Accepted") {
        return ChargingProfileStatus::Accepted;
    }
    if (s == "Rejected") {
        return ChargingProfileStatus::Rejected;
    }
    if (s == "NotSupported") {
        return ChargingProfileStatus::NotSupported;
    }

    throw StringToEnumException{s, "ChargingProfileStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @charging_profile_status: 传入的 charging_profile_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ChargingProfileStatus& charging_profile_status) {
    os << conversions::charging_profile_status_to_string(charging_profile_status);
    return os;
}

// from: SignCertificateResponse
namespace conversions {
/**
 * generic_status_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string generic_status_enum_type_to_string(GenericStatusEnumType e) {
    switch (e) {
    case GenericStatusEnumType::Accepted:
        return "Accepted";
    case GenericStatusEnumType::Rejected:
        return "Rejected";
    }

    throw EnumToStringException{e, "GenericStatusEnumType"};
}

/**
 * string_to_generic_status_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 GenericStatusEnumType。
 */
GenericStatusEnumType string_to_generic_status_enum_type(const std::string& s) {
    if (s == "Accepted") {
        return GenericStatusEnumType::Accepted;
    }
    if (s == "Rejected") {
        return GenericStatusEnumType::Rejected;
    }

    throw StringToEnumException{s, "GenericStatusEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @generic_status_enum_type: 传入的 generic_status_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const GenericStatusEnumType& generic_status_enum_type) {
    os << conversions::generic_status_enum_type_to_string(generic_status_enum_type);
    return os;
}

// from: SignedFirmwareStatusNotificationRequest
namespace conversions {
/**
 * firmware_status_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string firmware_status_enum_type_to_string(FirmwareStatusEnumType e) {
    switch (e) {
    case FirmwareStatusEnumType::Downloaded:
        return "Downloaded";
    case FirmwareStatusEnumType::DownloadFailed:
        return "DownloadFailed";
    case FirmwareStatusEnumType::Downloading:
        return "Downloading";
    case FirmwareStatusEnumType::DownloadScheduled:
        return "DownloadScheduled";
    case FirmwareStatusEnumType::DownloadPaused:
        return "DownloadPaused";
    case FirmwareStatusEnumType::Idle:
        return "Idle";
    case FirmwareStatusEnumType::InstallationFailed:
        return "InstallationFailed";
    case FirmwareStatusEnumType::Installing:
        return "Installing";
    case FirmwareStatusEnumType::Installed:
        return "Installed";
    case FirmwareStatusEnumType::InstallRebooting:
        return "InstallRebooting";
    case FirmwareStatusEnumType::InstallScheduled:
        return "InstallScheduled";
    case FirmwareStatusEnumType::InstallVerificationFailed:
        return "InstallVerificationFailed";
    case FirmwareStatusEnumType::InvalidSignature:
        return "InvalidSignature";
    case FirmwareStatusEnumType::SignatureVerified:
        return "SignatureVerified";
    }

    throw EnumToStringException{e, "FirmwareStatusEnumType"};
}

/**
 * string_to_firmware_status_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 FirmwareStatusEnumType。
 */
FirmwareStatusEnumType string_to_firmware_status_enum_type(const std::string& s) {
    if (s == "Downloaded") {
        return FirmwareStatusEnumType::Downloaded;
    }
    if (s == "DownloadFailed") {
        return FirmwareStatusEnumType::DownloadFailed;
    }
    if (s == "Downloading") {
        return FirmwareStatusEnumType::Downloading;
    }
    if (s == "DownloadScheduled") {
        return FirmwareStatusEnumType::DownloadScheduled;
    }
    if (s == "DownloadPaused") {
        return FirmwareStatusEnumType::DownloadPaused;
    }
    if (s == "Idle") {
        return FirmwareStatusEnumType::Idle;
    }
    if (s == "InstallationFailed") {
        return FirmwareStatusEnumType::InstallationFailed;
    }
    if (s == "Installing") {
        return FirmwareStatusEnumType::Installing;
    }
    if (s == "Installed") {
        return FirmwareStatusEnumType::Installed;
    }
    if (s == "InstallRebooting") {
        return FirmwareStatusEnumType::InstallRebooting;
    }
    if (s == "InstallScheduled") {
        return FirmwareStatusEnumType::InstallScheduled;
    }
    if (s == "InstallVerificationFailed") {
        return FirmwareStatusEnumType::InstallVerificationFailed;
    }
    if (s == "InvalidSignature") {
        return FirmwareStatusEnumType::InvalidSignature;
    }
    if (s == "SignatureVerified") {
        return FirmwareStatusEnumType::SignatureVerified;
    }

    throw StringToEnumException{s, "FirmwareStatusEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @firmware_status_enum_type: 传入的 firmware_status_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const FirmwareStatusEnumType& firmware_status_enum_type) {
    os << conversions::firmware_status_enum_type_to_string(firmware_status_enum_type);
    return os;
}

// from: SignedUpdateFirmwareResponse
namespace conversions {
/**
 * update_firmware_status_enum_type_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string update_firmware_status_enum_type_to_string(UpdateFirmwareStatusEnumType e) {
    switch (e) {
    case UpdateFirmwareStatusEnumType::Accepted:
        return "Accepted";
    case UpdateFirmwareStatusEnumType::Rejected:
        return "Rejected";
    case UpdateFirmwareStatusEnumType::AcceptedCanceled:
        return "AcceptedCanceled";
    case UpdateFirmwareStatusEnumType::InvalidCertificate:
        return "InvalidCertificate";
    case UpdateFirmwareStatusEnumType::RevokedCertificate:
        return "RevokedCertificate";
    }

    throw EnumToStringException{e, "UpdateFirmwareStatusEnumType"};
}

/**
 * string_to_update_firmware_status_enum_type - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 UpdateFirmwareStatusEnumType。
 */
UpdateFirmwareStatusEnumType string_to_update_firmware_status_enum_type(const std::string& s) {
    if (s == "Accepted") {
        return UpdateFirmwareStatusEnumType::Accepted;
    }
    if (s == "Rejected") {
        return UpdateFirmwareStatusEnumType::Rejected;
    }
    if (s == "AcceptedCanceled") {
        return UpdateFirmwareStatusEnumType::AcceptedCanceled;
    }
    if (s == "InvalidCertificate") {
        return UpdateFirmwareStatusEnumType::InvalidCertificate;
    }
    if (s == "RevokedCertificate") {
        return UpdateFirmwareStatusEnumType::RevokedCertificate;
    }

    throw StringToEnumException{s, "UpdateFirmwareStatusEnumType"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @update_firmware_status_enum_type: 传入的 update_firmware_status_enum_type
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const UpdateFirmwareStatusEnumType& update_firmware_status_enum_type) {
    os << conversions::update_firmware_status_enum_type_to_string(update_firmware_status_enum_type);
    return os;
}

// from: StatusNotificationRequest
namespace conversions {
/**
 * charge_point_error_code_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string charge_point_error_code_to_string(ChargePointErrorCode e) {
    switch (e) {
    case ChargePointErrorCode::ConnectorLockFailure:
        return "ConnectorLockFailure";
    case ChargePointErrorCode::EVCommunicationError:
        return "EVCommunicationError";
    case ChargePointErrorCode::GroundFailure:
        return "GroundFailure";
    case ChargePointErrorCode::HighTemperature:
        return "HighTemperature";
    case ChargePointErrorCode::InternalError:
        return "InternalError";
    case ChargePointErrorCode::LocalListConflict:
        return "LocalListConflict";
    case ChargePointErrorCode::NoError:
        return "NoError";
    case ChargePointErrorCode::OtherError:
        return "OtherError";
    case ChargePointErrorCode::OverCurrentFailure:
        return "OverCurrentFailure";
    case ChargePointErrorCode::PowerMeterFailure:
        return "PowerMeterFailure";
    case ChargePointErrorCode::PowerSwitchFailure:
        return "PowerSwitchFailure";
    case ChargePointErrorCode::ReaderFailure:
        return "ReaderFailure";
    case ChargePointErrorCode::ResetFailure:
        return "ResetFailure";
    case ChargePointErrorCode::UnderVoltage:
        return "UnderVoltage";
    case ChargePointErrorCode::OverVoltage:
        return "OverVoltage";
    case ChargePointErrorCode::WeakSignal:
        return "WeakSignal";
    }

    throw EnumToStringException{e, "ChargePointErrorCode"};
}

/**
 * string_to_charge_point_error_code - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ChargePointErrorCode。
 */
ChargePointErrorCode string_to_charge_point_error_code(const std::string& s) {
    if (s == "ConnectorLockFailure") {
        return ChargePointErrorCode::ConnectorLockFailure;
    }
    if (s == "EVCommunicationError") {
        return ChargePointErrorCode::EVCommunicationError;
    }
    if (s == "GroundFailure") {
        return ChargePointErrorCode::GroundFailure;
    }
    if (s == "HighTemperature") {
        return ChargePointErrorCode::HighTemperature;
    }
    if (s == "InternalError") {
        return ChargePointErrorCode::InternalError;
    }
    if (s == "LocalListConflict") {
        return ChargePointErrorCode::LocalListConflict;
    }
    if (s == "NoError") {
        return ChargePointErrorCode::NoError;
    }
    if (s == "OtherError") {
        return ChargePointErrorCode::OtherError;
    }
    if (s == "OverCurrentFailure") {
        return ChargePointErrorCode::OverCurrentFailure;
    }
    if (s == "PowerMeterFailure") {
        return ChargePointErrorCode::PowerMeterFailure;
    }
    if (s == "PowerSwitchFailure") {
        return ChargePointErrorCode::PowerSwitchFailure;
    }
    if (s == "ReaderFailure") {
        return ChargePointErrorCode::ReaderFailure;
    }
    if (s == "ResetFailure") {
        return ChargePointErrorCode::ResetFailure;
    }
    if (s == "UnderVoltage") {
        return ChargePointErrorCode::UnderVoltage;
    }
    if (s == "OverVoltage") {
        return ChargePointErrorCode::OverVoltage;
    }
    if (s == "WeakSignal") {
        return ChargePointErrorCode::WeakSignal;
    }

    throw StringToEnumException{s, "ChargePointErrorCode"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @charge_point_error_code: 传入的 charge_point_error_code
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ChargePointErrorCode& charge_point_error_code) {
    os << conversions::charge_point_error_code_to_string(charge_point_error_code);
    return os;
}

// from: StatusNotificationRequest
namespace conversions {
/**
 * charge_point_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string charge_point_status_to_string(ChargePointStatus e) {
    switch (e) {
    case ChargePointStatus::Available:
        return "Available";
    case ChargePointStatus::Preparing:
        return "Preparing";
    case ChargePointStatus::Charging:
        return "Charging";
    case ChargePointStatus::SuspendedEVSE:
        return "SuspendedEVSE";
    case ChargePointStatus::SuspendedEV:
        return "SuspendedEV";
    case ChargePointStatus::Finishing:
        return "Finishing";
    case ChargePointStatus::Reserved:
        return "Reserved";
    case ChargePointStatus::Unavailable:
        return "Unavailable";
    case ChargePointStatus::Faulted:
        return "Faulted";
    }

    throw EnumToStringException{e, "ChargePointStatus"};
}

/**
 * string_to_charge_point_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 ChargePointStatus。
 */
ChargePointStatus string_to_charge_point_status(const std::string& s) {
    if (s == "Available") {
        return ChargePointStatus::Available;
    }
    if (s == "Preparing") {
        return ChargePointStatus::Preparing;
    }
    if (s == "Charging") {
        return ChargePointStatus::Charging;
    }
    if (s == "SuspendedEVSE") {
        return ChargePointStatus::SuspendedEVSE;
    }
    if (s == "SuspendedEV") {
        return ChargePointStatus::SuspendedEV;
    }
    if (s == "Finishing") {
        return ChargePointStatus::Finishing;
    }
    if (s == "Reserved") {
        return ChargePointStatus::Reserved;
    }
    if (s == "Unavailable") {
        return ChargePointStatus::Unavailable;
    }
    if (s == "Faulted") {
        return ChargePointStatus::Faulted;
    }

    throw StringToEnumException{s, "ChargePointStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @charge_point_status: 传入的 charge_point_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const ChargePointStatus& charge_point_status) {
    os << conversions::charge_point_status_to_string(charge_point_status);
    return os;
}

// from: StopTransactionRequest
namespace conversions {
/**
 * reason_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string reason_to_string(Reason e) {
    switch (e) {
    case Reason::EmergencyStop:
        return "EmergencyStop";
    case Reason::EVDisconnected:
        return "EVDisconnected";
    case Reason::HardReset:
        return "HardReset";
    case Reason::Local:
        return "Local";
    case Reason::Other:
        return "Other";
    case Reason::PowerLoss:
        return "PowerLoss";
    case Reason::Reboot:
        return "Reboot";
    case Reason::Remote:
        return "Remote";
    case Reason::SoftReset:
        return "SoftReset";
    case Reason::UnlockCommand:
        return "UnlockCommand";
    case Reason::DeAuthorized:
        return "DeAuthorized";
    }

    throw EnumToStringException{e, "Reason"};
}

/**
 * string_to_reason - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 Reason。
 */
Reason string_to_reason(const std::string& s) {
    if (s == "EmergencyStop") {
        return Reason::EmergencyStop;
    }
    if (s == "EVDisconnected") {
        return Reason::EVDisconnected;
    }
    if (s == "HardReset") {
        return Reason::HardReset;
    }
    if (s == "Local") {
        return Reason::Local;
    }
    if (s == "Other") {
        return Reason::Other;
    }
    if (s == "PowerLoss") {
        return Reason::PowerLoss;
    }
    if (s == "Reboot") {
        return Reason::Reboot;
    }
    if (s == "Remote") {
        return Reason::Remote;
    }
    if (s == "SoftReset") {
        return Reason::SoftReset;
    }
    if (s == "UnlockCommand") {
        return Reason::UnlockCommand;
    }
    if (s == "DeAuthorized") {
        return Reason::DeAuthorized;
    }

    throw StringToEnumException{s, "Reason"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @reason: 传入的 reason
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const Reason& reason) {
    os << conversions::reason_to_string(reason);
    return os;
}

// from: TriggerMessageRequest
namespace conversions {
/**
 * message_trigger_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string message_trigger_to_string(MessageTrigger e) {
    switch (e) {
    case MessageTrigger::BootNotification:
        return "BootNotification";
    case MessageTrigger::DiagnosticsStatusNotification:
        return "DiagnosticsStatusNotification";
    case MessageTrigger::FirmwareStatusNotification:
        return "FirmwareStatusNotification";
    case MessageTrigger::Heartbeat:
        return "Heartbeat";
    case MessageTrigger::MeterValues:
        return "MeterValues";
    case MessageTrigger::StatusNotification:
        return "StatusNotification";
    }

    throw EnumToStringException{e, "MessageTrigger"};
}

/**
 * string_to_message_trigger - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 MessageTrigger。
 */
MessageTrigger string_to_message_trigger(const std::string& s) {
    if (s == "BootNotification") {
        return MessageTrigger::BootNotification;
    }
    if (s == "DiagnosticsStatusNotification") {
        return MessageTrigger::DiagnosticsStatusNotification;
    }
    if (s == "FirmwareStatusNotification") {
        return MessageTrigger::FirmwareStatusNotification;
    }
    if (s == "Heartbeat") {
        return MessageTrigger::Heartbeat;
    }
    if (s == "MeterValues") {
        return MessageTrigger::MeterValues;
    }
    if (s == "StatusNotification") {
        return MessageTrigger::StatusNotification;
    }

    throw StringToEnumException{s, "MessageTrigger"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @message_trigger: 传入的 message_trigger
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const MessageTrigger& message_trigger) {
    os << conversions::message_trigger_to_string(message_trigger);
    return os;
}

// from: TriggerMessageResponse
namespace conversions {
/**
 * trigger_message_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string trigger_message_status_to_string(TriggerMessageStatus e) {
    switch (e) {
    case TriggerMessageStatus::Accepted:
        return "Accepted";
    case TriggerMessageStatus::Rejected:
        return "Rejected";
    case TriggerMessageStatus::NotImplemented:
        return "NotImplemented";
    }

    throw EnumToStringException{e, "TriggerMessageStatus"};
}

/**
 * string_to_trigger_message_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 TriggerMessageStatus。
 */
TriggerMessageStatus string_to_trigger_message_status(const std::string& s) {
    if (s == "Accepted") {
        return TriggerMessageStatus::Accepted;
    }
    if (s == "Rejected") {
        return TriggerMessageStatus::Rejected;
    }
    if (s == "NotImplemented") {
        return TriggerMessageStatus::NotImplemented;
    }

    throw StringToEnumException{s, "TriggerMessageStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @trigger_message_status: 传入的 trigger_message_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const TriggerMessageStatus& trigger_message_status) {
    os << conversions::trigger_message_status_to_string(trigger_message_status);
    return os;
}

// from: UnlockConnectorResponse
namespace conversions {
/**
 * unlock_status_to_string - 把枚举或状态写成 OCPP 协议里的字符串。
 * @e: 要转换的枚举值
 *
 * 返回 std::string。
 */
std::string unlock_status_to_string(UnlockStatus e) {
    switch (e) {
    case UnlockStatus::Unlocked:
        return "Unlocked";
    case UnlockStatus::UnlockFailed:
        return "UnlockFailed";
    case UnlockStatus::NotSupported:
        return "NotSupported";
    }

    throw EnumToStringException{e, "UnlockStatus"};
}

/**
 * string_to_unlock_status - 把 OCPP 协议字符串解析成对应的枚举或状态。无法识别的字符串按该函数原有逻辑处理。
 * @s: OCPP 协议中的字符串
 *
 * 返回 UnlockStatus。
 */
UnlockStatus string_to_unlock_status(const std::string& s) {
    if (s == "Unlocked") {
        return UnlockStatus::Unlocked;
    }
    if (s == "UnlockFailed") {
        return UnlockStatus::UnlockFailed;
    }
    if (s == "NotSupported") {
        return UnlockStatus::NotSupported;
    }

    throw StringToEnumException{s, "UnlockStatus"};
}
} // namespace conversions

/**
 * operator<< - 供日志或容器使用的比较、输出运算符。
 * @os: 输出流，用于日志
 * @unlock_status: 传入的 unlock_status
 *
 * 返回 std::ostream&。
 */
std::ostream& operator<<(std::ostream& os, const UnlockStatus& unlock_status) {
    os << conversions::unlock_status_to_string(unlock_status);
    return os;
}

} // namespace v16
} // namespace ocpp
