/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 02:12:45 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/14 20:34:19 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	send_bit(int pid, int bit)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error: enter correct pid\n");
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Error: enter correct pid \n");
			exit(1);
		}
	}
}

static	void	send_null_terminator(int pid, int *sent)
{
	if (*sent < 8)
	{
		send_bit(pid, 0);
		(*sent)++;
	}
	else
		exit(0);
}

static void	ft_send_str(int pid, const char *str)
{
	static const char	*message = NULL;
	static int			bit_index = 0;
	static int			null_bits_sent = 0;
	char				current_char;
	int					current_bit;

	if (str != 0)
	{
		message = str;
		bit_index = 0;
		null_bits_sent = 0;
	}
	if ((message != 0) && message[bit_index / 8])
	{
		current_char = message[bit_index / 8];
		current_bit = (current_char >> (bit_index % 8)) & 1;
		send_bit(pid, current_bit);
		bit_index++;
	}
	else if (message != 0)
		send_null_terminator(pid, &null_bits_sent);
}

void	ft_receipt(int sig, siginfo_t *info, void *context)
{
	static int	pid = 0;

	(void)context;
	if (info->si_pid)
		pid = info->si_pid;
	if (sig == SIGUSR1)
		ft_send_str(pid, NULL);
	else if (sig == SIGUSR2)
		exit(0);
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	if (ac != 3 || ft_strlen(av[1]) > 8)
	{
		ft_printf("Error: Invalid Argument Or PID\n");
		ft_printf("USED: ./client <server_pid> <string>\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid >= 4194304)
		return (ft_printf("Error: Invalid PID\n"), 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_receipt;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (ft_printf("Error: sigaction\n"), 1);
	ft_send_str(pid, av[2]);
	while (1)
		pause();
}
