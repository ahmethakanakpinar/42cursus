/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 01:10:33 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/28 03:31:12 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
    Zombie* NewZombie = newZombie("Foo");
    NewZombie->announce();
    delete NewZombie;

    Zombie zombie("Foo");
    zombie.announce();
    randomChump("Foo");
    return 0;
}