#include <iostream>
#include "Professor.h"
#include "Course.h"
#include "BudgetStudent.h"
#include "PaidStudent.h"

int main() {
    Professor prof("Dr. Ivanov");
    Course c("OOP", &prof);

    BudgetStudent alice("Alice", 1500);
    PaidStudent bob("Bob", 200000);

    c.enrollStudent(&alice);
    c.enrollStudent(&bob);
    c.enrollStudent(&alice); 
    std::cout << c.getName() << " (Prof. " << c.getProfessor()->getName() << ")\n";
    std::cout << "Students: " << c.getStudentCount() << "\n";
    for (const Student* s : c.getStudents()) {
        std::cout << "- " << s->getName() << " (" << s->getStatus() << ")\n";
    }

    return 0;
}