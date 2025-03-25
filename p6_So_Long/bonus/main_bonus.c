/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:34:56 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/24 21:32:51 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ac_check_bonus(int ac, char **av)
{
	if (ac != 2)
		error_free_msg_bonus(NULL, "Error: Invalid number of ac");
	if (*av[1] == '\0')
		error_free_msg_bonus(NULL, "File Name is null");
}

int	main(int ac, char **av)
{
	t_game_bonus	game;

	ac_check_bonus(ac, av);
	game = init_game_bonus();
	get_map_bonus(av[1], &game);
	unioncheck_bonus(&game);
	init_mlx_bonus(&game);
	render_map_bonus(&game);
	hook_n_run_bonus(&game);
	return (EXIT_SUCCESS);
}
