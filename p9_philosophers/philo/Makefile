NAME = philo
CFLAGS = -Wall -Wextra -Werror -g -pthread

SRCS = args_validation.c  init.c  main.c  monitor.c  routines.c  utils.c time.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

main:
	make re
	make clean
	clear

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re


leak: all
	valgrind --tool=helgrind ./$(NAME) 4 410 200 200

memcheck: all
	valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose ./$(NAME) 4 410 200 200

.PHONY: all clean fclean re leak memcheck