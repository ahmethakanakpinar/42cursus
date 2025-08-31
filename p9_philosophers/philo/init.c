/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:38:39 by aakpinar          #+#    #+#             */
/*   Updated: 2025/08/31 05:31:18 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(t_table *table, int argc, char **argv)
{
	table->philo_count = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->must_eat = -1;
	if (argc == 6)
		table->must_eat = ft_atoi(argv[5]);
	if (table->philo_count <= 0 || table->time_to_die <= 0
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0 || (argc == 6
			&& table->must_eat <= 0))
		return (error_msg("invalid argument values."));
	return (SUCCESS);
}

int	init_table(t_table *table, int argc, char **argv)
{
	if (parse_args(table, argc, argv) != SUCCESS)
		return (ERROR);
	table->someone_died = false;
	table->start_time = get_time();
	if (table->start_time < 0)
		return (ERROR);
	table->philosophers = malloc(sizeof(t_philo) * table->philo_count);
	if (!table->philosophers)
		return (error_msg("malloc failed for philosophers"));
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_count);
	if (!table->forks)
	{
		free(table->philosophers);
		return (error_msg("malloc failed for forks"));
	}
	return (SUCCESS);
}

int	init_fork_mutexes(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			destroy_fork_mutexes(table, i);
			return (error_msg("mutex initialization failed"));
		}
		i++;
	}
	return (SUCCESS);
}

int	init_mutex(t_table *table)
{
	if (init_fork_mutexes(table) != SUCCESS)
		return (ERROR);
	if (pthread_mutex_init(&table->print_mutex, NULL) != 0)
	{
		cleanup_on_error(table);
		return (error_msg("print mutex initialization failed"));
	}
	if (pthread_mutex_init(&table->death_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->print_mutex);
		cleanup_on_error(table);
		return (error_msg("death mutex initialization failed"));
	}
	if (pthread_mutex_init(&table->last_meal_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->death_mutex);
		pthread_mutex_destroy(&table->print_mutex);
		cleanup_on_error(table);
		return (error_msg("last_meal mutex initialization failed"));
	}
	return (SUCCESS);
}

int	init_philosophers(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_count)
	{
		table->philosophers[i].id = i + 1;
		table->philosophers[i].eaten_meal = 0;
		table->philosophers[i].last_meal = table->start_time;
		table->philosophers[i].state = THINKING;
		table->philosophers[i].table = table;
		table->philosophers[i].left_fork = &table->forks[i];
		table->philosophers[i].right_fork = &table->forks[(i + 1)
			% table->philo_count];
		i++;
	}
	return (SUCCESS);
}
