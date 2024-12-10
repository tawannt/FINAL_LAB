#include "StringToDateConverter.h"

StringToDateConverter::StringToDateConverter() {
    // Do nothing
}

std::string StringToDateConverter::convert(Object& object) {
    // Do nothing
    return "";
}

Date StringToDateConverter::convert(const std::string& dateStr) {
    std::vector<int> dateParts;
    std::stringstream ss(dateStr);
    std::string part;

    while (std::getline(ss, part, '/')) {
        dateParts.push_back(std::stoi(part));
    }

    if (dateParts.size() != 3) {
        throw std::invalid_argument("Invalid date format");
    }

    int day = dateParts[0];
    int month = dateParts[1];
    int year = dateParts[2];

    return Date(day, month, year);
}

std::string StringToDateConverter::toString() {
    return "StringToDateConverter";
}