/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 04:34:02 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/03 23:53:47 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

enum Command
{
    ADD,
    SEARCH,
    EXIT,
    INVALID
};

Command parseCommand(const std::string& input)
{
    if (input == "ADD")
        return ADD;
    else if (input == "SEARCH")
        return SEARCH;
    else if (input == "EXIT")
        return EXIT;
    return INVALID;
}

int main()
{
    PhoneBook phoneBook;
    std::string input;
    Command command;

    std::cout << "Welcome to the PhoneBook!\n";

    do
    {
        std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";        
        std::getline(std::cin, input);

        if(std::cin.eof())
            break;
        
        command = parseCommand(input);

        switch (command)
        {
            case ADD:
                // ADD logic here
                phoneBook.addContact();
                break;
            case SEARCH:
                // SEARCH logic here
                phoneBook.searchContacts();
                break;
            case EXIT:
                break;
            case INVALID:
                std::cout << RED << "Invalid command. Please try again." << RESET << std::endl;
                break;
        }
    } while (command != EXIT);
    std::cout << GREEN << "Goodbye!" << RESET << std::endl;
    return(0);
}