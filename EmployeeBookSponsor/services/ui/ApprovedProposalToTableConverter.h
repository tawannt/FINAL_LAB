#ifndef APPROVEDPROPOSALTOTABLECONVERTER_H
#define APPROVEDPROPOSALTOTABLECONVERTER_H


#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <iostream>


#include "IConverter.h"
#include "CurrencyFormatter.h"
#include "SeniorityToStringConverter.h"
#include "../../models/ApprovedProposal.h"
#include "../business/SeniorityClassifier.h"


/// @brief Lop chuyen doi ApprovedProposal sang bang
class ApprovedProposalToTableConverter : public IConverter {
private:
    /// @brief Danh sach headers
    std::vector<std::string> _headers;
    /// @brief Danh sach kich thuoc
    std::vector<int> _columnSizes;
public:
    ApprovedProposalToTableConverter();
    ~ApprovedProposalToTableConverter() = default;
    ApprovedProposalToTableConverter(std::vector<std::string>& headers, std::vector<int>& columnSizes);

    /// @brief Phuong thuc chuyen doi danh sach ApprovedProposal sang bang (dang chuoi)
    /// @param os 
    /// @param intro 
    /// @return Chuoi bang
    std::string convertToTable(std::vector<std::shared_ptr<Object>>& os, std::string intro);

    /// @brief Ham override chuyen doi Object thanh chuoi (khong lam gi)
    /// @param object 
    /// @return Empty string
    std::string convert(Object& object) override;
    std::string toString() override;
protected:
    class ApprovedProposalToRowConverter {
    private:
        std::vector<int> _columnSizes;
    public:
        ApprovedProposalToRowConverter(std::vector<int>& columnSizes);

        /// @brief Ham chuyen doi Object thanh dong trong bang
        /// @param o 
        /// @return Chuoi dong
        std::string convert(std::shared_ptr<Object>& o) const;
    };
};

#endif // APPROVEDPROPOSALTOTABLECONVERTER_H