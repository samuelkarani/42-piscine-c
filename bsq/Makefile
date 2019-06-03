CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
SRCS = ft_bsq.c ft_read_parse.c ft_logic_helpers.c ft_putchar.c ft_validate.c ft_putstr.c ft_putnbr.c ft_strcat.c ft_strcpy.c ft_logic.c ft_read_map.c ft_atoi.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME):
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
clean:
	@/bin/rm -f $(OBJS)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re