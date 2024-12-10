#include "BookParser.h"

std::shared_ptr<Object> BookParser::parse(std::string info) {
    std::string title, link;
    float price;
    std::istringstream iss(info);
    iss >> title >> price >> link;
    return std::make_shared<Book>(title, price, link);
}

std::string BookParser::toString() {
    return "BookParser";
}

std::string BookParser::parsedObjectName() {
    return "Book";
}