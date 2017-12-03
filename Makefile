# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 10:04:49 by acauchy           #+#    #+#              #
#    Updated: 2017/12/03 15:47:02 by acauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft fillit all clean fclean re

NAME = fillit

SRC_NAME =	main.c \
		import.c \
		utils.c \
		output.c \
		resolve.c validate_tetri.c
SRC_PATH = ./

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./o/

SRCS = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CC = clang
CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -Llibft
LDLIBS = -lft
CPPFLAGS = -I./libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	 @mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -Rf $(OBJ_PATH)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
