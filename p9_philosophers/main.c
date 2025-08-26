/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:38:24 by aakpinar          #+#    #+#             */
/*   Updated: 2025/08/27 01:45:25 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (validate_arguments(argc, argv) != SUCCESS)
		return (ERROR);
	if (init_table(&table, argc, argv) != SUCCESS)
		return (ERROR);
	if (init_mutex(&table) != SUCCESS)
		return (destroy_table(&table), ERROR);
	if (init_philosophers(&table) != SUCCESS)
		return (destroy_table(&table), ERROR);
	
	return (SUCCESS);
}
