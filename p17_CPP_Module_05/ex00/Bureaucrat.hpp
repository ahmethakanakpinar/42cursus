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

    private:
        const std::string _name;
        int _grade;
};
