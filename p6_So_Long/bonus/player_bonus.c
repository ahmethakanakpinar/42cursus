/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 19:15:01 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/24 21:33:37 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player_block_bonus(t_game_bonus *game)
{
	char	*moves_str;

	mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
		game->block.player->img,
		B_S_BONUS * game->map.player_position.x,
		B_S_BONUS * game->map.player_position.y);
	mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
		game->block.wall, 0, 0);
	moves_str = ft_itoa(game->moves);
	mlx_string_put(game->mlx_init, game->mlx_wind, 10, 15, 0xFFFFFF, moves_str);
	ft_printf("Move number: %d\n", game->moves);
	free(moves_str);
}

void	which_block_bonus(t_game_bonus *game)
{
	if (game->map.map[game->map.player_position.y]
		[game->map.player_position.x] == 'C')
	{
		game->map.map[game->map.player_position.y]
		[game->map.player_position.x] = '0';
		game->map.collectibles -= 1;
		return ;
	}
	if (game->map.map[game->map.player_position.y]
		[game->map.player_position.x] == 'E'
		&& game->map.collectibles == 0)
	{
		ft_printf("You won\n");
		quit_game_bonus(game);
	}
}

void	update_left_behind_block_bonus(t_game_bonus *game)
{
	if (game->map.map[game->map.player_position.y]
		[game->map.player_position.x] == 'E')
	{
		mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
			game->block.exit, B_S_BONUS * game->map.player_position.x,
			B_S_BONUS * game->map.player_position.y);
	}
	else
		mlx_put_image_to_window(game->mlx_init, game->mlx_wind,
			game->block.floor, B_S_BONUS * game->map.player_position.x,
			B_S_BONUS * game->map.player_position.y);
}

void	update_player_pos_bonus(t_game_bonus *game, bool horizontal, int length)
{
	if (horizontal)
	{
		if (game->map.map[game->map.player_position.y]
			[game->map.player_position.x + length] == '1')
			return ;
		update_left_behind_block_bonus(game);
		game->map.player_position.x += length;
	}
	else
	{
		if (game->map.map[game->map.player_position.y
				+ length][game->map.player_position.x] == '1')
			return ;
		update_left_behind_block_bonus(game);
		game->map.player_position.y += length;
	}
	game->moves++;
	which_block_bonus(game);
	put_player_block_bonus(game);
}
