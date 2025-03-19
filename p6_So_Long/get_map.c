/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:16:33 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/19 21:04:58 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_row(char *map_file, t_game *game)
{
	char	*temp;
	int		counter;
	int		fd;

	counter = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_free_msg(game, "Error Failed to open map file"); 

	temp = get_next_line(fd);
	
    while ((temp = get_next_line(fd)) != NULL)
    {
        counter++;
        free(temp);
    }
	if (counter == 0)
		error_free_msg(game, "Error Empty file"); 


	game->map.row = counter;
	close(fd);
}

void	read_row(char *map_file, t_game *game)
{
	int	i;
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		error_free_msg(game, "Error Failed to open map file"); 

	i = 0;
    while (i < game->map.row)
    {
        char *temp = get_next_line(fd);
        if (!temp)
			error_free_msg(game, "Error: Failed to read row"); 
        
        game->map.map[i] = trim_free(temp, "\n");
        if (!game->map.map[i])
			error_free_msg(game, "Malloc() err"); 
        i++;
    }
	game->map.map[i] = NULL;
	close(fd);
	game->map.column = ft_strlen_endl(game->map.map[0]);
}

void	get_map(char *file_map, t_game *game)
{
	get_row(file_map, game);
	game->map.map = malloc((game->map.row + 1) * sizeof(char *));
	if (!game->map.map)
		error_free_msg(game, "Malloc() error"); 
	read_row(file_map, game);
}