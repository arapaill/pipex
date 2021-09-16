# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/05 11:29:21 by user42            #+#    #+#              #
#    Updated: 2021/09/16 16:37:15 by arapaill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = 	srcs/main.c srcs/pipex.c
LIB_SRC = srcs/libft/ft_exit.c srcs/libft/ft_split.c srcs/libft/ft_strichr.c \
		srcs/libft/ft_strncmp.c srcs/libft/ft_strlcpy.c srcs/libft/ft_strdup.c \
		srcs/libft/ft_strjoin.c srcs/libft/ft_memcpy.c
NAME = pipex
LIB = ar rcs

all : $(NAME)

$(NAME):	
			@$(CC) $(CFLAGS) ${SRC} ${LIB_SRC} -o $(NAME)
			@echo "\033[32m[✓]\033[0m		[$(NAME) compiled]"

%.o: %.c
			$(CC) $(CFLAGS) -c -o $@ $<

clean:
			@rm -f *.o

fclean:	clean
			@rm -f $(NAME)
			
re:			fclean all

