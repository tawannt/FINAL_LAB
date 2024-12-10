#include "Book.h"

Book::Book() {
    _title = "";
    _price = 0;
    _link = "";
}

Book::Book(std::string title, float price, std::string link) {
    _title = title;
    _price = price;
    _link = link;
}

std::string Book::title() {
    return _title;
}

float Book::price() {
    return _price;
}

std::string Book::link() {
    return _link;
}

void Book::setTitle(std::string title) {
    _title = title;
}

void Book::setPrice(float price) {
    _price = price;
}

void Book::setLink(std::string link) {
    _link = link;
}

std::string Book::toString() {
    return "Book";
}