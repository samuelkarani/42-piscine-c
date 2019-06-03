# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/01 15:49:26 by smbaabu           #+#    #+#              #
#    Updated: 2018/09/04 00:58:40 by smbaabu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -Iincludes/
NAME = libft.a
_SRCS = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
SRCS = $(patsubst %, srcs/%, $(_SRCS))
OBJECTS = $(_SRCS:.c=.o)

all: $(NAME)
$(NAME):
	$(CC) $(CFLAGS) $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
clean:
	/bin/rm -f $(OBJECTS)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
