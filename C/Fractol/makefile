#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfournie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 12:38:41 by gfournie          #+#    #+#              #
#    Updated: 2015/05/01 19:11:04 by gfournie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

FLAG = -Wall -Werror -Wextra -O3 #-framework OpenGL -framework AppKit#

SRC = main.c misc.c julia.c mandel.c t.c newton.c t2.c

OBJ = main.o misc.o julia.o mandel.o t.o newton.o t2.o  -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	gcc -o $(NAME) $(FLAG) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all