#ifndef IDAO_H
#define IDAO_H

#include <vector>


#include "../../models/Object.h"
#include "../../models/Proposal.h"

/// @brief Giao dien cho cac lop truy xuat du lieu
class IDao {
public:
    /// @brief Lay danh sach cac doi tuong Proposal can luu tru
    /// @return Mang cac doi tuong Proposal
    virtual std::vector<std::shared_ptr<Proposal>> getAll() = 0;
};

#endif // IDAO_H