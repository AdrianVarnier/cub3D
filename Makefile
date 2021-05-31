# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 01:02:57 by avarnier          #+#    #+#              #
#    Updated: 2021/05/31 18:45:12 by avarnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = clang
FLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -lXext -lX11 -lm

INC = sources/include
INC_BONUS = bonus/include
MLX = minilibx-linux

SRC = 	sources/free/free_error.c \
		sources/free/free_exit.c \
		sources/free/free_map_line.c \
		sources/free/free_param_error.c \
		sources/free/free_save.c \
		sources/free/free_cross_exit.c \
		sources/free/free_texture_exit.c \
		sources/free/free_game.c \
		sources/init/init_game.c \
		sources/init/init_param.c \
		sources/init/init_player.c \
		sources/init/init_sprite.c \
		sources/init/init_texture.c \
		sources/input/input.c \
		sources/main/main.c \
		sources/parser/check_error.c \
		sources/parser/check_map.c \
		sources/parser/check_param1.c \
		sources/parser/check_param2.c \
		sources/parser/check_utils1.c \
		sources/parser/check_utils2.c \
		sources/parser/get_map.c \
		sources/parser/get_param1.c \
		sources/parser/get_param2.c \
		sources/parser/get_color_utils.c \
		sources/parser/get_utils.c \
		sources/parser/parse.c \
		sources/raycaster/check_horizontal_intersection1.c \
		sources/raycaster/check_horizontal_intersection2.c \
		sources/raycaster/check_vertical_intersection1.c \
		sources/raycaster/check_vertical_intersection2.c \
		sources/raycaster/raycast.c \
		sources/renderer/render.c \
		sources/renderer/render_sprite.c \
		sources/renderer/render_sprite_utils.c \
		sources/renderer/render_texture.c \
		sources/saver/save.c \
		sources/utils/ft_atoi.c \
		sources/utils/ft_atoi_base.c \
		sources/utils/ft_bzero.c \
		sources/utils/ft_isdigit.c \
		sources/utils/ft_itoa_base.c \
		sources/utils/ft_memcpy.c \
		sources/utils/ft_memmove.c \
		sources/utils/ft_memset.c \
		sources/utils/ft_strchr.c \
		sources/utils/ft_strdup.c \
		sources/utils/ft_strlcat.c \
		sources/utils/ft_strlcpy.c \
		sources/utils/ft_strlen.c \
		sources/utils/get_next_line.c \
		sources/utils/ft_putstr_fd.c \

OBJ = $(addsuffix .o, $(basename $(SRC)))


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L $(MLX) $(LIBS)

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS) -I $(INC) -I $(MLX) -I $(INC_BONUS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
