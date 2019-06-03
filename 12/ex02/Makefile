# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 15:39:01 by smbaabu           #+#    #+#              #
#    Updated: 2018/09/06 15:39:02 by smbaabu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -I -Wall -Wextra -Werror
NAME = ft_tail
SRCS = helpers.c
OBJECTS = *.o

all: $(NAME)
$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) main.c $(SRCS)
clean:
	/bin/rm -f $(OBJECTS)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re