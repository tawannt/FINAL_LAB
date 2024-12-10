#ifndef BOOK_H
#define BOOK_H

#include <string>

#include "Object.h"

/// @brief Lop doi tuong Sach
class Book : public Object {
private:
    std::string _title;
    float _price;
    std::string _link;
public:
    Book();
    Book(std::string title, float price, std::string link);
    ~Book() = default;

    std::string title();
    float price();
    std::string link();

    void setTitle(std::string title);
    void setPrice(float price);
    void setLink(std::string link);

    std::string toString();
};

#endif // BOOK_H