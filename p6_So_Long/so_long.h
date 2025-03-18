#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "minilibx-linux/mlx.h"
# include <stdbool.h>
# include <fcntl.h>

# define BLOCK_SIZE 64


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
void	read_row(char *map_file, t_game *game);
void	get_row(char *map_file, t_game *game);
char	*trim_free(char *s1, char const *set);
size_t	ft_strlen_endl(char *str);
char	*f_strchr(const char *str, int c);
char	*ft_strncpy(char *dest, const char *src, size_t n);

#endif
