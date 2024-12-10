#include "Date.h"

Date::Date(){
    _day = 1;
    _month = 1;
    _year = 1;
}

Date::Date(int day, int month, int year){
    _day = day;
    _month = month;
    _year = year;
}

int Date::day(){
    return _day;
}

int Date::month(){
    return _month;
}

int Date::year(){
    return _year;
}

std::string Date::toString(){
    return "Date";
}