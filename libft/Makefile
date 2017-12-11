# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpaquet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 17:47:16 by cpaquet           #+#    #+#              #
#    Updated: 2017/12/11 14:30:14 by acauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a

SRC_NAME =	ft_atoi.c \
			ft_memcpy.c \
			ft_putstr_fd.c \
			ft_strjoin.c \
			ft_strsplit.c \
			ft_bzero.c \
			ft_memdel.c \
			ft_strcat.c \
			ft_strlen.c \
			ft_strstr.c \
			ft_isalnum.c \
			ft_memmove.c \
			ft_strchr.c \
			ft_strmap.c \
			ft_strsub.c \
			ft_isalpha.c \
			ft_memset.c \
			ft_strclr.c \
			ft_strmapi.c \
			ft_strtrim.c \
			ft_isdigit.c \
			ft_putchar.c \
			ft_strcmp.c \
			ft_strncat.c \
			ft_tolower.c \
			ft_isprint.c \
			ft_putchar_fd.c \
			ft_strcpy.c \
			ft_strncmp.c \
			ft_toupper.c \
			ft_itoa.c \
			ft_putendl.c \
			ft_strdel.c \
			ft_strncpy.c \
			ft_memalloc.c \
			ft_putendl_fd.c \
			ft_strdup.c \
			ft_strnequ.c \
			ft_memccpy.c \
			ft_putnbr.c \
			ft_strequ.c \
			ft_strnew.c \
			ft_memchr.c \
			ft_putnbr_fd.c \
			ft_striter.c \
			ft_strnstr.c \
			ft_memcmp.c \
			ft_putstr.c \
			ft_striteri.c \
			ft_strrchr.c \
			ft_strlcat.c \
			ft_isascii.c \
			ft_lstnew.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_islower.c \
			ft_isspace.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_lstpushback.c \
			ft_puthex.c \
			ft_puthex_fd.c \
			ft_putnstr.c \
			ft_sqrt.c \
			ft_swap.c
SRC_PATH = ./

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = ./o/

SRCS = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJS = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CC = clang
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $^
	ranlib libft.a

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -Rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re : fclean all
