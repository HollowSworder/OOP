#include "BudgetStudent.h"

BudgetStudent::BudgetStudent(const std::string& name, int scholarship)
    : Student(name), scholarship_(scholarship) {}

std::string BudgetStudent::getStatus() const {
    return "Budget";
}

int BudgetStudent::getScholarship() const {
    return scholarship_;
}