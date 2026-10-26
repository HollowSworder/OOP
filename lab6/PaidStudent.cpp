#include "PaidStudent.h"

PaidStudent::PaidStudent(const std::string& name, int tuition)
    : Student(name), tuition_(tuition) {}

std::string PaidStudent::getStatus() const {
    return "Paid";
}

int PaidStudent::getTuition() const {
    return tuition_;
}