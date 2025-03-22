/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:57:29 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/22 21:31:14 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_blocks(t_game *game)
{
	if (game->block.exit)
		mlx_destroy_image(game->mlx_init, game->block.exit);
	if (game->block.collectibles)
		mlx_destroy_image(game->mlx_init, game->block.collectibles);
	if (game->block.wall)
		mlx_destroy_image(game->mlx_init, game->block.wall);
	if (game->block.floor)
		mlx_destroy_image(game->mlx_init, game->block.floor);
	if (game->block.player)
	{
		if (game->block.player->img_up)
			mlx_destroy_image(game->mlx_init,
				game->block.player->img_up);
		if (game->block.player->img_down)
			mlx_destroy_image(game->mlx_init,
				game->block.player->img_down);
		if (game->block.player->img_left)
			mlx_destroy_image(game->mlx_init,
				game->block.player->img_left);
		if (game->block.player->img_right)
			mlx_destroy_image(game->mlx_init,
				game->block.player->img_right);
		free(game->block.player);
		game->block.player = NULL;
	}
}

void	free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	if (i > 0)
		free(matrix);
	matrix = NULL;
}

void	error_free(t_game *game)
{
	if (!game)
		return ;
	free_blocks(game);
	if (game->mlx_wind)
		mlx_destroy_window(game->mlx_init, game->mlx_wind);
	if (game->mlx_init)
	{
		mlx_destroy_display(game->mlx_init);
		free(game->mlx_init);
	}
	if (game->map.map)
		free_matrix(game->map.map);
}

void	error_free_msg(t_game *game, char *error_msg)
{
	error_free(game);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
