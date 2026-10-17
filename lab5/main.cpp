#include <iostream>
#include "Course.h"

int main() {
    Course course("Algorithms and Data Structures");
    course.addTopic("Binary Search Trees");
    course.addTopic("Graph Theory");

    std::cout << "Course: " << course.getName() << "\n";
    std::cout << "Topics count: " << course.getTopics().size() << "\n";

    return 0;
}