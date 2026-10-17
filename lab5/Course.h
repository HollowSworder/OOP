#pragma once
#include <string>
#include <vector>

class Course {
    std::string name_;
    std::vector<std::string> topics_; 
public:
    explicit Course(const std::string& name);
    void addTopic(const std::string& topic);
    const std::string& getName() const;
    const std::vector<std::string>& getTopics() const;
    ~Course() = default;
};