#ifndef ICONVERTER_H
#define ICONVERTER_H

#include "../../models/Object.h"


// TODO:convert Object to Object, but to do it we need to wrapper
/// @brief Interface chuyen doi doi tuong thanh chuoi
class IConverter : public Object {
public:
    virtual ~IConverter() = default;
    
public:
    virtual std::string convert(Object& object) = 0;

    std::string toString() override {
        return "IConverter";
    }
};

#endif // ICONVERTER_H