#include "Employee.h"

Employee::Employee() {
    _name = "";
    _email = "";
    _startDate = Date();
}

Employee::Employee(std::string name, std::string email, Date startDate) {
    _name = name;
    _email = email;
    _startDate = startDate;
}

std::string Employee::name() {
    return _name;
}

std::string Employee::email() {
    return _email;
}

Date Employee::startDate() {
    return _startDate;
}

std::string Employee::toString() {
    return "Employee";
}