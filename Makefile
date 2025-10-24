# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchagas- <bchagas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/23 23:10:05 by bchagas-          #+#    #+#              #
#    Updated: 2025/10/23 23:10:13 by bchagas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all	: do_configure

do_configure	:
	./configure

clean	:
	./configure clean

re	: clean all
