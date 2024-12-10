#ifndef SPONSORCONSULTER_H
#define SPONSORCONSULTER_H

#include <vector>

#include "SeniorityClassifier.h"
#include "../../models/Proposal.h"
#include "../../models/ApprovedProposal.h"


/// @brief Lop doi tuong tu van de xuat thong tin tai tro cho kieu Seniority
class SponsorConsulter {
public:
    SponsorConsulter() = default;
    ~SponsorConsulter() = default;
    /// @brief Phuong thuc chuyen doi cac Proposal thanh ApprovedProposal
    /// @param proposals Danh sach cac de xuat
    /// @return Danh sach cac de xuat da duoc duyet
    std::vector<std::shared_ptr<ApprovedProposal>> endorse(std::vector<std::shared_ptr<Proposal>> proposals);
};

#endif // SPONSORCONSULTER_H