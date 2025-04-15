CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
LIBFTDIR = libft
PRINTF = ft_printf/libftprintf.a
PRINTFDIR = ft_printf
NAME = push_swap

SRCS = main.c \
		action.c \
		error_free.c \
		list_utils.c \
		normal.c \
		sorting.c \
		stack_init.c \
		tiny_sort.c \
		ft_atol.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFTDIR) -I $(PRINTFDIR) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR) > /dev/null 2>&1

$(PRINTF):
	@$(MAKE) -C $(PRINTFDIR) > /dev/null 2>&1


clean:
	$(MAKE) clean -C $(PRINTFDIR)
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(PRINTFDIR)
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re