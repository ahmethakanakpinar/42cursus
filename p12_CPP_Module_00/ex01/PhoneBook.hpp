/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 04:33:33 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/03 22:18:27 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();
    
    // Add a new contact
    void addContact();
    // Search and display contacts
    void searchContacts();
    // Display all contacts in a formatted table
    void displayAllContacts() const;
   

private:
    Contact contacts[8];
    int count;
    int oldestIndex;
    
    // Helper methods
    static std::string formatString(const std::string& str);
    static std::string intToString(int num);
};

#endif