/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:16:33 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/24 21:32:34 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_row_bonus(char *map_file, t_game_bonus *game)
{
	char	*temp;
	int		counter;
	int		fd;

	counter = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_free_msg_bonus(game, "Error Failed to open map file");
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		counter++;
		free(temp);
		temp = get_next_line(fd);
	}
	if (counter == 0)
		error_free_msg_bonus(game, "Error Empty file");
	game->map.row = counter;
	close(fd);
}

void	read_row_bonus(char *map_file, t_game_bonus *game)
{
	int		i;
	int		fd;
	char	*temp;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_free_msg_bonus(game, "Error Failed to open map file");
	i = 0;
	while (i < game->map.row)
	{
		temp = get_next_line(fd);
		if (!temp)
			error_free_msg_bonus(game, "Error: Failed to read row");
		game->map.map[i] = trim_free_bonus(temp, "\n");
		if (!game->map.map[i])
			error_free_msg_bonus(game, "Malloc() err");
		i++;
	}
	game->map.map[i] = NULL;
	close(fd);
	game->map.column = ft_strlen_endl_bonus(game->map.map[0]);
}

void	get_map_bonus(char *file_map, t_game_bonus *game)
{
	if (check_file_extension_bonus(file_map) == 0)
		error_free_msg_bonus(game, "Error:invalid map file");
	get_row_bonus(file_map, game);
	game->map.map = malloc ((game->map.row + 1) * sizeof(char *));
	if (!game->map.map)
		error_free_msg_bonus(game, "Malloc() error");
	read_row_bonus(file_map, game);
}
