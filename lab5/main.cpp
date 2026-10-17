#include <iostream>
#include "Professor.h"
#include "Course.h"
#include "Student.h"

int main() {
    Professor prof("Dr. Grace Hopper");
    Course course("Software Engineering", &prof);
    course.addTopic("Version Control");

    Student student("Иван");
    student.enroll(&course);
    student.enroll(&course); 

    std::cout << "Student: " << student.getName() << "\n";
    std::cout << "Enrolled courses count: " << student.getCourses().size() << "\n";

    return 0;
}