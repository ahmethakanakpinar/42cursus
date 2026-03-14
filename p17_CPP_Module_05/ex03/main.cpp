#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(NULL));

    std::cout << "--- TEST 1: ShrubberyCreationForm ---" << std::endl;
    {
        Bureaucrat gardener("Gardener", 130);
        ShrubberyCreationForm tree("Garden");

        std::cout << tree << std::endl;
        gardener.executeForm(tree);  // Should fail: form not signed
        gardener.signForm(tree);
        std::cout << tree << std::endl;
        gardener.executeForm(tree);  // Should succeed and create file
    }

    std::cout << "\n--- TEST 2: RobotomyRequestForm (50% Chance) ---" << std::endl;
    {
        Bureaucrat doctor("Doctor", 40);
        RobotomyRequestForm bender("Bender");

        doctor.signForm(bender);
        doctor.executeForm(bender);
        doctor.executeForm(bender);
        doctor.executeForm(bender);
    }

    std::cout << "\n--- TEST 3: PresidentialPardonForm (Insufficient Grade) ---" << std::endl;
    {
        Bureaucrat intern("Intern", 20);
        PresidentialPardonForm criminal("Arthur Dent");

        intern.signForm(criminal);     // Should succeed (grade 20 <= 25)
        intern.executeForm(criminal);  // Should fail (grade 20 > 5)
    }

    std::cout << "\n--- TEST 4: PresidentialPardonForm (Success) ---" << std::endl;
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm criminal("Ford Prefect");

        president.signForm(criminal);
        president.executeForm(criminal);
    }

    std::cout << "\n--- TEST 5: Grade Too Low to Sign ---" << std::endl;
    {
        Bureaucrat nobody("Nobody", 150);
        ShrubberyCreationForm tree("Park");

        nobody.signForm(tree);  // Should fail: grade 150 > required 145
    }

    std::cout << "\n--- TEST 6: Bureaucrat Grade Boundaries ---" << std::endl;
    {
        try {
            Bureaucrat tooHigh("TooHigh", 0);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        try {
            Bureaucrat tooLow("TooLow", 151);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0;
}