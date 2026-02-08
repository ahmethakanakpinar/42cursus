/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmethakan <ahmethakan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 01:12:54 by aakpinar          #+#    #+#             */
/*   Updated: 2026/02/08 11:19:42 by ahmethakan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>


class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce(void);

    private:
        std::string _name;

};
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif