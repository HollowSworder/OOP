#include <iostream>
#include <vector>
#include "Professor.h"
#include "Course.h"
#include "Student.h"
#include "BudgetStudent.h"
#include "PaidStudent.h"

class ForeignStudent : public Student {
    std::string country_;
public:
    ForeignStudent(const std::string& name, const std::string& country)
        : Student(name), country_(country) {}

    std::string getStatus() const { return "Foreign"; } 
    int getTuition() const { return 300000; } 
    const std::string& getCountry() const { return country_; }
};

int main() {
    Professor prof1("Dr. Ivanov");
    Professor prof2("Dr. Petrova");

    Course c1("OOP", &prof1);
    Course c2("Math", &prof2);
    Course c3("Physics", &prof1);

    c1.addTopic("Classes and objects");
    c1.addTopic("Constructors");
    c1.addTopic("Rule of three");

    c2.addTopic("Limits");
    c2.addTopic("Derivatives");

    c3.addTopic("Mechanics");
    c3.addTopic("Thermodynamics");
    c3.addTopic("Electromagnetism");

    BudgetStudent alice("Alice", 1500);
    PaidStudent bob("Bob", 200000);
    BudgetStudent gleb("Gleb", 1200);
    ForeignStudent john("John", "USA"); 

    alice.enroll(&c1);
    c1.enrollStudent(&alice);
    alice.enroll(&c2);
    c2.enrollStudent(&alice);
    alice.enroll(&c1); 

    bob.enroll(&c3);
    c3.enrollStudent(&bob);

    gleb.enroll(&c1);
    c1.enrollStudent(&gleb);
    gleb.enroll(&c3);
    c3.enrollStudent(&gleb);

    john.enroll(&c1);
    c1.enrollStudent(&john);

    std::cout << "Students\n";
    
    std::cout << alice.getName() << " (" << alice.getStatus() << "), tuition: " << alice.getTuition() 
              << ", scholarship: " << alice.getScholarship() << "\n";
    for (Course* crs : alice.getCourses()) {
        std::cout << crs->getName() << " (Prof. " << crs->getProfessor()->getName() << ")\n";
    }

    std::cout << bob.getName() << " (" << bob.getStatus() << "), tuition: " << bob.getTuition() 
              << ", scholarship: 0\n";
    for (Course* crs : bob.getCourses()) {
        std::cout << crs->getName() << " (Prof. " << crs->getProfessor()->getName() << ")\n";
    }

    std::cout << gleb.getName() << " (" << gleb.getStatus() << "), tuition: " << gleb.getTuition() 
              << ", scholarship: " << gleb.getScholarship() << "\n";
    for (Course* crs : gleb.getCourses()) {
        std::cout << crs->getName() << " (Prof. " << crs->getProfessor()->getName() << ")\n";
    }

    std::cout << john.getName() << " (" << john.getStatus() << "), tuition: " << john.getTuition() 
              << ", scholarship: 0\n";
    for (Course* crs : john.getCourses()) {
        std::cout << crs->getName() << " (Prof. " << crs->getProfessor()->getName() << ")\n";
    }

    std::cout << "\nCourses\n";
    Course* coursesList[] = {&c1, &c2, &c3};
    for (Course* crs : coursesList) {
        std::cout << crs->getName() << " (Prof. " << crs->getProfessor()->getName() << ")\n";
        std::cout << "Topics: " << crs->getTopics().size() << "\n";
        for (const auto& topic : crs->getTopics()) {
            std::cout << "- " << topic << "\n";
        }
        std::cout << "Students: " << crs->getStudentCount() << "\n";
        for (const Student* st : crs->getStudents()) {
            std::cout << "- " << st->getName() << "\n";
        }
        std::cout << "\n";
    }

    int totalTuition = bob.getTuition() + john.getTuition();
    std::cout << "Summary\n";
    std::cout << "Total tuition: " << totalTuition << "\n";

    return 0;
}