/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinding_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:35:37 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/24 21:55:44 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**copy_map_bonus(t_game_bonus *game)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_calloc(game->map.row + 1, sizeof(char *));
	if (!temp)
		error_free_msg_bonus(game, "Calloc() err");
	while (i < game->map.row)
	{
		temp[i] = ft_strdup(game->map.map[i]);
		if (!temp[i])
		{
			free_matrix_bonus(temp);
			error_free_msg_bonus(game, "Malloc() err");
		}
		i++;
	}
	return (temp);
}

int	flood_fill_bonus(t_map_bonus *map, t_position_bonus curr, char **temp_map)
{
	static int	collectibles;
	static int	exit_flag;

	if (curr.x < 0 || curr.x >= map->column || curr.y < 0 || curr.y >= map->row)
		return (0);
	if (temp_map[curr.y][curr.x] == '1' || temp_map[curr.y][curr.x] == 'F')
		return (0);
	if (temp_map[curr.y][curr.x] == 'C')
		collectibles++;
	else if (temp_map[curr.y][curr.x] == 'E')
		exit_flag = 1;
	temp_map[curr.y][curr.x] = 'F';
	flood_fill_bonus(map, (t_position_bonus){curr.x + 1, curr.y}, temp_map);
	flood_fill_bonus(map, (t_position_bonus){curr.x - 1, curr.y}, temp_map);
	flood_fill_bonus(map, (t_position_bonus){curr.x, curr.y + 1}, temp_map);
	flood_fill_bonus(map, (t_position_bonus){curr.x, curr.y - 1}, temp_map);
	return (collectibles == map->collectibles && exit_flag);
}

void	reset_flood_fill_bonus(t_map_bonus *map, t_position_bonus start,
	char **temp_map, int *result)
{
	*result = flood_fill_bonus(map, start, temp_map);
}

void	check_path_bonus(t_game_bonus *game)
{
	char	**temp_map;
	int		result;

	temp_map = copy_map_bonus(game);
	reset_flood_fill_bonus(&game->map, game->map.player_position,
		temp_map, &result);
	if (!result)
	{
		free_matrix_bonus(temp_map);
		error_free_msg_bonus(game, "Error: Invalid path");
	}
	free_matrix_bonus(temp_map);
}
