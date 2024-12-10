#ifndef MOCKDAO_H
#define MOCKDAO_H

#include <vector>
#include <memory>

#include "IDao.h"
#include "../../models/Proposal.h"
#include "../../models/Date.h"
#include "../ui/StringToDateConverter.h"

/// @brief Lớp truy cap du lieu gia
class MockDao : public IDao {
public:
    MockDao() = default;
    ~MockDao() = default;

    std::vector<std::shared_ptr<Proposal>> getAll() override;
};

#endif // MOCKDAO_H