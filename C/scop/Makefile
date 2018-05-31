# **************************************************************************** #
#	                                                                           #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/23 23:09:04 by jromagna          #+#    #+#              #
#    Updated: 2016/03/28 23:40:51 by ibuchwal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop

NAMET = scoptriche

SRC =	main.c \
		objreader.c \
		fatoi.c \
		misc.c \
		misc2.c \

SRC2 =	readerbmp.c \

SRC3 =	triche.c \
		
	  
OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror # -g3 -fsanitize=address
LFLAGS = -L libft -lft -lpthread -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
	@echo "mlx start"
	@make -C mlx
	@make -C libft
	# @make -C SOIL2-master
	@echo "mlx ok"
	@echo "comp start"
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(OBJ2) -o $(NAME) mlx/libmlx.a
	@echo "ALL DONE"

$(NAMET): $(OBJ) $(OBJ3)
	@echo "mlx start"
	@make -C mlx
	@make -C libft
	@make -C SOIL2-master
	@echo "mlx ok"
	@echo "comp start"
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(OBJ3) -o $(NAMET) mlx/libmlx.a SOIL2-master/libSOIL2.a
	@echo "ALL DONE"

norm:
	norminette **[ch]

clean:
	@echo "cleaning .o"
	@/bin/rm -f $(OBJ) $(OBJ2) $(OBJ3)
	@make -C libft clean
	@make -C SOIL2-master fclean
	@echo "cleaning .o done"

fclean: clean
	@echo "cleaning NAME"
	@/bin/rm -f $(NAME) $(NAMET)
	@make -C libft clean
	@make -C SOIL2-master fclean
	@echo "cleaning NAME done"

re: fclean all

