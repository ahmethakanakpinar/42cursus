/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 05:03:08 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/15 03:44:54 by aakpinar         ###   ########.fr       */
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

void	user_message(char *string)
{
	if (!ft_strncmp(string, "pa", 2))
		ft_printf(PA);
	else if (!ft_strncmp(string, "pb", 2))
		ft_printf(PB);
	else if (!ft_strncmp(string, "rra", 3))
		ft_printf(RRA);
	else if (!ft_strncmp(string, "rrr", 3))
		ft_printf(RRR);
	else if (!ft_strncmp(string, "ra", 2))
		ft_printf(RA);
	else if (!ft_strncmp(string, "rb", 2))
		ft_printf(RB);
	else if (!ft_strncmp(string, "rr", 2))
		ft_printf(RR);
	else if (!ft_strncmp(string, "sa", 2))
		ft_printf(SA);
	else if (!ft_strncmp(string, "sb", 2))
		ft_printf(SB);
}
