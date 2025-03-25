/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:35:32 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/24 21:33:02 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_ecp_bonus(t_game_bonus *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		error_free_msg_bonus(game, "Error: Invalid number of exit");
	if (game->map.collectibles == 0)
		error_free_msg_bonus(game, "Error: Invalid number of collectibles");
	if (game->map.player == 0 || game->map.player > 1)
		error_free_msg_bonus(game, "Error: Invalid number of player");
}

void	check_count_el_bonus(t_game_bonus *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map.row)
	{
		col = 0;
		while (col < game->map.column)
		{
			if (check_str_bonus("ECP01", game->map.map[row][col]) == 0)
				error_free_msg_bonus(game, "Error: Invalid element in the map");
			if (game->map.map[row][col] == 'E')
				game->map.exit++;
			else if (game->map.map[row][col] == 'C')
				game->map.collectibles++;
			else if (game->map.map[row][col] == 'P')
			{
				game->map.player++;
				game->map.player_position = (t_position_bonus){col, row};
			}	
			col++;
		}
		row++;
	}
	check_ecp_bonus(game);
}

void	unioncheck_bonus(t_game_bonus *game)
{
	if (check_rect_bonus(game) == 0)
		error_free_msg_bonus(game, "Error: Map is not rectangular");
	check_count_el_bonus(game);
	if (check_bor_bonus(&game->map) == 0)
		error_free_msg_bonus(game, "Error : Invalid map borders");
	check_path_bonus(game);
}
