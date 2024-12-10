#include "Proposal.h"

Proposal::Proposal() {
    _employee = std::shared_ptr<Employee>();
    _book = std::shared_ptr<Book>();
}

Proposal::Proposal(std::shared_ptr<Employee> employee, std::shared_ptr<Book> book) {
    this->_employee = employee;
    this->_book = book;
}

std::shared_ptr<Employee> Proposal::getEmployee() {
    return _employee;
}

std::shared_ptr<Book> Proposal::getBook() {
    return _book;
}

void Proposal::setEmployee(std::shared_ptr<Employee> employee) {
    _employee = employee;
}

void Proposal::setBook(std::shared_ptr<Book> book) {
    _book = book;
}

std::string Proposal::toString() {
    return "Proposal";
}