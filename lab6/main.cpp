#include <iostream>
#include "Student.h"

int main() {
    Student baseStudent("Иван");

    std::cout << "Name: " << baseStudent.getName() << "\n";
    std::cout << "Status: " << baseStudent.getStatus() << "\n";
    std::cout << "Tuition: " << baseStudent.getTuition() << "\n";

    return 0;
}