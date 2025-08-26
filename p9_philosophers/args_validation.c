/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:02:17 by aakpinar          #+#    #+#             */
/*   Updated: 2025/08/27 00:50:17 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_limits(char *str)
{
	long	num;
	int		i;

	i = 0;
	num = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		num = (num * 10) + (str[i] - '0');
		if (num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	check_philo_number(char *str)
{
	int	num;

	num = ft_atoi(str);
	if (num < 1)
		return (error_msg_with_index(2, "need at least 1 philosopher"));
	if (num > MAX_PHILOS)
		return (error_msg_with_index(2, "too many philosophers (max 200)"));
	return (SUCCESS);
}


int	validate_arguments(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (error_msg("Invalid number of arguments. Expected 5 or 6 arguments."));
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (error_msg_with_index(i+1, "invalid argument format"));
		if (!check_limits(argv[i]))
			return (error_msg_with_index(i+1, "argument too large"));
		i++;
	}
	if (check_philo_number(argv[1]) != SUCCESS)
		return (ERROR);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (error_msg_with_index(6, "meals number must be positive"));
	return (SUCCESS);
}
