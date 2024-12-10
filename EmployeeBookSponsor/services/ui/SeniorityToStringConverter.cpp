#include "SeniorityToStringConverter.h"

SeniorityToStringConverter::SeniorityToStringConverter() {
    // Do nothing
}

std::string SeniorityToStringConverter::convert(Object& object) {
    // do nothing
    return "";
}

std::string SeniorityToStringConverter::convertToString(SeniorityEnum& seniority) {
    switch (seniority) {
        case Fresher:
            return "Fresher";
        case Junior:
            return "Junior";
        case Senior:
            return "Senior";
        default:
            return "Unknown";
    }
}

std::string SeniorityToStringConverter::toString() {
    return "SeniorityToStringConverter";
}