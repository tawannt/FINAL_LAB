#include "SeniorityClassifier.h"

SeniorityEnum SeniorityClassifier::classify(Employee& employee) {
    // Lấy ngày hiện tại
    time_t t = time(0);
    tm* now = localtime(&t);
    int currentMonth = now->tm_mon + 1; // tm_mon tính từ 0 -> 11
    int currentYear = now->tm_year + 1900;
    Date startDate = employee.startDate();

    // Tính toán số năm làm việc
    int yearsOfExperience = currentYear - startDate.year();
    if (currentMonth < startDate.month()) {
        yearsOfExperience -= 1; // Chưa đủ 1 năm nếu chưa tới tháng bắt đầu
    }

    // Phân loại dựa trên số năm làm việc
    if (yearsOfExperience < 1) {
        return Fresher;
    } else if (yearsOfExperience < 2) {
        return Junior;
    } else {
        return Senior;
    }
}