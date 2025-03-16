CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf


SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client

LIBFTDIR    = libft
PRINTF_DIR  = ft_printf
LIBFT       = $(LIBFTDIR)/libft.a
PRINTF      = $(PRINTF_DIR)/libftprintf.a


all: $(LIBFT) $(PRINTF) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	@make -C $(LIBFTDIR)


$(PRINTF):
	@make -C $(PRINTF_DIR)


$(NAME_SERVER): $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(LIBFT) $(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(LIBFT) $(PRINTF) -o $(NAME_CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFTDIR)
	@make clean -C $(PRINTF_DIR)
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re