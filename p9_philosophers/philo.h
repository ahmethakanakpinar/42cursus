/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:38:07 by aakpinar          #+#    #+#             */
/*   Updated: 2025/08/28 22:51:09 by aakpinar         ###   ########.fr       */
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

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	FORK_TAKEN,
	DIED
}					t_state;

typedef struct s_philo
{
	int				id;
	int				eaten_meal;
	long			last_meal;
	t_state			state;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
}					t_philo;

typedef struct s_table
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	bool			someone_died;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;	
	pthread_mutex_t	last_meal_mutex;
	pthread_mutex_t	death_mutex;
	t_philo			*philosophers;
}					t_table;


int	is_valid_number(char *str);
int	check_limits(char *str);
int	check_philo_number(char *str);
int	validate_arguments(int argc, char **argv);

int	parse_args(t_table *table, int argc, char **argv);
int	init_table(t_table *table, int argc, char **argv);
int	init_fork_mutexes(t_table *table);
int	init_mutex(t_table *table);
int	init_philosophers(t_table *table);

bool	all_ate_enough(t_table *table);
bool	check_philosopher_death(t_table *table, int i);
bool	check_simulation_end(t_table *table);
void	*monitor_routine(void *table_void);
bool	check_death(t_table *table);


int	take_forks(t_philo *philo);
void	drop_forks(t_philo *philo);
int	eat(t_philo *philo);
int	sleep_and_think(t_philo *philo);
void	*philosopher_routine(void *philosopher_void);


long	get_time(void);
long	time_diff(long past, long present);
void	precise_sleep(long time);

int	error_msg(char *str);
int	error_msg_with_index(int index, char *str);
int	ft_atoi(const char *str);
void	destroy_forks(t_table *table, int count);
void	destroy_table(t_table *table);

void	print_status(t_philo *philo, t_state state);

#endif
