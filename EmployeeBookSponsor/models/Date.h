#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <ctime>

#include "Object.h"


/// @brief Lop doi tuong Date
class Date : public Object {
private:
    int _day;
    int _month;
    int _year;
public:
    Date();
    Date(int day, int month, int year);
    ~Date() = default;

    int day();
    int month();
    int year();

    std::string toString() override;
};

#endif // DATE_H