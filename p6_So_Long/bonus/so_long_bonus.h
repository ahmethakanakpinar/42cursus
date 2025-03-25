/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakpinar <aakpinar@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:35:56 by aakpinar          #+#    #+#             */
/*   Updated: 2025/03/24 21:55:42 by aakpinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <stdbool.h>
# include <fcntl.h>

# define W_B_BONUS "bonus/textures_bonus/wall_bonus.xpm"
# define F_B_BONUS "bonus/textures_bonus/floor_bonus.xpm"
# define P_R_BONUS "bonus/textures_bonus/character/pac_open_right_bonus.xpm"
# define P_L_BONUS "bonus/textures_bonus/character/pac_open_left_bonus.xpm"
# define P_U_BONUS "bonus/textures_bonus/character/pac_open_up_bonus.xpm"
# define P_D_BONUS "bonus/textures_bonus/character/pac_open_down_bonus.xpm"
# define C_B_BONUS "bonus/textures_bonus/pacdot_bonus.xpm"
# define E_B_BONUS "bonus/textures_bonus/portal_bonus.xpm"
# define B_S_BONUS 64

typedef struct s_position_bonus
{
	int			x;
	int			y;
}				t_position_bonus;

typedef struct s_player_bonus
{
	void	*img_up;
	void	*img_down;
	void	*img_left;
	void	*img_right;
	void	*img;
}			t_player_bonus;

typedef struct s_block_bonus
{
	void			*exit;
	void			*collectibles;
	t_player_bonus	*player;
	void			*wall;
	void			*floor;
}					t_block_bonus;

typedef struct s_map_bonus
{
	char				**map;
	int					row;
	int					column;
	int					collectibles;
	int					player;
	int					exit;
	t_position_bonus	player_position;
}						t_map_bonus;

typedef struct s_game_bonus
{
	void				*mlx_init;
	void				*mlx_wind;
	int					moves;
	t_block_bonus		block;
	t_map_bonus			map;
}						t_game_bonus;

t_game_bonus	init_game_bonus(void);
void			get_map_bonus(char *file_map, t_game_bonus *game);
void			read_row_bonus(char *map_file, t_game_bonus *game);
void			get_row_bonus(char *map_file, t_game_bonus *game);
char			*trim_free_bonus(char *s1, char const *set);
size_t			ft_strlen_endl_bonus(char *str);
char			*f_strchr_bonus(const char *str, int c);
char			*ft_strncpy_bonus(char *dest, const char *src, size_t n);
int				check_file_extension_bonus(char *map_file);
int				check_bor_bonus(t_map_bonus *map);
int				check_str_bonus(char *str, int c);
int				check_rect_bonus(t_game_bonus *game);
char			**copy_map_bonus(t_game_bonus *game);
int				flood_fill_bonus(t_map_bonus *map, t_position_bonus curr,
					char **temp_map);
void			reset_flood_fill_bonus(t_map_bonus *map, t_position_bonus start,
					char **temp_map, int *result);
void			check_path_bonus(t_game_bonus *game);
void			check_ecp_bonus(t_game_bonus *game);
void			check_count_el_bonus(t_game_bonus *game);
void			unioncheck_bonus(t_game_bonus *game);
void			free_blocks_bonus(t_game_bonus *game);
void			free_matrix_bonus(char **matrix);
void			error_free_bonus(t_game_bonus *game);
void			error_free_msg_bonus(t_game_bonus *game, char *error_msg);
void			init_mlx_bonus(t_game_bonus *game);
void			error_xpm_bonus(t_game_bonus *game);
void			xpm_to_image_bonus(t_game_bonus *game);
void			img_to_window_bonus(t_game_bonus *game);
void			render_map_bonus(t_game_bonus *game);
int				quit_game_bonus(t_game_bonus *game);
int				on_press_bonus(int key, t_game_bonus *game);
void			hook_n_run_bonus(t_game_bonus *game);
void			put_player_block_bonus(t_game_bonus *game);
void			which_block_bonus(t_game_bonus *game);
void			update_left_behind_block_bonus(t_game_bonus *game);
void			update_player_pos_bonus(t_game_bonus *game,
					bool horizontal, int length);
#endif
