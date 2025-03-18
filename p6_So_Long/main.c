/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:34:56 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/17 19:43:51 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ac_check(int ac, char **av)
{
	if (ac != 2)
		printf("Error: Invalid number of ac"); 
	if (*av[1] == '\0')
        printf("File Name is null");
}

int	main(int ac, char **av)
{
	ac_check(ac, av);
	return (0);
}