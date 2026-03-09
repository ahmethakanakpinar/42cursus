#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "--- TEST 1: Form Creation and << Operator ---" << std::endl;
    try {
        Form taxForm("TaxForm", 50, 20);
        std::cout << taxForm << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Form Creation with Invalid Grades ---" << std::endl;
    try {
        Form invalidForm("Invalid", 0, 50); // 0 is too high
    } catch (std::exception &e) {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Successful Signing ---" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        Form contract("Contract", 10, 5); // Needs 10 to sign
        
        std::cout << contract << std::endl;
        boss.signForm(contract); // Boss is grade 1, should succeed
        std::cout << contract << std::endl; // Status should be signed
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: Unsuccessful Signing (Grade Too Low) ---" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        Form topSecret("TopSecret", 1, 1); // Needs 1 to sign
        
        intern.signForm(topSecret); // Intern is 150, should fail and print reason
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}