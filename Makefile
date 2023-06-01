# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tuukka <tuukka@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 12:40:05 by ttikanoj          #+#    #+#              #
#    Updated: 2023/01/06 19:37:41 by tuukka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRC = ./push_swap.c push_swap_ops1.c push_swap_ops2.c push_swap_ops3.c \
		push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c \
		push_swap_small.c push_swap_big.c ft_atoi.c push_swap_string.c \
		ft_split.c ft_strdup.c ft_strlen.c

OBJ = ./push_swap.o push_swap_ops1.o push_swap_ops2.o push_swap_ops3.o \
		push_swap_utils1.o push_swap_utils2.o push_swap_utils3.o \
		push_swap_small.o push_swap_big.o ft_atoi.o push_swap_string.o \
		ft_split.o ft_strdup.o ft_strlen.o

HEADERS = -I ./includes

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(HEADERS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
