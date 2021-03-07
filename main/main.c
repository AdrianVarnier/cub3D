/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:51:58 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/06 21:29:29 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "raycaster.h"
#include "init.h"
#include "mlx.h"
#include "input.h"

int	image_loop(t_game *game)
{
	game->image->image = mlx_new_image(game->minilibx->minilibx,
	game->param->width, game->param->height);
	game->image->data = mlx_get_data_addr(game->image->image,
	&game->image->bpp, &game->image->ls, &game->image->endian);
	raycast(game);
	mlx_put_image_to_window(game->minilibx->minilibx,
	game->minilibx->window, game->image->image, 0, 0);
	mlx_destroy_image(game->minilibx->minilibx, game->image->image);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		perror("Wrong argument number");
		exit(0);
	}
	init_game(&game);
	parse(argv[1], game->param);
	init_player(game->param, game->player);
	game->minilibx->minilibx = mlx_init();
	init_texture(game);
	game->minilibx->window = mlx_new_window(game->minilibx->minilibx,
	game->param->width, game->param->height, "cub3d");
	mlx_hook(game->minilibx->window, 2, 1L<<0, press_input, game);
	mlx_hook(game->minilibx->window, 3, 1L<<1, released_input, game->player);
	mlx_loop_hook(game->minilibx->minilibx, image_loop, game);
	mlx_loop(game->minilibx->minilibx);
}
