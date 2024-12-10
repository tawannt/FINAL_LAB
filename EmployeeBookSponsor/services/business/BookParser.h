#ifndef BOOK_PARSER_H
#define BOOK_PARSER_H

#include "IParsable.h"
#include "../../models/Book.h"

/// @brief Parser cho lop Book
class BookParser : public IParsable {
public:
    std::shared_ptr<Object> parse(std::string info) override;
    std::string toString() override;
    std::string parsedObjectName() override;
};

#endif // BOOK_PARSER_H