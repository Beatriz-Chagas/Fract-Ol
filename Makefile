# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchagas- <bchagas-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/15 06:03:46 by bchagas-          #+#    #+#              #
#    Updated: 2025/11/15 06:55:34 by bchagas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -lXext -lX11 -lm

SRC = main.c render.c iteration.c utils.c init.c hooks.c keys.c color.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
