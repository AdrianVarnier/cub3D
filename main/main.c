/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 00:51:58 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/01 14:35:39 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "raycaster.h"
#include "init.h"
#include "mlx.h"

int	image_loop(t_game *game)
{
	game->image->image = mlx_new_image(game->minilibx->minilibx,
	game->param->width, game->param->height);
	game->image->data = mlx_get_data_addr(game->image->image,
	&game->image->bpp, &game->image->ls, &game->image->endian);
	raycast(game->param, game->player, game->image, game->texture);
	mlx_put_image_to_window(game->minilibx->minilibx,
	game->minilibx->window, game->image->image, 0, 0);
	mlx_destroy_image(game->minilibx->minilibx, game->image->image);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	init_game(&game);
	parse(argv[1], game->param);
	init_player(game->param, game->player);
	game->minilibx->minilibx = mlx_init();
	game->minilibx->window = mlx_new_window(game->minilibx->minilibx,
	game->param->width, game->param->height, "cub3d");
	mlx_loop_hook(game->minilibx->minilibx, image_loop, game);
	mlx_loop(game->minilibx->minilibx);
}
