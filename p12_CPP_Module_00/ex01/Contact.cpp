/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar < aakpinar@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 04:59:09 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/02 05:00:22 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

Contact::Contact()
{

}

Contact::~Contact()
{

}

std::string Contact::getFirstName() const
{
    return (this->_firstName);
}

std::string Contact::getLastName() const
{
    return (this->_lastName);
}

std::string Contact::getNickname() const
{
    return (this->_nickname);
}

std::string Contact::getPhoneNumber() const
{
    return (this->_phoneNumber);
}

std::string Contact::getSecret() const
{
    return (this->_secret);
}

void Contact::setFirstName(const std::string& firstName)
{
    this->_firstName = firstName;
}
void Contact::setLastName(const std::string& lastName)
{
    this->_lastName = lastName;
}

void Contact::setNickname(const std::string& nickname)
{
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

void Contact::setSecret(const std::string& secret)
{
    this->_secret = secret;
}

// Helper method to get valid (non-empty) input from user
std::string Contact::getValidInput(const std::string& prompt)
{
    std::string input;
    
    while (true)
    {
        std::cout << CYAN << prompt << RESET;
        std::getline(std::cin, input);
        
        if (std::cin.eof())
        {
            std::cout << RED << "\nInput interrupted!" << RESET << std::endl;
            exit(1);
        }
        
        // Remove leading/trailing whitespace manually
        size_t start = 0;
        size_t end = input.length();
        
        while (start < end && std::isspace(input[start]))
            start++;
        while (end > start && std::isspace(input[end - 1]))
            end--;
            
        input = input.substr(start, end - start);
        
        if (!input.empty())
            return input;
            
        std::cout << RED << "Field cannot be empty! Please try again." << RESET << std::endl;
    }
}

// Static factory method to create a Contact from user input
Contact Contact::createFromInput()
{
    Contact contact;
    
    std::cout << GREEN << "\n=== Adding New Contact ===" << RESET << std::endl;
    
    contact.setFirstName(getValidInput("First Name: "));
    contact.setLastName(getValidInput("Last Name: "));
    contact.setNickname(getValidInput("Nickname: "));
    contact.setPhoneNumber(getValidInput("Phone Number: "));
    contact.setSecret(getValidInput("Darkest Secret: "));
    
    return contact;
}