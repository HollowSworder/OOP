#include "Course.h"
#include "Professor.h"
#include "Student.h"

Course::Course(const std::string& name, Professor* prof)
    : name_(name), professor_(prof) {}

void Course::addTopic(const std::string& topic) {
    topics_.push_back(topic);
}

void Course::enrollStudent(Student* s) {
    if (s == nullptr) return;
    for (Student* existing : students_) {
        if (existing == s) return; 
    }
    students_.push_back(s);
}

const std::string& Course::getName() const {
    return name_;
}

const std::vector<std::string>& Course::getTopics() const {
    return topics_;
}

const Professor* Course::getProfessor() const {
    return professor_;
}

const std::vector<Student*>& Course::getStudents() const {
    return students_;
}

int Course::getStudentCount() const {
    return static_cast<int>(students_.size());
}