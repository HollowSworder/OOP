#pragma once
#include "Student.h"

class PaidStudent : public Student {
    int tuition_;
public:
PaidStudent(const std::string& name, int tuition);
    std::string getStatus() const;
    int getTuition() const;
};