#ifndef EMPLOYEEBOOKSPONSOR_SERVICES_BUSINESS_SENIORITYCLASSIFIER_H
#define EMPLOYEEBOOKSPONSOR_SERVICES_BUSINESS_SENIORITYCLASSIFIER_H

#include "../../models/Employee.h"
#include "../../models/Date.h"

enum SeniorityEnum {
    Fresher = 1,
    Junior = 2,
    Senior = 3
};


/// @brief Lop phan loai nhan vien theo do tuoi lam viec
class SeniorityClassifier {
public:
    SeniorityEnum classify(Employee& employee);
};

#endif //EMPLOYEEBOOKSPONSOR_SERVICES_BUSINESS_SENIORITYCLASSIFIER_H

