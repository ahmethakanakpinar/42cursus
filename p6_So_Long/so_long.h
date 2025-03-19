/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:35:56 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/19 22:02:25 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <fcntl.h>

# define BLOCK_SIZE 32


typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_block
{
	void		*exit;
	void		*collectibles;
	void		*player;
	void		*wall;
	void		*floor;
}				t_block;

typedef struct s_map
{
	char		**map;
	int			row;
	int			column;
	int			collectibles;
	int			player;
	int			exit;
	t_position	player_position;
}				t_map;

typedef struct s_game
{
	void		*mlx_init;
	void		*mlx_wind;
	int			moves;
	t_block		block;
	t_map		map;
}				t_game;

t_game			init_game(void);
void	get_map(char *file_map, t_game *game);
void	read_row(char *map_file, t_game *game);
void	get_row(char *map_file, t_game *game);
char	*trim_free(char *s1, char const *set);
size_t	ft_strlen_endl(char *str);
char	*f_strchr(const char *str, int c);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int	check_file_extension(char *map_file);
int	check_bor(t_map *map);
int	check_str(char *str, int c);
int	check_rect(t_game *game);
char	**copy_map(t_game *game);
int	flood_fill(t_map *map, t_position curr, char **temp_map);
void	reset_flood_fill(t_map *map, t_position start, char **temp_map, int *result);
void	check_path(t_game *game);
void	check_ecp(t_game *game);
void	check_count_el(t_game *game);
void	unioncheck(t_game *game);
void	free_blocks(t_game *game);
void	free_matrix(char **matrix);
void	error_free(t_game *game);
void	error_free_msg(t_game *game, char *error_msg);
#endif
