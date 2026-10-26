#pragma once
class Professor;
class Student;
#include <string>
#include <vector>

class Course {
    std::string name_;
    std::vector<std::string> topics_; 
    Professor* professor_;            
    std::vector<Student*> students_;  

public:
    Course(const std::string& name, Professor* prof);
    ~Course() = default;

    void addTopic(const std::string& topic);
    void enrollStudent(Student* s);

    const std::string& getName() const;
    const std::vector<std::string>& getTopics() const;
    const Professor* getProfessor() const;
    const std::vector<Student*>& getStudents() const;
    int getStudentCount() const;
};