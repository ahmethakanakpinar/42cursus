/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 05:04:29 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/14 06:02:56 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **argv)
{
	int	index;

	index = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[index])
		free(argv[index++]);
	free(argv);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	error_free(t_stack **a, char **argv, int is_split_arg, int *numbers)
{
	free_stack(a);
	if (numbers != NULL)
		free(numbers);
	if (is_split_arg)
		free_matrix(argv);
	exit(EXIT_FAILURE);
}

int	error_syntax(char *str)
{
	int error_found;
	int	i;

	error_found = 0;
	if (!(str[0] == '+' || str[0] == '-' || ft_isdigit(str[0])))
		error_found = 1;
	if ((str[0] == '+' || str[0] == '-') && !ft_isdigit(str[1]))
		error_found = 1;
	i = 1;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error_found = 1;
		i++;
	}
	if (error_found)
		write(2, SYNTAX, ft_strlen(SYNTAX));
	return (error_found);
}

int	error_repetition(int *stack, int size)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j++])
			{
				flag = 1;
				break ;
			}
		}
		i++;
	}
	if (flag)
		write(2, DUPLICATE, ft_strlen(DUPLICATE));
	return (flag);
}
