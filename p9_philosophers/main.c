/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:38:24 by aakpinar          #+#    #+#             */
/*   Updated: 2025/07/26 00:27:19 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (error_msg("wrong number of arguments"));
	
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) != SUCCESS)
		return (ERROR);
	
}
