/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pathfinding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:35:37 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/20 19:09:38 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_calloc(game->map.row + 1, sizeof(char *));
	if (!temp)
		error_free_msg(game, "Calloc() err");
	while (i < game->map.row)
	{
		temp[i] = ft_strdup(game->map.map[i]);
		if (!temp[i])
		{
			free_matrix(temp);
			error_free_msg(game, "Malloc() err");
		}
		i++;
	}
	return (temp);
}

int	flood_fill(t_map *map, t_position curr, char **temp_map)
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
	flood_fill(map, (t_position){curr.x + 1, curr.y}, temp_map);
	flood_fill(map, (t_position){curr.x - 1, curr.y}, temp_map);
	flood_fill(map, (t_position){curr.x, curr.y + 1}, temp_map);
	flood_fill(map, (t_position){curr.x, curr.y - 1}, temp_map);
	return (collectibles == map->collectibles && exit_flag);
}

void	reset_flood_fill(t_map *map, t_position start, char **temp_map,
        int *result)
{
    // int	collectibles;
    // int	exit_flag;

    // collectibles = 0;
    // exit_flag = 0;
    *result = flood_fill(map, start, temp_map);
}

void	check_path(t_game *game)
{
	char	**temp_map;
	int		result;

	temp_map = copy_map(game);
	reset_flood_fill(&game->map, game->map.player_position, temp_map, &result);
	if (!result)
	{
		free_matrix(temp_map);
		error_free_msg(game, "Error: Invalid path");
	}
	free_matrix(temp_map);
}