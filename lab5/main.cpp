#include <iostream>
#include "Professor.h"
#include "Course.h"

int main() {
    Professor prof("Dr. Alan Turing");
    Course course("Computer Science 101", &prof);
    course.addTopic("Introduction to Turing Machines");

    std::cout << "Course: " << course.getName() << "\n";
    std::cout << "Professor: " << course.getProfessor()->getName() << "\n";

    return 0;
}