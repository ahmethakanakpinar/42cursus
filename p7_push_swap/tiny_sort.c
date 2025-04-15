/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 02:53:08 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/15 05:59:23 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*a)->value;
	middle = (*a)->next->value;
	bottom = (*a)->next->next->value;
	if (top > middle && middle < bottom && bottom > top)
		swap(a, "sa");
	else if (top > middle && middle < bottom && bottom < top)
		rotate(a, NULL, "ra");
	else if (top < middle && middle > bottom && bottom > top)
	{
		swap(a, "sa");
		rotate(a, NULL, "ra");
	}
	else if (top < middle && middle > bottom && bottom < top)
		reverse_rotate(a, NULL, "rra");
	else if (top > middle && middle > bottom)
	{
		swap(a, "sa");
		reverse_rotate(a, NULL, "rra");
	}
}

static void	make_stack_three(t_stack **a, t_stack **b)
{
	int	index;
	int	counter;
	int	size;

	index = 0;
	counter = 0;
	size = stack_len(*a);
	while (index < size)
	{
		if ((*a)->value == 0 && size == 4)
		{
			push(b, a, "pb");
			break ;
		}
		else if (size == 5 && ((*a)->value == 0 || (*a)->value == 1))
		{
			push(b, a, "pb");
			counter++;
		}
		else if (counter == 2)
			break ;
		else
			rotate(a, NULL, "ra");
		index++;
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	make_stack_three(a, b);
	sort_three(a);
	if (!stack_sorted(*a))
		sort_three(a);
	if (stack_len(*b) == 2 && (*b)->value < (*b)->next->value)
		swap(b, "sb");
	while (stack_len(*b))
		push(a, b, "pa");
}
