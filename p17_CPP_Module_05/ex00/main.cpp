#include "Bureaucrat.hpp"

int main()
{
    std::cout << "--- TEST 1: Normal Creation and << Operator ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 75);
        std::cout << alice << std::endl;
        
        alice.incrementGrade(); // 75 -> 74
        std::cout << "Incremented: " << alice << std::endl;
        
        alice.decrementGrade(); // 74 -> 75
        std::cout << "Decremented: " << alice << std::endl;
    } 
    catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Creation with Too High Grade (< 1) ---" << std::endl;
    try {
        Bureaucrat zeus("Zeus", 0);
    } 
    catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Creation with Too Low Grade (> 150) ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 151);
    } 
    catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: Incrementing Grade Above Limit (1 -> 0) ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;
        boss.incrementGrade(); // Should throw an exception here
        std::cout << "This text should not be printed!" << std::endl;
    } 
    catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 5: Decrementing Grade Below Limit (150 -> 151) ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        std::cout << intern << std::endl;
        intern.decrementGrade(); // Should throw an exception here
        std::cout << "This text should not be printed!" << std::endl;
    } 
    catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    return 0;
}