#include <iostream>
#include <vector>
#include "Professor.h"
#include "Course.h"
#include "Student.h"

int main() {
    std::vector<Professor> professors;
    professors.emplace_back("Dr. Alan Turing");
    professors.emplace_back("Dr. Grace Hopper");

    Course c1("Computer Science", &professors[0]);
    c1.addTopic("Turing Machines");
    c1.addTopic("Computability");

    Course c2("Software Engineering", &professors[1]);
    c2.addTopic("Compilers");
    c2.addTopic("Debugging");

    Student student("Иван");
    student.enroll(&c1);
    student.enroll(&c2);
    student.enroll(&c1); 

    std::cout << "Professors & Courses\n";
    std::cout << "1. Professor: " << c1.getProfessor()->getName() << " | Course: " << c1.getName() << "\n";
    std::cout << "2. Professor: " << c2.getProfessor()->getName() << " | Course: " << c2.getName() << "\n\n";

    std::cout << "Student Info\n";
    std::cout << "Student name: " << student.getName() << "\n";
    std::cout << "Enrolled courses:\n";
    for (const Course* coursePtr : student.getCourses()) {
        std::cout << " - " << coursePtr->getName() << " (Topics: " << coursePtr->getTopics().size() << ")\n";
    }

    return 0;
}