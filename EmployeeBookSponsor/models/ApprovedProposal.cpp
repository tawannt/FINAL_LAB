#include "ApprovedProposal.h"

ApprovedProposal::ApprovedProposal() {
    _originalPrice = 0;
    _sponsorPercent = 0;
    _sponsorAmount = 0;
}

ApprovedProposal::ApprovedProposal(float originalPrice, float sponsorPercent, float sponsorAmount) {
    _originalPrice = originalPrice;
    _sponsorPercent = sponsorPercent;
    _sponsorAmount = sponsorAmount;
}

float ApprovedProposal::OriginalPrice() {
    return _originalPrice;
}

float ApprovedProposal::SponsorAmount() {
    return _sponsorAmount;
}

float ApprovedProposal::SponsorPercent() {
    return _sponsorPercent;
}

void ApprovedProposal::setOriginalPrice(float originalPrice) {
    _originalPrice = originalPrice;
}

void ApprovedProposal::setSponsorPercent(float sponsorPercent) {
    _sponsorPercent = sponsorPercent;
}

void ApprovedProposal::setSponsorAmount(float sponsorAmount) {
    _sponsorAmount = sponsorAmount;
}

std::string ApprovedProposal::toString() {
    return "ApprovedProposal";
}