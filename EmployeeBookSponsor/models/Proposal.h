#ifndef PROPOSAL_H
#define PROPOSAL_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

#include "Object.h"
#include "Book.h"
#include "Employee.h"


/// @brief Lop doi tuong De xuat mua sach
class Proposal : public Object {
private:
    /// @brief Cac nhan vien de xuat
    std::shared_ptr<Employee> _employee;

    /// @brief Danh sach cac cuon sach de xuat
    std::shared_ptr<Book> _book;
public:
    Proposal();
    Proposal(std::shared_ptr<Employee> employee, std::shared_ptr<Book> book);
    ~Proposal() = default;

    /// @brief Getter 
    std::shared_ptr<Employee> getEmployee();
    std::shared_ptr<Book> getBook();

    /// @brief Setter
    void setEmployee(std::shared_ptr<Employee> employee);
    void setBook(std::shared_ptr<Book> book);

    std::string toString() override;
};

#endif // PROPOSAL_H