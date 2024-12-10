#include "MockDao.h"


std::vector<std::shared_ptr<Proposal>> MockDao::getAll() {
    std::vector<std::shared_ptr<Proposal>> proposals;

    // Employee: Do Minh Long
    StringToDateConverter converter;
    std::string date = "05/07/2023";
    Date d = converter.convert(date);
    auto employee1 = std::make_shared<Employee>("Do Minh Long", "dmlong@gmail.com", d);
    auto book1 = std::make_shared<Book>("Clean architecture with .Net Core", 60.69, "www.amazon.com?id=11512");
    auto proposal1 = std::make_shared<Proposal>(employee1, book1);
    proposals.push_back(proposal1);

    // Employee: Tran Bao Tuan
    date = "12/06/2022";
    d = converter.convert(date);
    auto employee2 = std::make_shared<Employee>("Tran Bao Tuan", "tbtuan@gmail.com", d);
    auto book2 = std::make_shared<Book>("The Pragmatic Programmer: From Journeyman to Master", 55.17, "www.amazon.com?id=11459");
    auto proposal2 = std::make_shared<Proposal>(employee2, book2);
    proposals.push_back(proposal2);

    // Employee: Cao Hoang Thien
    date = "12/06/2021";
    d = converter.convert(date);
    auto employee3 = std::make_shared<Employee>("Cao Hoang Thien", "chthien@gmail.com", d);
    auto book3 = std::make_shared<Book>("Design Patterns: Elements of Reusable Object-Oriented Software", 58.29, "www.amazon.com?id=66821");
    auto proposal3 = std::make_shared<Proposal>(employee3, book3);
    proposals.push_back(proposal3);

    return proposals;
}