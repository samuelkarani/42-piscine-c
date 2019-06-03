# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/03 11:49:46 by smbaabu           #+#    #+#              #
#    Updated: 2018/09/04 01:39:20 by smbaabu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Iincludes -Wall -Wextra -Werror
NAME = do-op
_SRCS = ft_atoi.c ft_ops.c ft_putchar.c ft_putstr.c ft_putnbr.c
SRCS = $(patsubst %, srcs/%, $(_SRCS))
OBJS = $(_SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) main.c $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
.PHONY: all clean fclean re
