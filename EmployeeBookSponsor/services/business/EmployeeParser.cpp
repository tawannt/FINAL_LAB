#include "EmployeeParser.h"

std::shared_ptr<Object> EmployeeParser::parse(std::string info) {
    std::string name, email;
    int day, month, year;
    std::regex pattern("Employee: Name=([A-Za-z\\s]+), Email=([\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}), StartDate=(\\d+)/(\\d+)/(\\d+)");
    std::smatch matches;
    if (!std::regex_match(info, matches, pattern)) {
        return nullptr;
    }
    name = matches[1];
    email = matches[2];
    day = std::stoi(matches[3]);
    month = std::stoi(matches[4]);
    year = std::stoi(matches[5]);
    Date startDate(day, month, year);
    return std::make_shared<Employee>(name, email, startDate);
}

std::string EmployeeParser::toString() {
    return "EmployeeParser";
}

std::string EmployeeParser::parsedObjectName() {
    return "Employee";
}