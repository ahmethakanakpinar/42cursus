
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf


SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)


NAME_SERVER = server
NAME_CLIENT = client


PRINTF_DIR  = ft_printf
PRINTF      = $(PRINTF_DIR)/libftprintf.a

all: $(PRINTF) $(NAME_SERVER) $(NAME_CLIENT)



$(PRINTF):
	@make -C $(PRINTF_DIR)


$(NAME_SERVER): $(OBJS_SERVER) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF) -o $(NAME_SERVER)


$(NAME_CLIENT): $(OBJS_CLIENT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF) -o $(NAME_CLIENT)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@make clean -C $(PRINTF_DIR)
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	@make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
