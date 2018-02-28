# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduverge <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 15:11:17 by tduverge          #+#    #+#              #
#    Updated: 2018/02/26 11:58:32 by tduverge    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_FILES = \
		flags.c\
		ft_printf.c\
		pf_litoa_base.c\
		pf_luitoa_base.c\
		pf_special.c\
		pf_str.c\
		pf_applyflags_nb.c\
		pf_applyflags_str.c\
		pf_applyflags_x.c\
		pf_applyflags_o.c\
		pf_d.c\
		pf_s.c\
		pf_u.c\
		pf_c.c\
		pf_upper_c.c\
		pf_upper_s.c\
		pf_p.c\
		pf_base.c\
		pf_percent.c\
		pf_unicode.c

SRC = $(addprefix src/, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

SRC_LIBFT_FILES = \
		ft_atoi.c\
		ft_bzero.c\
		ft_count_words.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_itoa_base.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_memalloc.c\
		ft_memccpy.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memdel.c\
		ft_memmove.c\
		ft_memset.c\
		ft_pgcd.c\
		ft_power.c\
		ft_putchar.c\
		ft_putchar_fd.c\
		ft_putendl.c\
		ft_putendl_fd.c\
		ft_putnbr.c\
		ft_putnbr_fd.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strclr.c\
		ft_strcmp.c\
		ft_strcpy.c\
		ft_strdel.c\
		ft_strdup.c\
		ft_strequ.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strnjoin.c\
		ft_strlcat.c\
		ft_strlen.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strncat.c\
		ft_strncmp.c\
		ft_strncpy.c\
		ft_strnequ.c\
		ft_strnew.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strrev.c\
		ft_strsplit.c\
		ft_strstr.c\
		ft_strsub.c\
		ft_strtrim.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_strsubf.c\
		ft_strjoinf.c

SRC_LIBFT = $(addprefix libft/, $(SRC_LIBFT_FILES))

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIBFT)
	@ar rcs $(NAME) $(OBJ) $(OBJ_LIBFT)
	@echo "\033[32mLibrary created.\033[0m"

./src/%.o: ./src/%.c
	@$(CC) $(FLAGS) -c $< -o $@

./libft/%.o: ./libft/%.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ) $(OBJ_LIBFT)
	@echo "\033[31mObjects deleted.\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[31mLibrary deleted.\033[0m"

re: fclean all
