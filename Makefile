# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 06:03:46 by bchagas-          #+#    #+#              #
#    Updated: 2025/11/17 04:08:16 by bchagas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -I include
MLXFLAGS = -lmlx -lXext -lX11 -lm

SRC = \
	src/main.c \
	src/render.c \
	src/iteration.c \
	src/utils.c \
	 src/init.c \
	src/color.c \
	src/ft_atof.c \
	bonus/hooks_bonus.c \
	bonus/keys_bonus.c \
	bonus/iteration_bonus.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
