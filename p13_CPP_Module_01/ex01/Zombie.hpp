/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 03:47:02 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/28 04:09:32 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>


class Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
        void setName(std::string name);


};
Zombie* zombieHorde(int N, std::string name);

#endif