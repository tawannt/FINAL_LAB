#ifndef EMPLOYEE_PARSER_H
#define EMPLOYEE_PARSER_H

#include "IParsable.h"
#include "../../models/Employee.h"

/// @brief Parser cho lop Employee
class EmployeeParser : public IParsable {
public:
    std::shared_ptr<Object> parse(std::string info) override;
    std::string toString() override;
    std::string parsedObjectName() override;
};

#endif // EMPLOYEE_PARSER_H