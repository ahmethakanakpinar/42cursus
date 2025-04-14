/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 05:11:46 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/14 05:56:38 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_bigger(long *numbers, int size)
{
	int		index;
	long	bigger;

	bigger = numbers[0];
	index = 0;
	while (index < size)
	{
		if (numbers[index] > bigger)
			bigger = numbers[index];
		index++;
	}
	return (bigger);
}

long	*normalize(long *numbers, int size)
{
	int		i;
	long	*nums;
	int		j;
	int		smaller;
	long	bigger;

	bigger = find_bigger(numbers, size);
	nums = malloc(sizeof(long) * size);
	if (!nums)
		return (free(numbers), NULL);
	i = 0;
	while (i < size)
	{
		smaller = 0;
		j = 0;
		while (j < size)
		{
			if (numbers[j] < numbers[smaller])
				smaller = j;
			j++;
		}
		numbers[smaller] = bigger + 1;
		nums[smaller] = i++;
	}
	return (free(numbers), nums);
}
