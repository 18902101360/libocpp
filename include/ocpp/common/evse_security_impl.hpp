// SPDX-License-Identifier: Apache-2.0
// Copyright 2020 - 2023 Pionix GmbH and Contributors to EVerest
#ifndef OCPP_COMMON_EVSE_SECURITY_IMPL
#define OCPP_COMMON_EVSE_SECURITY_IMPL

#include <filesystem>
#include <optional>

#include <evse_security/evse_security.hpp>
#include <ocpp/common/evse_security.hpp>
#include <ocpp/common/support_older_cpp_versions.hpp>

namespace ocpp {

struct SecurityConfiguration {
    fs::path csms_ca_bundle;
    fs::path mf_ca_bundle;
    fs::path mo_ca_bundle;
    fs::path v2g_ca_bundle;
    fs::path csms_leaf_cert_directory;
    fs::path csms_leaf_key_directory;
    fs::path secc_leaf_cert_directory;
    fs::path secc_leaf_key_directory;
    fs::path secc_leaf_cert_link;
    fs::path secc_leaf_key_link;
    fs::path cpo_cert_chain_link;
    std::optional<std::string> private_key_password;
};

class EvseSecurityImpl : public EvseSecurity {

private:
    std::unique_ptr<evse_security::EvseSecurity> evse_security;

public:
    explicit EvseSecurityImpl(const SecurityConfiguration& security_configuration);
    InstallCertificateResult install_ca_certificate(const std::string& certificate,
                                                    const CaCertificateType& certificate_type) override;
    DeleteCertificateResult delete_certificate(const CertificateHashDataType& certificate_hash_data) override;
    InstallCertificateResult update_leaf_certificate(const std::string& certificate_chain,
                                                     const CertificateSigningUseEnum& certificate_type) override;
    CertificateValidationResult verify_certificate(const std::string& certificate_chain,
                                                   const LeafCertificateType& certificate_type) override;
    CertificateValidationResult verify_certificate(const std::string& certificate_chain,
                                                   const std::vector<LeafCertificateType>& certificate_types) override;
    std::vector<CertificateHashDataChain>
    get_installed_certificates(const std::vector<CertificateType>& certificate_types) override;
    std::vector<OCSPRequestData> get_v2g_ocsp_request_data() override;
    std::vector<OCSPRequestData> get_mo_ocsp_request_data(const std::string& certificate_chain) override;
    void update_ocsp_cache(const CertificateHashDataType& certificate_hash_data,
                           const std::string& ocsp_response) override;
    bool is_ca_certificate_installed(const CaCertificateType& certificate_type) override;
    GetCertificateSignRequestResult
    generate_certificate_signing_request(const CertificateSigningUseEnum& certificate_type, const std::string& country,
                                         const std::string& organization, const std::string& common,
                                         bool use_tpm) override;
    GetCertificateInfoResult get_leaf_certificate_info(const CertificateSigningUseEnum& certificate_type,
                                                       bool include_ocsp = false) override;
    bool update_certificate_links(const CertificateSigningUseEnum& certificate_type) override;
    std::string get_verify_file(const CaCertificateType& certificate_type) override;
    std::string get_verify_location(const CaCertificateType& certificate_type) override;
    int get_leaf_expiry_days_count(const CertificateSigningUseEnum& certificate_type) override;
};

namespace conversions {

/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 GetCertificateSignRequestStatus。
 */
GetCertificateSignRequestStatus to_ocpp(evse_security::GetCertificateSignRequestStatus other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 CaCertificateType。
 */
CaCertificateType to_ocpp(evse_security::CaCertificateType other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 CertificateType。
 */
CertificateType to_ocpp(evse_security::CertificateType other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 HashAlgorithmEnumType。
 */
HashAlgorithmEnumType to_ocpp(evse_security::HashAlgorithm other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 GetCertificateInfoStatus。
 */
GetCertificateInfoStatus to_ocpp(evse_security::GetCertificateInfoStatus other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 InstallCertificateResult。
 */
InstallCertificateResult to_ocpp(evse_security::InstallCertificateResult other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 CertificateValidationResult。
 */
CertificateValidationResult to_ocpp(evse_security::CertificateValidationResult other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 DeleteCertificateResult。
 */
DeleteCertificateResult to_ocpp(evse_security::DeleteCertificateResult other);

/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 CertificateHashDataType。
 */
CertificateHashDataType to_ocpp(evse_security::CertificateHashData other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 CertificateHashDataChain。
 */
CertificateHashDataChain to_ocpp(evse_security::CertificateHashDataChain other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 OCSPRequestData。
 */
OCSPRequestData to_ocpp(evse_security::OCSPRequestData other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 CertificateOCSP。
 */
CertificateOCSP to_ocpp(evse_security::CertificateOCSP other);
/**
 * to_ocpp - to ocpp
 * @other: 传入的 other
 *
 * 返回 CertificateInfo。
 */
CertificateInfo to_ocpp(evse_security::CertificateInfo other);

/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::CaCertificateType。
 */
evse_security::CaCertificateType from_ocpp(CaCertificateType other);
/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::LeafCertificateType。
 */
evse_security::LeafCertificateType from_ocpp(LeafCertificateType other);
/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::LeafCertificateType。
 */
evse_security::LeafCertificateType from_ocpp(CertificateSigningUseEnum other);
/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::CertificateType。
 */
evse_security::CertificateType from_ocpp(CertificateType other);
/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::HashAlgorithm。
 */
evse_security::HashAlgorithm from_ocpp(HashAlgorithmEnumType other);
/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::InstallCertificateResult。
 */
evse_security::InstallCertificateResult from_ocpp(InstallCertificateResult other);
/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::DeleteCertificateResult。
 */
evse_security::DeleteCertificateResult from_ocpp(DeleteCertificateResult other);

/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::CertificateHashData。
 */
evse_security::CertificateHashData from_ocpp(CertificateHashDataType other);
/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::CertificateHashDataChain。
 */
evse_security::CertificateHashDataChain from_ocpp(CertificateHashDataChain other);
/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::OCSPRequestData。
 */
evse_security::OCSPRequestData from_ocpp(OCSPRequestData other);
/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::CertificateOCSP。
 */
evse_security::CertificateOCSP from_ocpp(CertificateOCSP other);
/**
 * from_ocpp - from ocpp
 * @other: 传入的 other
 *
 * 返回 evse_security::CertificateInfo。
 */
evse_security::CertificateInfo from_ocpp(CertificateInfo other);

}; // namespace conversions

} // namespace ocpp

#endif
