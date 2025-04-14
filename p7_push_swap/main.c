/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 04:56:37 by aakpinar          #+#    #+#             */
/*   Updated: 2025/04/14 05:56:29 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	arg_counter(char **av)
{
    int count = 0;
    
    while (av[count] != NULL)
        count++;
    return (count + 1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = ac;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			return (1);
		ac = arg_counter(av);
	}
	else
		av += 1;
	stack_init(&a, av, ac, size == 2);
	
	return (0);
}
