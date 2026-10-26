#pragma once
#include "Student.h"

class BudgetStudent : public Student {
    int scholarship_;
public:
    BudgetStudent(const std::string& name, int scholarship);
    std::string getStatus() const;
    int getScholarship() const;
};