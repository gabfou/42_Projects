#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfournie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/03 10:46:46 by gfournie          #+#    #+#              #
#    Updated: 2015/06/03 10:46:49 by gfournie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


NAME = libfts.a
SRC = Part1/ft_bzero.s\
	  Part1/ft_strcat.s\
	  Part1/ft_isalpha.s\
	  Part1/ft_isdigit.s\
	  Part1/ft_isalnum.s\
	  Part1/ft_isascii.s\
	  Part1/ft_isprint.s\
	  Part1/ft_toupper.s\
	  Part1/ft_tolower.s\
	  Part1/ft_puts.s\
	  Part2/ft_strlen.s\
	  Part2/ft_memset.s\
	  Part2/ft_memcpy.s\
	  Part2/ft_strdup.s\
	  Bonus/ft_islower.s\
	  Bonus/ft_isupper.s\
	  Part3/ft_cat.s
OBJ = $(SRC:.s=.o)

all: $(NAME)
$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

test : $(NAME)
	gcc -Wall -Werror -Wextra main.c -L./ -lfts -o test_lib

%.o: %.s
	~/.brew/Cellar/nasm/2.11.08/bin/nasm -f macho64 $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

1:
	./test_lib part1

2:
	./test_lib part2

3:
	./test_lib part3
b:
	./test_lib bonus

a: 1 2 b
