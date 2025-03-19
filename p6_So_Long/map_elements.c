/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:35:32 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/19 21:03:20 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ecp(t_game *game)
{
	if (game->map.exit == 0 || game->map.exit > 1)
		error_free_msg(game, "Error: Invalid number of exit");
	if (game->map.collectibles == 0)
		error_free_msg(game, "Error: Invalid number of collectibles");
	if (game->map.player == 0 || game->map.player > 1)
		error_free_msg(game, "Error: Invalid number of player");
}

void	check_count_el(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map.row)
	{
		col = 0;
		while (col < game->map.column)
		{
			if (check_str("ECP01", game->map.map[row][col]) == 0)
				error_free_msg(game, "Error: Invalid element in the map");
			if (game->map.map[row][col] == 'E')
				game->map.exit++;
			else if (game->map.map[row][col] == 'C')
				game->map.collectibles++;
			else if (game->map.map[row][col] == 'P')
			{
				game->map.player++;
				game->map.player_position = (t_position){col, row};
			}
			col++;
		}
		row++;
	}
	check_ecp(game);
}


void	unioncheck(t_game *game)
{
	if (check_rect(game) == 0)
		error_free_msg(game, "Error: Map is not rectangular");
	check_count_el(game);
	if (check_bor(&game->map) == 0)
		error_free_msg(game, "Error : Invalid map borders");
	check_path(game);
}