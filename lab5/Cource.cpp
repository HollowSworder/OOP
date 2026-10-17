#include "Course.h"

Course::Course(const std::string& name) : name_(name) {}

void Course::addTopic(const std::string& topic) {
    topics_.push_back(topic);
}

const std::string& Course::getName() const {
    return name_;
}

const std::vector<std::string>& Course::getTopics() const {
    return topics_;
}