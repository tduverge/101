# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbedene <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 16:51:31 by kbedene           #+#    #+#              #
#    Updated: 2017/11/24 11:06:34 by tduverge    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_FILES =\
	count_tet.c\
	fill_board.c\
	ft_filltab.c\
	ft_next_sqrt.c\
	ft_resolve.c\
	ft_write2d.c\
	main.c\
	print_i1.c\
	print_i2.c\
	print_j1.c\
	print_j2.c\
	print_j3.c\
	print_j4.c\
	print_l1.c\
	print_l2.c\
	print_l3.c\
	print_l4.c\
	print_o.c\
	print_s1.c\
	print_s2.c\
	print_soluce.c\
	print_t1.c\
	print_t2.c\
	print_t3.c\
	print_t4.c\
	print_z1.c\
	print_z2.c\
	recup_file.c\
	test.c\
	test_i.c\
	test_j.c\
	test_l.c\
	test_o.c\
	test_s.c\
	test_t.c\
	test_z.c\
	verif_file.c\
	ft_memalloc.c\
	ft_putchar.c\
	ft_putstr.c\
	ft_strlen.c\
	ft_strsub.c\
	ft_bzero.c\
	ft_putstr_fd.c\
	ft_delete.c\
	delete_i.c\
	delete_j.c\
	delete_l.c\
	delete_o.c\
	delete_s.c\
	delete_t.c\
	delete_z.c

SRC = $(addprefix srcs/, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

HEADS = ../header/fillit.h ../header/libft.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

./srcs/%.o: ./srcs/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
