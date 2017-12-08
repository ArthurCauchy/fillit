# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 10:04:49 by acauchy           #+#    #+#              #
#    Updated: 2017/12/08 15:13:47 by arthur           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: libft all clean fclean re

NAME = fillit

SRC_NAME =	main.c \
		import.c \
		utils.c \
		output.c \
		resolve.c \
		validate_tetri.c
SRC_PATH = ./

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./o/

SRCS = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CC = clang
CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -Ilibft

all: $(NAME)

libft:
	make -C libft/

$(NAME): libft $(OBJS)
	$(CC) $(OBJS) -o $@ libft/libft.a $(CPPFLAGS)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	 @mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $< $(CPPFLAGS)

clean:
	rm -Rf $(OBJ_PATH)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
