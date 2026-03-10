#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(AForm const& other);
        AForm& operator=(AForm const& other);
        ~AForm();
        
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        virtual void execute(Bureaucrat const & executor) const = 0;
        void beSigned(const Bureaucrat& bureaucrat);
        const std::string& getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

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

std::ostream& operator<<(std::ostream& out, const AForm& Aform);
