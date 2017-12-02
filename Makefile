# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 10:04:49 by acauchy           #+#    #+#              #
#    Updated: 2017/12/02 14:30:45 by acauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft

CC = clang

FLAGS = -Wall -Wextra -Werror

NAME = fillit

SRCS = main.c import.c utils.c output.c resolve.c validate_tetri.c

OBJS = main.o import.o utils.o output.o resolve.o validate_tetri.o

all: $(NAME)

libft:
	make -C libft/ fclean && make -C libft/

$(OBJS):
	$(CC) -c $(SRCS) $(FLAGS) -I./libft

$(NAME): libft $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L./libft/ -lft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
