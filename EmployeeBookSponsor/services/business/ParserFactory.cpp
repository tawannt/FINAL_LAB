#include "ParserFactory.h"

void ParserFactory::_config() {
    registerWith(std::make_shared<EmployeeParser>());
    registerWith(std::make_shared<BookParser>());
    // registerWith(new ProposalParser());
}

std::string ParserFactory::toString() {
    return "ParserFactory";
}

void ParserFactory::registerWith(std::shared_ptr<Object> service) {
    _servicesForType.insert({dynamic_pointer_cast<IParsable>(service)->parsedObjectName(), service});
}

std::shared_ptr<Object> ParserFactory::getServiceForType(std::string type) {
    if (_servicesForType.size() == 0){
        _config();
    }
    return _servicesForType[type];
}