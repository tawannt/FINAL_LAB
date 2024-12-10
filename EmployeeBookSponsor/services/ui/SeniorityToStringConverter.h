#ifndef SENIORITYTOSTRINGCONVERTER_H
#define SENIORITYTOSTRINGCONVERTER_H

#include "IConverter.h"
#include "../business/SeniorityClassifier.h"


/// @brief Lop chuyen doi SeniorityEnum sang chuoi
class SeniorityToStringConverter : public IConverter{
public:
    SeniorityToStringConverter();
    ~SeniorityToStringConverter() = default;
    /// @brief Phuong thuc override chuyen doi Object thanh chuoi (khong lam gi)
    /// @param object 
    /// @return Empty string
    std::string convert(Object& object) override;

    /// @brief Phuong thuc chuyen doi SeniorityEnum sang chuoi
    /// @param seniority 
    /// @return Chuoi tuong ung voi SeniorityEnum
    std::string convertToString(SeniorityEnum& seniority);
    std::string toString() override;
};

#endif // SENIORITYTOSTRINGCONVERTER_H