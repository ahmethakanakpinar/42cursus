#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(Form const &other);
        Form& operator=(Form const &other);
        ~Form();

        void beSigned(const Bureaucrat &bureaucrat);

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& o, const Form& form);
