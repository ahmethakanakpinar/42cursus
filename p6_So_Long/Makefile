CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -lm -lXext -lX11
LIBFT = libft/libft.a
LIBFTDIR = libft
PRINTF = ft_printf/libftprintf.a
PRINTFDIR = ft_printf
GNL = get_next_line/get_next_line.a
GNLDIR = get_next_line
MLX = minilibx-linux/libmlx.a
MLXDIR = minilibx-linux
NAME = so_long

SRCS = map_elements.c \
    map_pathfinding.c \
    map_validation.c \
    get_map.c \
    free_utils.c \
    init_mlx.c \
    init_game.c \
    loop.c \
    player.c \
    render.c \
    utils.c \
    main.c

BONUS_DIR = bonus
BONUS_SRCS = $(BONUS_DIR)/map_elements_bonus.c \
	$(BONUS_DIR)/map_pathfinding_bonus.c \
	$(BONUS_DIR)/map_validation_bonus.c \
	$(BONUS_DIR)/get_map_bonus.c \
	$(BONUS_DIR)/free_utils_bonus.c \
	$(BONUS_DIR)/init_mlx_bonus.c \
	$(BONUS_DIR)/init_game_bonus.c \
	$(BONUS_DIR)/loop_bonus.c \
	$(BONUS_DIR)/player_bonus.c \
	$(BONUS_DIR)/render_bonus.c \
	$(BONUS_DIR)/utils_bonus.c \
	$(BONUS_DIR)/main_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)

bonus: $(BONUS_DIR)/$(NAME)_bonus

$(BONUS_DIR)/$(NAME)_bonus: $(BONUS_OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(GNL) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(BONUS_DIR)/$(NAME)_bonus

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFTDIR) -I $(PRINTFDIR) -I $(GNLDIR) -I $(MLXDIR) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) > /dev/null 2>&1

$(PRINTF):
	@$(MAKE) -C $(PRINTFDIR) > /dev/null 2>&1

$(GNL):
	@$(MAKE) -C $(GNLDIR) > /dev/null 2>&1

$(MLX):
	@$(MAKE) -C $(MLXDIR) > /dev/null 2>&1

clean:
	$(MAKE) clean -C $(GNLDIR)
	$(MAKE) clean -C $(PRINTFDIR)
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C $(GNLDIR)
	$(MAKE) fclean -C $(PRINTFDIR)
	$(MAKE) fclean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MLXDIR)
	$(RM) $(NAME) $(BONUS_DIR)/$(NAME)_bonus


re: fclean all

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file=valgrind_so_long_out.txt ./$(NAME) $(ARGS)

valgrind_bonus:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file=valgrind_so_long_out.txt ./$(BONUS_DIR)/$(NAME)_bonus $(ARGS)

get:
	git clone https://github.com/42Paris/minilibx-linux.git

norm:
	rm -rf minilibx-linux
	norminette
	$(MAKE) get

.PHONY: all clean fclean re