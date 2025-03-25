/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:52:15 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/24 21:51:02 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

#include <unistd.h>
#include <limits.h>
#include <stdio.h>

void	error_xpm_bonus(t_game_bonus *game)
{
	if (!game->block.wall)
	{
		perror("MLX XPM Yükleme Hatası");
		error_free_msg_bonus(game, "Error in wall_bonus.xpm file");
	}
	if (!game->block.exit)
		error_free_msg_bonus(game, "Error in exit_bonus.xpm file");
	if (!game->block.player->img_left)
		error_free_msg_bonus(game, "Error in player_bonus.xpm file");
	if (!game->block.player->img_right)
		error_free_msg_bonus(game, "Error in player_bonus.xpm file");
	if (!game->block.player->img_down)
		error_free_msg_bonus(game, "Error in player_bonus.xpm file");
	if (!game->block.player->img_up)
		error_free_msg_bonus(game, "Error in player_bonus.xpm file");
	if (!game->block.floor)
		error_free_msg_bonus(game, "Error in floor_bonus.xpm file");
	if (!game->block.collectibles)
		error_free_msg_bonus(game, "Error in collectibles_bonus.xpm file");
}

void	xpm_to_image_bonus(t_game_bonus *game)
{
	int	img_size;

	img_size = B_S_BONUS;
	game->block.wall = mlx_xpm_file_to_image(game->mlx_init, W_B_BONUS,
			&img_size, &img_size);
	game->block.floor = mlx_xpm_file_to_image(game->mlx_init, F_B_BONUS,
			&img_size, &img_size);
	game->block.player = malloc(sizeof(t_player_bonus));
	if (!game->block.player)
		error_free_msg_bonus(game, "Malloc error for player struct");
	game->block.player->img_up = mlx_xpm_file_to_image(game->mlx_init,
			P_U_BONUS, &img_size, &img_size);
	game->block.player->img_down = mlx_xpm_file_to_image(game->mlx_init,
			P_D_BONUS, &img_size, &img_size);
	game->block.player->img_left = mlx_xpm_file_to_image(game->mlx_init,
			P_L_BONUS, &img_size, &img_size);
	game->block.player->img_right = mlx_xpm_file_to_image(game->mlx_init,
			P_R_BONUS, &img_size, &img_size);
	game->block.player->img = game->block.player->img_left;
	game->block.collectibles = mlx_xpm_file_to_image(game->mlx_init,
			C_B_BONUS, &img_size, &img_size);
	game->block.exit = mlx_xpm_file_to_image(game->mlx_init, E_B_BONUS,
			&img_size, &img_size);
	error_xpm_bonus(game);
}

void	img_to_window_bonus(t_game_bonus *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.row)
	{
		j = -1;
		while (++j < game->map.column)
		{
			if (game->map.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
					game->block.wall, B_S_BONUS * j, B_S_BONUS * i);
			else if (game->map.map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
					game->block.collectibles, B_S_BONUS * j, B_S_BONUS * i);
			else if (game->map.map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
					game->block.exit, B_S_BONUS * j, B_S_BONUS * i);
			else
				mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
					game->block.floor, B_S_BONUS * j, B_S_BONUS * i);
		}
	}
	put_player_block_bonus(game);
}

void	render_map_bonus(t_game_bonus *game)
{
	xpm_to_image_bonus(game);
	img_to_window_bonus(game);
}
