#ifndef IPARSABLE_H
#define IPARSABLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <regex>

#include "../../models/Object.h"

/// @brief Interface cho cac lop chuyen doi chuoi thanh doi tuong
class IParsable : public Object {
public:
    /// @brief Chuyen doi chuoi thanh doi tuong
    /// @param info chuoi thong tin
    /// @return con tro toi doi tuong duoc tao ra
    virtual std::shared_ptr<Object> parse(std::string info) = 0;

    std::string toString() override {
        return "IParsable";
    }
    virtual std::string parsedObjectName() = 0;
};

#endif // IPARSABLE_H