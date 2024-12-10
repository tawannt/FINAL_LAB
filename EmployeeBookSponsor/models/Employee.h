#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "Object.h"
#include "Date.h"

/// @brief Lop doi tuong Nhan vien trong cong ty
class Employee : public Object {
private:
    std::string _name;
    std::string _email;
    Date _startDate;
public:
    Employee();
    Employee(std::string name, std::string email, Date startDate);
    ~Employee() = default;

    std::string name();
    std::string email();
    Date startDate();

    std::string toString() override;
};

#endif // EMPLOYEE_H