/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 04:42:47 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/04 00:00:18 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : count(0), oldestIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}
void PhoneBook::addContact()
{
    Contact newContact = Contact::createFromInput();
    
    this->contacts[this->oldestIndex] = newContact;
    
    if (this->count < 8)
        this->count++;

    this->oldestIndex = (this->oldestIndex + 1) % 8;

    std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;  
}

void PhoneBook::searchContacts()
{
    if (this->count == 0)
    {
        std::cout << RED << "No contacts available to search." << RESET << std::endl;
        return;
    }
    displayAllContacts();

    std::string input;
    int index;

    while (true)
    {
        std::cout << "\nEnter the index of your Search (1 = oldest): ";
        std::getline(std::cin, input);

        if (std::cin.eof())
        {
            std::cout << RED << "\nSearch interrupted!" << RESET << std::endl;
            return;
        }

        // Check if input is empty
        if (input.empty())
        {
            std::cout << RED << "Please enter a valid index." << RESET << std::endl;
            continue;
        }

        // Check if all characters are digits
        bool isNumber = true;
        for (size_t i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {
                isNumber = false;
                break;
            }
        }

        if (!isNumber)
        {
            std::cout << RED << "Invalid input. Please enter a number." << RESET << std::endl;
            continue;
        }

        index = std::atoi(input.c_str());

        if (index < 1 || index > this->count)
        {
            std::cout << RED << "Invalid index! Please enter a number between 1 and " 
                      << this->count << "." << RESET << std::endl;
            continue;
        }
        
        displayContactDetails(index - 1);
        return;
    }

  
}

void PhoneBook::displayAllContacts() const
{
    if (this->count == 0)
    {
        std::cout << RED << "No contacts to display." << RESET << std::endl;
        return;
    }

    std::cout << "\n" << CYAN << "---------------------------------------------" << RESET << std::endl;
    std::cout << CYAN << "|" << RESET << formatString("Index") << CYAN << "|" << RESET;
    std::cout << formatString("First Name") << CYAN << "|" << RESET;
    std::cout << formatString("Last Name") << CYAN << "|" << RESET;
    std::cout << formatString("Nickname") << CYAN << "|" << RESET << std::endl;
    std::cout << CYAN << "---------------------------------------------" << RESET << std::endl;

    for (int i = 0; i < this->count; i++)
    {
        std::cout << CYAN << "|" << RESET << formatString(intToString(i + 1)) << CYAN << "|" << RESET;
        std::cout << formatString(this->contacts[i].getFirstName()) << CYAN << "|" << RESET;
        std::cout << formatString(this->contacts[i].getLastName()) << CYAN << "|" << RESET;
        std::cout << formatString(this->contacts[i].getNickname()) << CYAN << "|" << RESET << std::endl;
    }
    
    std::cout << CYAN << "---------------------------------------------" << RESET << std::endl;
}

std::string PhoneBook::intToString(int num)
{
    if (num == 0)
        return "0";
    
    std::string result;
    bool isNegative = false;
    
    if (num < 0)
    {
        isNegative = true;
        num = -num;
    }
    
    while (num > 0)
    {
        result = static_cast<char>('0' + (num % 10)) + result;
        num /= 10;
    }
    
    if (isNegative)
        result = "-" + result;
    
    return result;
}

std::string PhoneBook::formatString(const std::string& str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    
    std::string formatted;
    size_t spaces = 10 - str.length();
    
    for (size_t i = 0; i < spaces; i++)
        formatted += " ";
    formatted += str;
    
    return formatted;
}

void PhoneBook::displayContactDetails(int index) const
{
    if (index < 0 || index >= this->count)
    {
        std::cout << RED << "Invalid index!" << RESET << std::endl;
        return;
    }

    std::cout << "\n" << GREEN << "====== Contact Details ======" << RESET << std::endl;
    std::cout << CYAN << "First Name    : " << RESET << this->contacts[index].getFirstName() << std::endl;
    std::cout << CYAN << "Last Name     : " << RESET << this->contacts[index].getLastName() << std::endl;
    std::cout << CYAN << "Nickname      : " << RESET << this->contacts[index].getNickname() << std::endl;
    std::cout << CYAN << "Phone Number  : " << RESET << this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << CYAN << "Darkest Secret: " << RESET << this->contacts[index].getSecret() << std::endl;
    std::cout << GREEN << "=============================" << RESET << std::endl;
}
