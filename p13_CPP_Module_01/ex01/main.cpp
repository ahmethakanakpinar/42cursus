/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 03:53:04 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/28 04:10:16 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int count = 10;
    Zombie* zombies = zombieHorde(count, "Zombie");
    for(int i = 0; i < count; i++)
    {
        zombies[i].announce();
    }

    delete[] zombies;
    return 0;
}