/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:51:58 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/25 17:47:15 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "raycaster.h"
#include "renderer.h"
#include "init.h"
#include "mlx.h"
#include "input.h"

int	image_loop(t_game *game)
{
	game->image->image = mlx_new_image(game->mlx->mlx,
	game->param->width, game->param->height);
	game->image->data = mlx_get_data_addr(game->image->image,
	&game->image->bpp, &game->image->ls, &game->image->endian);
	raycast(game);
	render_sprite(game);
	mlx_put_image_to_window(game->mlx->mlx,
	game->mlx->window, game->image->image, 0, 0);
	mlx_destroy_image(game->mlx->mlx, game->image->image);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2 && argc > 3)
	{
		perror("Wrong argument number");
		exit(0);
	}
	init_game(&game);
	parse(argv[1], game->param);
	init_player(game->param, game->player);
	init_sprite(game->sprite, game->param);
	game->mlx->mlx = mlx_init();
	init_texture(game);
	game->mlx->window = mlx_new_window(game->mlx->mlx,
	game->param->width, game->param->height, "cub3d");
	mlx_hook(game->mlx->window, 2,  1L << 0, press_input, game);
	mlx_hook(game->mlx->window, 3,  1L << 1, released_input, game->player);
	mlx_loop_hook(game->mlx->mlx, image_loop, game);
	mlx_loop(game->mlx->mlx);
}
