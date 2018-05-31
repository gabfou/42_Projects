# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibuchwal <ibuchwal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/30 14:15:15 by gudepard          #+#    #+#              #
#    Updated: 2016/03/09 20:55:29 by ibuchwal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	libft.a

SRC_DIR				=	srcs
INCLUDE_DIR			=	.

SRC 				=	ft_memset.c        \
						ft_bzero.c         \
						ft_memcpy.c        \
						ft_memccpy.c       \
						ft_memchr.c        \
						ft_memcmp.c        \
						ft_strlen.c        \
						ft_strdup.c        \
						ft_strcpy.c        \
						ft_strncpy.c       \
						ft_strcat.c        \
						ft_strncat.c       \
						ft_strlcat.c       \
						ft_strchr.c        \
						ft_strrchr.c       \
						ft_strstr.c        \
						ft_strnstr.c       \
						ft_strcmp.c        \
						ft_strncmp.c       \
						ft_atoi.c          \
						ft_isalpha.c       \
						ft_isdigit.c       \
						ft_isalnum.c       \
						ft_isascii.c       \
						ft_isprint.c       \
						ft_toupper.c       \
						ft_tolower.c       \
						ft_strnew.c        \
						ft_strdel.c        \
						ft_strclr.c        \
						ft_striter.c       \
						ft_striteri.c      \
						ft_strmap.c        \
						ft_strmapi.c       \
						ft_strequ.c        \
						ft_strnequ.c       \
						ft_strsub.c        \
						ft_strjoin.c       \
						ft_strtrim.c       \
						ft_putchar.c       \
						ft_putstr.c        \
						ft_putendl.c       \
						ft_putnbr.c        \
						ft_putchar_fd.c    \
						ft_putstr_fd.c     \
						ft_putendl_fd.c    \
						ft_djb2.c          \
						ft_max.c           \
						# ft_min.c           \

OBJ_DIR				=	objs
OBJ					=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

COMPILER			=	gcc
CFLAGS				=	-O3 -Wall -Wextra -Werror -I$(INCLUDE_DIR) -c

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJ)
	rm -Rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
