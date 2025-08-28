/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:38:24 by aakpinar          #+#    #+#             */
/*   Updated: 2025/08/28 23:13:55 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void	print_status(t_philo *philo, t_state state)
{
	size_t	time;

	pthread_mutex_lock(&philo->table->death_mutex);
	if (!philo->table->someone_died)
	{
		pthread_mutex_lock(&philo->table->print_mutex);
		time = time_diff(philo->table->start_time, get_time());
		if (state == FORK_TAKEN)
			printf("%ld %i has taken a fork\n",
				time, philo->id);
		else if (state == EATING)	
			printf("%ld %i is eating\n",
				time, philo->id);
		else if (state == SLEEPING)
			printf("%ld %i is sleeping\n",
				time, philo->id);
		else if (state == THINKING)
			printf("%ld %i is thinking\n",
				time, philo->id);
		else if (state == DIED)
			printf("%ld %i died\n", time,
				philo->id);
		pthread_mutex_unlock(&philo->table->print_mutex);
	}
	pthread_mutex_unlock(&philo->table->death_mutex);
}

static int	start_threads(t_table *table)
{
	pthread_t	monitor;
	int			i;

	i = 0;
	while (i < table->philo_count)
	{
		if (pthread_create(&table->philosophers[i].thread, NULL,
				philosopher_routine, &table->philosophers[i]) != 0)
			return (error_msg("thread creation failed"));
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, table) != 0)
		return (error_msg("monitor thread creation failed"));
	i = 0;
	while (i < table->philo_count)
	{
		pthread_join(table->philosophers[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	return (SUCCESS);
}






static int	handle_one_philo(t_table *table)
{
	print_status(&table->philosophers[0], THINKING);
	// Single philosopher can't eat because they need two forks
	// They will die after time_to_die from start
	precise_sleep(table->time_to_die);
	print_status(&table->philosophers[0], DIED);
	table->someone_died = true;
	return (SUCCESS);	
}


int	main(int argc, char **argv)
{
	t_table	table;

	if (validate_arguments(argc, argv) != SUCCESS)
		return (ERROR);
	if (init_table(&table, argc, argv) != SUCCESS)
		return (ERROR);
	if (init_mutex(&table) != SUCCESS)
		return (destroy_table(&table), ERROR);
	if (init_philosophers(&table) != SUCCESS)
		return (destroy_table(&table), ERROR);

	if (table.philo_count == 1)
	{
		handle_one_philo(&table);
	}
	else
	{
		if (start_threads(&table) != SUCCESS)
			return (destroy_table(&table), ERROR);
	}
	destroy_table(&table);
	return (SUCCESS);
}
