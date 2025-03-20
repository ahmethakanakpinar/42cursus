/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:35:42 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/20 20:52:08 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_extension(char *map_file)
{
	size_t	i;

	i = ft_strlen_endl(map_file) - 4;
	if (ft_strncmp(&map_file[i], ".ber", 4) == 0)
		return (1);
	return (0);
}

int	check_bor(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->row)
		if (map->map[i][0] != '1' || map->map[i][map->column - 1] != '1')
			return (0);
	i = -1;
	while (++i < map->column)
		if (map->map[0][i] != '1' || map->map[map->row - 1][i] != '1')
		{

printf("kontrol0 %c\n ", map->map[0][i]);
printf("kontrol1 %c\n ", map->map[map->row - 1][i]);
printf("kontrol2 %d\n ", map->row - 1);
printf("kontrol2 %d\n ", i);
return (0);
		}
	return (1);
}



int	check_str(char *str, int c)
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

int	check_rect(t_game *game)
{
	size_t	row;
	size_t	len;

	row = game->map.column;
	len = 0;
	while (game->map.map[len] != NULL)
	{
		if (row != ft_strlen_endl(game->map.map[len]))
			return (0);
		len++;
	}
	return (1);
}