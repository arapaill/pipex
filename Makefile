# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/05 11:29:21 by user42            #+#    #+#              #
#    Updated: 2021/08/05 11:44:26 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = 	srcs/main.c srcs/pipex.c
LIB_SRC = libft/ft_exit.c
NAME = pipex
LIB = ar rcs

all : $(NAME)

$(NAME):	
			@$(CC) $(CFLAGS) ${SRC} srcs/main.c -o $(NAME)
			@echo "\033[32m[✓]\033[0m		[$(NAME) compiled]"

%.o: %.c
			$(CC) $(CFLAGS) -c -o $@ $<

clean:
			@rm -f *.o

fclean:	clean
			@rm -f $(NAME)
			
re:			fclean all