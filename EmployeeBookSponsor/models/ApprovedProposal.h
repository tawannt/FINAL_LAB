#ifndef APPROVEDPROPOSAL_H
#define APPROVEDPROPOSAL_H

#include <string>

#include "Proposal.h"

/// @brief Lop doi tuong De xuat mua sach da duoc duyet
class ApprovedProposal : public Proposal {
private:
    float _originalPrice;
    float _sponsorPercent;
    float _sponsorAmount;
public:
    ApprovedProposal();
    ApprovedProposal(float originalPrice, float sponsorPercent, float sponsorAmount);
    ~ApprovedProposal() = default;

    /// @brief Getter
    float OriginalPrice();
    float SponsorAmount();
    float SponsorPercent();

    /// @brief Setter
    void setOriginalPrice(float originalPrice);
    void setSponsorPercent(float sponsorPercent);
    void setSponsorAmount(float sponsorAmount);

    std::string toString() override;
};

#endif // APPROVEDPROPOSAL_H