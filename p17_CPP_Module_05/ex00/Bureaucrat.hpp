#pragma once

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
    
        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();

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
