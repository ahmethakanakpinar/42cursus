/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:26:31 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/15 04:18:19 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_iswhitespace(char c)
{
	return (((c >= 9 && c <= 13) || c == 32));
}

long	ft_atol(char *string)
{
	long	number;
	long	index;
	int		sign;

	index = 0;
	while (ft_iswhitespace(string[index]))
		index++;
	sign = 1;
	if (string[index] == '+' || string[index] == '-')
	{
		if (string[index] == '-')
			sign = -1;
		index++;
	}
	number = 0;
	while (ft_isdigit(string[index]))
	{
		number = number * 10 + (string[index] - '0');
		index++;
		if (sign == -1 && number == 2147483648)
			return (-2147483648);
		if (number > INT_MAX || number < INT_MIN)
			return (2147483648);
	}
	return (number * sign);
}
