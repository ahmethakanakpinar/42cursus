/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar < aakpinar@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 11:54:53 by aakpinar          #+#    #+#             */
/*   Updated: 2025/12/26 12:02:05 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc[i]; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            std::cout << static_cast<char>(std::toupper(argv[i][j]));
        }
    }
    std::cout << std::endl;
    return 0;
}