# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 10:04:49 by acauchy           #+#    #+#              #
#    Updated: 2017/11/29 17:27:23 by acauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft

CC = clang

FLAGS = -Wall -Wextra -Werror

NAME = fillit

SRCS = fillit.c

OBJS = fillit.o

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
