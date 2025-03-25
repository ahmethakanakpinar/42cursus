/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:51:01 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/24 21:39:42 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_mlx_bonus(t_game_bonus *game)
{
	game->mlx_init = mlx_init();
	if (!game->mlx_init)
		error_free_msg_bonus(game, "Error : failed to initialize mlx");
	game->mlx_wind = mlx_new_window(game->mlx_init, game->map.column
			* B_S_BONUS, game->map.row * B_S_BONUS, "so_long_bonus");
	if (!game->mlx_wind)
		error_free_msg_bonus(game, "Error : Failed to open new window");
}
