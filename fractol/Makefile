# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/02/16 17:27:01 by tduverge     #+#   ##    ##    #+#        #
#    Updated: 2018/02/16 18:42:17 by tduverge    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fractol

SRC_FILES = burning.c \
			color.c \
			fill_pixel.c \
			fractol.c \
			julia.c \
			key_funct.c \
			legend.c \
			mandel.c \
			mouse_funct.c \
			init.c

SRC = $(addprefix src/, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

HEAD_FILES = fractol.h \
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
