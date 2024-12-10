#ifndef REAL_DAO_H
#define REAL_DAO_H

#include "IDao.h"

/// @brief Lớp truy cập dữ liệu từ file text
class RealDao: public IDao {
public:
    RealDao() = default;
    ~RealDao() = default;
    /// @brief Lấy danh sách các đối tượng hình học đang được lưu trữ trong file text
    /// @return Mảng các đối tượng Proposal
    std::vector<std::shared_ptr<Proposal>> getAll() override;
private:
    /// @brief Trích xuất từ đầu tiên của dòng
    std::string _firstWord(std::string line);
};

#endif // REAL_DAO_H