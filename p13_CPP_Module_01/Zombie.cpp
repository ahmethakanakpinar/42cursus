/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 01:12:59 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/28 03:12:00 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " is created." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->_name << " is destroyed." << std::endl;
}
void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}