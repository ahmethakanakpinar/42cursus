/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:52:15 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/22 22:53:54 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_xpm(t_game *game)
{
	if (!game->block.wall)
		error_free_msg(game, "Error in wall.xpm file");
	if (!game->block.exit)
		error_free_msg(game, "Error in exit.xpm file");
	if (!game->block.player->img_left)
		error_free_msg(game, "Error in player.xpm file");
	if (!game->block.player->img_right)
		error_free_msg(game, "Error in player.xpm file");
	if (!game->block.player->img_down)
		error_free_msg(game, "Error in player.xpm file");
	if (!game->block.player->img_up)
		error_free_msg(game, "Error in player.xpm file");
	if (!game->block.floor)
		error_free_msg(game, "Error in floor.xpm file");
	if (!game->block.collectibles)
		error_free_msg(game, "Error in collectibles.xpm file");
}

void	xpm_to_image(t_game *game)
{
	int	img_size;

	img_size = BLOCK_SIZE;
	game->block.wall = mlx_xpm_file_to_image(game->mlx_init, WALL_BLOCK,
			&img_size, &img_size);
	game->block.floor = mlx_xpm_file_to_image(game->mlx_init, FLOOR_BLOCK,
			&img_size, &img_size);
	game->block.player = malloc(sizeof(t_player));
	if (!game->block.player)
		error_free_msg(game, "Malloc error for player struct");
	game->block.player->img_up = mlx_xpm_file_to_image(game->mlx_init,
			PLAYER_UP, &img_size, &img_size);
	game->block.player->img_down = mlx_xpm_file_to_image(game->mlx_init,
			PLAYER_DOWN, &img_size, &img_size);
	game->block.player->img_left = mlx_xpm_file_to_image(game->mlx_init,
			PLAYER_LEFT, &img_size, &img_size);
	game->block.player->img_right = mlx_xpm_file_to_image(game->mlx_init,
			PLAYER_RIGHT, &img_size, &img_size);
	game->block.player->img = game->block.player->img_left;
	game->block.collectibles = mlx_xpm_file_to_image(game->mlx_init,
			COLLECTIBLES_BLOCK, &img_size, &img_size);
	game->block.exit = mlx_xpm_file_to_image(game->mlx_init, EXIT_BLOCK,
			&img_size, &img_size);
	error_xpm(game);
}

void	img_to_window(t_game *game)
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
					game->block.wall, BLOCK_SIZE * j, BLOCK_SIZE * i);
			else if (game->map.map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
					game->block.collectibles, BLOCK_SIZE * j, BLOCK_SIZE * i);
			else if (game->map.map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
					game->block.exit, BLOCK_SIZE * j, BLOCK_SIZE * i);
			else
				mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
					game->block.floor, BLOCK_SIZE * j, BLOCK_SIZE * i);
		}
	}
	put_player_block(game);
}

void	render_map(t_game *game)
{
	xpm_to_image(game);
	img_to_window(game);
}
