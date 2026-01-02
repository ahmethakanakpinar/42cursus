/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar < aakpinar@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 04:33:33 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/02 04:51:55 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

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
    
   

private:
    Contact contacts[8];
    int oldestIndex;
    int count;
    

   
};

#endif