# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 01:02:57 by avarnier          #+#    #+#              #
#    Updated: 2021/03/27 01:04:45 by avarnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = clang
FLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -lXext -lX11 -lm

INC = include
MLX = minilibx-linux

SRC = 	free/free_error.c \
		free/free_exit.c \
		free/free_map_line.c \
		free/free_param_error.c \
		init/init_game.c \
		init/init_param.c \
		init/init_player.c \
		init/init_sprite.c \
		init/init_texture.c \
		input/input.c \
		main/main.ci \
		parser/check_error.c \
		parser/check_map.c \
		parser/check_param1.c \
		parser/check_param2.c \
		parser/check_utils1.c \
		parser/check_utils2.c \
		parser/get_map.c \
		parser/get_param1.c \
		parser/get_param2.c \
		parser/get_utils.c \
		parser/parse.c \
		raycaster/check_horizontal_intersection1.c \
		raycaster/check_horizontal_intersection2.c \
		raycaster/check_vertical_intersection1.c \
		raycaster/check_vertical_intersection2.c \
		raycaster/raycast.c \
		renderer/render.c \
		renderer/render_sprite.c \
		renderer/render_sprite_utils.c \
		renderer/render_texture.c \
		saver/save.c \
		saver/free_save.c \
		utils/ft_atoi.c \
		utils/ft_atoi_base.c \
		utils/ft_bzero.c \
		utils/ft_isdigit.c \
		utils/ft_itoa_base.c \
		utils/ft_memcpy.c \
		utils/ft_memmove.c \
		utils/ft_memset.c \
		utils/ft_strchr.c \
		utils/ft_strdup.c \
		utils/ft_strlcat.c \
		utils/ft_strlcpy.c \
		utils/ft_strlen.c \
		utils/get_next_line.c \

OBJ = $(addsuffix .o, $(basename $(SRC)))


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L $(MLX) $(LIBS)

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS) -I $(INC) -I $(MLX)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
