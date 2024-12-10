#ifndef PARSER_FACTORY_H
#define PARSER_FACTORY_H

#include <string>
#include <map>


#include "../../models/Object.h"
#include "IParsable.h"
#include "EmployeeParser.h"
#include "BookParser.h"

/// @brief Factory cho cac lop chuyen doi chuoi thanh doi tuong
class ParserFactory : public Object {
private:
    /// @brief Dang ky cac dich vu can lay
    static void _config();
public:
    std::string toString() override;
public:
    /// @brief Luu ten dich vu ung voi doi tuong dich vu can lay, vi du: dich vu IdeaParser
    inline static std::map<std::string, std::shared_ptr<Object>> _servicesForType;
    static void registerWith(std::shared_ptr<Object> service);
    static std::shared_ptr<Object> getServiceForType(std::string type);
};

#endif // PARSER_FACTORY_H