/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar < aakpinar@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 04:42:47 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/02 04:57:55 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
PhoneBook::PhoneBook()
{
    this->count = 0;
    this->oldestIndex = 0;
}
void PhoneBook::addContact()
{
    Contact newContact = Contact::createFromInput();
    
    this->contacts[this->oldestIndex] = newContact;
    
    if(this->count < 8)
        this->count++;

    this->oldestIndex = (this->oldestIndex + 1) % 8;

    std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;  
}