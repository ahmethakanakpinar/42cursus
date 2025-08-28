/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:53:18 by aakpinar          #+#    #+#             */
/*   Updated: 2025/08/28 22:16:52 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->id % 2 == 0) {
		first = philo->right_fork;
		second = philo->left_fork;
	} else {
		first = philo->left_fork;
		second = philo->right_fork;
	}
	pthread_mutex_lock(first);
	print_status(philo, FORK_TAKEN);
	pthread_mutex_lock(second);
	print_status(philo, FORK_TAKEN);
	return (SUCCESS);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->id % 2 == 0) {
		first = philo->right_fork;
		second = philo->left_fork;
	} else {
		first = philo->left_fork;
		second = philo->right_fork;
	}

	// Mutex unlock sırası: lock edilen sıranın tersinde
	// Lock: first → second, Unlock: second → first
	pthread_mutex_unlock(second);  // Lock edilen sonuncuyu önce unlock et
	pthread_mutex_unlock(first);   // Lock edilen ilkini sonra unlock et
}

int	eat(t_philo *philo)
{
	print_status(philo, EATING);
	pthread_mutex_lock(&philo->table->last_meal_mutex);
	philo->last_meal = get_time();
	philo->eaten_meal++;
	pthread_mutex_unlock(&philo->table->last_meal_mutex);
	precise_sleep(philo->table->time_to_eat);
	drop_forks(philo);
	return (SUCCESS);
}

int	sleep_and_think(t_philo *philo)
{
	print_status(philo, SLEEPING);
	precise_sleep(philo->table->time_to_sleep);
	print_status(philo, THINKING);
	return (SUCCESS);
}

void	*philosopher_routine(void *philosopher_void)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher_void;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!check_death(philo->table))
	{
		if (take_forks(philo) != SUCCESS)
			break ;
		if (eat(philo) != SUCCESS)
			break ;
		if (sleep_and_think(philo) != SUCCESS)
			break ;
		usleep(200);
	}
	return (NULL);
}
