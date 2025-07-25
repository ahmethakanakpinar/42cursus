/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:38:07 by aakpinar          #+#    #+#             */
/*   Updated: 2025/07/26 00:27:26 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>  
# include <pthread.h> 
# include <stdbool.h>  
# include <stdio.h>    
# include <stdlib.h>   
# include <sys/time.h> 
# include <unistd.h>   

# define SUCCESS 0
# define ERROR 1
# define MAX_PHILOS 200
# define WARNING_ARGS "%sWarning: time below 60ms might cause timing issues%s\n"

// Colors for status messages
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"
# define BOLD "\033[1m"
# define WHITE "\033[0;97m"
# define MAGENTA "\033[0;95m"

// Philosopher states
typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	FORK_TAKEN,
	DIED
}					t_state;

// Structure for each philosopher
typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal;
	t_state			state;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	bool			someone_died;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	death_mutex;
	t_philo			*philosophers;
}					t_data;

int		error_msg(char *str);

#endif