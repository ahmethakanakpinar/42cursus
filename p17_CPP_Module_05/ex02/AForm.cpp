#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) 
{
}

Form::Form(Form const& other) : _name(other._name),
                                _isSigned(other._isSigned), 
                                _gradeToSign(other._gradeToSign), 
                                _gradeToExecute(other._gradeToExecute)
{
}
Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}
Form::~Form() 
{
}
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :  _name(name),
                                                                            _isSigned(false),
                                                                            _gradeToSign(gradeToSign),
                                                                            _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _isSigned;
}
int Form::getGradeToSign() const
{
    return _gradeToSign;
}
int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high, cannot be less than 1";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form){
    out << "Form " << form.getName() << ", " << (form.isSigned() ? "signed" : "not signed") 
      << ", grade to sign: " << form.getGradeToSign() 
      << ", grade to execute: " << form.getGradeToExecute();
    return out;
}