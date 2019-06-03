# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smbaabu <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 12:58:20 by smbaabu           #+#    #+#              #
#    Updated: 2018/09/06 12:58:33 by smbaabu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_cat
SRCS = main.c
OBJECTS = *.o

all: $(NAME)
$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
clean:
	/bin/rm -f $(OBJECTS)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
