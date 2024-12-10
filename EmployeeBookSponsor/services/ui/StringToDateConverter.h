#ifndef STRINGTODATECONVERTER_H
#define STRINGTODATECONVERTER_H

#include <string>
#include <vector>
#include <sstream>
#include "IConverter.h"
#include "../../models/Date.h"

/// @brief Lop chuyen doi chuoi sang ngay
class StringToDateConverter : public IConverter {
public:
    StringToDateConverter();
    ~StringToDateConverter() = default;

    /// @brief Phuong thuc override chuyen doi Object thanh chuoi (khong lam gi)
    std::string convert(Object& object) override;

    /// @brief Phuong thuc chuyen doi chuoi thanh ngay
    /// @param dateStr 
    /// @return Date
    Date convert(const std::string& dateStr);
    std::string toString() override;
};

#endif // STRINGTODATECONVERTER_H