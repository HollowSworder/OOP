#pragma once
class Course;
#include <string>
#include <vector>

class Student {
protected:
    std::string name_;
    std::vector<Course*> courses_;

public:
    explicit Student(const std::string& name);
    virtual ~Student() = default;

    void enroll(Course* c);
    const std::string& getName() const;
    const std::vector<Course*>& getCourses() const;
    int getCourseCount() const;

    std::string getStatus() const;
    int getTuition() const;
};