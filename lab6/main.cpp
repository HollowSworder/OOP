#include <iostream>
#include "Student.h"
#include "BudgetStudent.h"
#include "PaidStudent.h"

int main() {
    BudgetStudent alice("Alice", 1500);
    PaidStudent bob("Bob", 200000);

    std::cout << alice.getName() << " (" << alice.getStatus()
              << "), tuition: " << alice.getTuition()
              << ", scholarship: " << alice.getScholarship() << "\n";

    std::cout << bob.getName() << " (" << bob.getStatus()
              << "), tuition: " << bob.getTuition() << "\n";

    return 0;
}