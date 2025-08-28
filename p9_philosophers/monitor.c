/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 03:08:20 by aakpinar          #+#    #+#             */
/*   Updated: 2025/08/28 23:12:10 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


bool	all_ate_enough(t_table *table)
{
	int	i;
	int	finished;

	if (table->must_eat == -1)
		return (false);
	finished = 0;
	i = -1;
	while (++i < table->philo_count)
	{
		if (table->philosophers[i].eaten_meal >= table->must_eat)
			finished++;
	}
	return (finished == table->philo_count);
}

bool	check_philosopher_death(t_table *table, int i)
{
	long	time;

	pthread_mutex_lock(&table->last_meal_mutex);
	time = time_diff(table->philosophers[i].last_meal, get_time());
	pthread_mutex_unlock(&table->last_meal_mutex);
	if (time >= table->time_to_die)
	{
		pthread_mutex_lock(&table->death_mutex);
		if (!table->someone_died)
		{
			table->someone_died = true;
			pthread_mutex_lock(&table->print_mutex);
			printf("%ld %i died\n", time,
				table->philosophers[i].id);
			pthread_mutex_unlock(&table->print_mutex);
		}
		pthread_mutex_unlock(&table->death_mutex);
		return (true);
	}
	return (false);
}

bool	check_simulation_end(t_table *table)
{
	if (table->must_eat != -1 && all_ate_enough(table))
	{
		pthread_mutex_lock(&table->death_mutex);
		table->someone_died = true;
		pthread_mutex_unlock(&table->death_mutex);
		return (true);
	}
	return (false);
}

void	*monitor_routine(void *table_void)
{
	t_table	*table;
	int		i;

	table = (t_table *)table_void;
	while (1)
	{
		i = -1;
		while (++i < table->philo_count)
		{
			if (check_philosopher_death(table, i))
				return (NULL);
		}
		if (check_simulation_end(table))
			return (NULL);
		usleep(50);
		if (check_death(table))
			return (NULL);
	}
}
bool	check_death(t_table *table)
{
	bool	died;

	pthread_mutex_lock(&table->death_mutex);
	died = table->someone_died;
	pthread_mutex_unlock(&table->death_mutex);
	return (died);
}