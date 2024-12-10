#ifndef OBJECT_H
#define OBJECT_H
#include <string>
#include <format>
#include <memory>
#include <iostream>


/// @brief Lop co so cho cac lop doi tuong
class Object {
public:
    /// @brief Bieu dien doi tuong duoi dang chuoi
    /// @return chuoi mo ta doi tuong
    virtual std::string toString() = 0;
    ~Object() = default;
};

#endif // OBJECT_H