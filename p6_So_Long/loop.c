/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 21:08:22 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/20 21:46:12 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	quit_game(t_game *game)
{
	error_free(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	on_press(int key, t_game *game)
{
	if (key == 65307)
		quit_game(game);
	else if (key == 119 || key == 65362)
	{
		game->block.player->img = game->block.player->img_up;
		update_player_pos(game, false, -1);
	}
	else if (key == 97 || key == 65361)
	{
		game->block.player->img = game->block.player->img_left;
		update_player_pos(game, true, -1);
	}
	else if (key == 115 || key == 65364)
	{
		game->block.player->img = game->block.player->img_down;
		update_player_pos(game, false, 1);
	}
	else if (key == 100 || key == 65363)
	{
		game->block.player->img = game->block.player->img_right;
		update_player_pos(game, true, 1);
	}	
	return (EXIT_SUCCESS);
}

void	hook_n_run(t_game *game)
{
	mlx_hook(game->mlx_wind, 2, (1L << 0), on_press, game);
	mlx_hook(game->mlx_wind, 17, (1L << 17), quit_game, game);
	mlx_loop(game->mlx_init);
}
