#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    void execute(const Bureaucrat& executor) const;

private:
    std::string _target;
};