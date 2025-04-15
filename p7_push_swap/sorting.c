/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 01:28:45 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/15 05:57:22 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bit(int bit_index, int n)
{
	return (n >> bit_index & 1);
}

void	operations(t_stack **a, t_stack **b, int bit_index)
{
	int	size;
	int	index;

	while (*b)
		push(a, b, "pa");
	size = stack_len(*a);
	index = 0;
	while (index < size)
	{
		if ((stack_sorted(*a) && *b == NULL))
			break ;
		if (get_bit(bit_index, (*a)->value))
			rotate(a, NULL, "ra");
		else
			push(b, a, "pb");
		index++;
	}
}

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	index;

	index = 0;
	if (size == 2)
		swap(a, "sa");
	else if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_five(a, b);
	else
	{
		while (1)
		{
			operations(a, b, index);
			if ((stack_sorted(*a) && *b == NULL))
				break ;
			index++;
		}
	}
}
