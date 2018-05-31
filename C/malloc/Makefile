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

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

SRC =	malloc.c \
		free.c \
		realloc.c \
		misc.c \
		calloc.c \
		show_alloc_mem.c \
		reallocf.c \
		valloc.c \
		public.c \
		public2.c \
	  
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 # -fsanitize=address
LFLAGS = -L libft -lft -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	@echo "comp start"
	@make -C libft
	$(CC) $(CFLAGS) -shared $(LFLAGS) $(OBJ) -o $(NAME)
	@ln -sf $(NAME) libft_malloc.so 
	@echo "ALL DONE"

clean:
	@echo "cleaning .o"
	@/bin/rm -f $(OBJ)
	@make -C libft clean
	@echo "cleaning .o done"

fclean: clean
	@echo "cleaning NAME"
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft_malloc.so
	@make -C libft fclean
	@echo "cleaning NAME done"

re: fclean all

