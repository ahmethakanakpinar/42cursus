/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:34:56 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/22 22:32:10 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ac_check(int ac, char **av)
{
	if (ac != 2)
		error_free_msg(NULL, "Error: Invalid number of ac");
	if (*av[1] == '\0')
		error_free_msg(NULL, "File Name is null");
}

int	main(int ac, char **av)
{
	t_game	game;

	ac_check(ac, av);
	game = init_game();
	get_map(av[1], &game);
	unioncheck(&game);
	init_mlx(&game);
	render_map(&game);
	hook_n_run(&game);
	return (EXIT_SUCCESS);
}
