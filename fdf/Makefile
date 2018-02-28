# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/01/23 16:57:57 by tduverge     #+#   ##    ##    #+#        #
#    Updated: 2018/01/25 09:14:23 by tduverge    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf

SRC_FILES = get_next_line.c \
			main.c \
			matrix_invert.c \
			matrix_make.c \
			matrix_operation.c \
			parsing.c \
			drawer.c \
			calc.c \
			modif.c \
			legend.c \
			fill_pixel.c \

SRC = $(addprefix src/, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

HEAD_FILES = fdf.h \
			 get_next_line.h \
			 libft.h

HEAD = $(addprefix header/, $(HEAD_FILES))

LIBFT = libft/libft.a

MINILIBX = minilibx_macos/libmlx.a

CC = gcc

FLAGS = -Wall -Werror -Wextra -ggdb

MLX_FLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/
	$(CC) $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX)

./src/%.o: ./src/%.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C ./libft/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all
