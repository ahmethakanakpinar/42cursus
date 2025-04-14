/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 05:03:08 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/14 06:02:45 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	create_list(t_stack **a, long *numbers, int argc)
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{
		if (append_node(a, numbers[index]))
			return (1);
		index++;
	}
	free(numbers);
	return (0);
}

void	stack_init(t_stack **a, char **argv, int argc, int is_split_arg)
{
	long	nbr;
	int		index;
	long	*numbers;

	index = 0;
	numbers = malloc(sizeof(long) * (argc - 1));
	if (numbers == NULL)
		error_free(a, argv, is_split_arg, NULL);
	while (argv[index])
	{
		if (error_syntax(argv[index]))
			error_free(a, argv, is_split_arg, numbers);
		if (error_overflow(&nbr, index, argv))
			error_free(a, argv, is_split_arg, numbers);
		numbers[index++] = (int)nbr;
	}
	if (error_repetition(numbers, argc - 1))
		error_free(a, argv, is_split_arg, numbers);
	numbers = normalize(numbers, argc - 1);
	if (numbers == NULL)
		error_free(a, argv, is_split_arg, NULL);
	if (create_list(a, numbers, argc))
		error_free(a, argv, is_split_arg, numbers);
	if (is_split_arg)
		free_matrix(argv);
}

static int	error_overflow(long *nbr, int index, char **argv)
{
	*nbr = ft_atol(argv[index]);
	if (*nbr > INT_MAX)
	{
		write(2, OVERFLOW, ft_strlen(OVERFLOW));
		return (1);
	}
	return (0);
}