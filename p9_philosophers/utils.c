/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:37:57 by aakpinar          #+#    #+#             */
/*   Updated: 2025/08/27 02:47:00 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(char *str)
{
	printf("%s Error: %s%s\n", RED, str, RESET);
	return (ERROR);
}

int	error_msg_with_index(int index, char *str)
{
	printf("%s Error: %s%s\n", RED, str, RESET);
	printf("%s ARGUMENT : %d %s\n", YELLOW, index, RESET);
	return (ERROR);
}


int	ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	res;

	i = 0;
	a = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			a = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * a);
}

void	destroy_forks(t_table *table, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		pthread_mutex_destroy(&table->forks[i]);
}

void destroy_table(t_table *table)
{
    int i;

    if (table->philosophers)
    {
        free(table->philosophers);
        table->philosophers = NULL;
    }

    if (table->forks)
    {
        i = -1;
        while (++i < table->philo_count)
            pthread_mutex_destroy(&table->forks[i]);
        free(table->forks);
        table->forks = NULL;
    }
    
    pthread_mutex_destroy(&table->print_mutex);
    pthread_mutex_destroy(&table->death_mutex);
    pthread_mutex_destroy(&table->last_meal_mutex);
}