/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:35:42 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/24 21:33:28 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_file_extension_bonus(char *map_file)
{
	size_t	i;

	i = ft_strlen_endl_bonus(map_file) - 4;
	if (ft_strncmp(&map_file[i], ".ber", 4) == 0)
		return (1);
	return (0);
}

int	check_bor_bonus(t_map_bonus *map)
{
	int	i;

	i = -1;
	while (++i < map->row)
		if (map->map[i][0] != '1' || map->map[i][map->column - 1] != '1')
			return (0);
	i = -1;
	while (++i < map->column)
	{
		if (map->map[0][i] != '1' || map->map[map->row - 1][i] != '1')
		{
			return (0);
		}
	}
	return (1);
}

int	check_str_bonus(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_rect_bonus(t_game_bonus *game)
{
	size_t	row;
	size_t	len;

	row = game->map.column;
	len = 0;
	while (game->map.map[len] != NULL)
	{
		if (row != ft_strlen_endl_bonus(game->map.map[len]))
			return (0);
		len++;
	}
	return (1);
}
