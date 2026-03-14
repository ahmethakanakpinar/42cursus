#pragma once

#include <string>
#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm* makeForm(const std::string& formName, const std::string& target) const;

	private:
		typedef AForm* (Intern::*FormCreator)(const std::string& target) const;

		AForm* makeShrubberyCreationForm(const std::string& target) const;
		AForm* makeRobotomyRequestForm(const std::string& target) const;
		AForm* makePresidentialPardonForm(const std::string& target) const;
};
