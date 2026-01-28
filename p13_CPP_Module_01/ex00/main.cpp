/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 01:10:33 by aakpinar          #+#    #+#             */
/*   Updated: 2026/01/28 03:41:55 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


int main()
{
    Zombie* heapZombie = newZombie("Heap");
    heapZombie->announce();
    std::cout << std::endl;
    std::cout << std::endl;

    
    randomChump("Stack");
    std::cout << std::endl;
    std::cout << std::endl;

    delete heapZombie;
    return 0;
}