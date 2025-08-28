/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:40:12 by aakpinar          #+#    #+#             */
/*   Updated: 2025/08/28 22:50:06 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (error_msg("gettimeofday() failed"));
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	time_diff(long past, long present)
{
	return (present - past);
}

void	precise_sleep(long time)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(50);
}
