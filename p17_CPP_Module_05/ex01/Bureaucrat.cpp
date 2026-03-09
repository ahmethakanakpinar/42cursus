#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) 
{
    if (this != &other) 
    {
        _grade = other._grade;
    }
    return (*this);
}
Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name){
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;     
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;     
}
void Bureaucrat::signForm(Form &form)
{
    form.beSigned(*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high, cannot be less than 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low, cannot be more than 150";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}