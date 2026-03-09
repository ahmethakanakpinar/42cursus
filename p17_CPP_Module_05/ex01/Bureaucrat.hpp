#pragma once

#include <iostream>
#include "Form.hpp"
class Form;

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
    
        Bureaucrat(const std::string &name, int grade);
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

        void signForm(Form &form);


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
        int _grade;
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);
