#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

static void testFormLifecycle(AForm* form, Bureaucrat& signer, Bureaucrat& executor)
{
    if (!form)
        return;

    std::cout << *form << std::endl;
    signer.signForm(*form);
    executor.executeForm(*form);
    delete form;
}

int main()
{
    std::srand(std::time(NULL));

    Intern someRandomIntern;
    Bureaucrat manager("Manager", 1);
    Bureaucrat assistant("Assistant", 140);

    std::cout << "--- TEST 1: Robotomy form creation from intern ---" << std::endl;
    AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
    testFormLifecycle(robotomy, manager, manager);

    std::cout << "\n--- TEST 2: Shrubbery with low executor (should fail execute) ---" << std::endl;
    AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "Home");
    testFormLifecycle(shrubbery, assistant, assistant);

    std::cout << "\n--- TEST 3: Presidential pardon form creation ---" << std::endl;
    AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    testFormLifecycle(pardon, manager, manager);

    std::cout << "\n--- TEST 4: Unknown form name ---" << std::endl;
    AForm* unknown = someRandomIntern.makeForm("coffee form", "Nobody");
    if (unknown)
        delete unknown;

    return 0;
}