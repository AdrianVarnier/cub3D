/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:48:48 by avarnier          #+#    #+#             */
/*   Updated: 2021/04/30 12:46:46 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "raycaster.h"
#include "renderer.h"
#include "init.h"
#include "mlx.h"
#include "input.h"
#include "save.h"
#include "free.h"
#include "minimap_bonus.h"
#include "lifebar_bonus.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
	&& s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	check_window(t_param *param, t_game *game)
{
	int	x;
	int	y;

	mlx_get_screen_size(game->mlx->mlx, &x, &y);
	if (param->width > x)
		param->width = x;
	if (param->height > y)
		param->height = y;
}

static int	image_loop(t_game *game)
{
	game->image->image = mlx_new_image(game->mlx->mlx,
	game->param->width, game->param->height);
	game->image->data = mlx_get_data_addr(game->image->image,
	&game->image->bpp, &game->image->ls, &game->image->endian);
	raycast(game);
	render_sprite(game);
	render_minimap(game);
	render_lifebar(game);
	free(game->wall_distance);
	mlx_put_image_to_window(game->mlx->mlx,
	game->mlx->window, game->image->image, 0, 0);
	mlx_destroy_image(game->mlx->mlx, game->image->image);
	return (0);
}

static void	save_exit(t_game *game, char *argv)
{
	init_game(&game);
	parse(argv, game);
	init_player(game->param, game->player);
	init_sprite(game->sprite, game->param);
	game->mlx->mlx = mlx_init();
	init_texture(game);
	check_window(game->param, game);
	game->image->image = mlx_new_image(game->mlx->mlx,
	game->param->width, game->param->height);
	game->image->data = mlx_get_data_addr(game->image->image,
	&game->image->bpp, &game->image->ls, &game->image->endian);
	raycast(game);
	render_sprite(game);
	render_minimap(game);
	render_lifebar(game);
	free(game->wall_distance);
	save(game);
	mlx_destroy_image(game->mlx->mlx, game->image->image);
	free_save(game);
}

int			main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		save_exit(game, argv[1]);
	if (argc != 2)
	{
		perror("Wrong argument");
		exit(0);
	}
	init_game(&game);
	parse(argv[1], game);
	init_player(game->param, game->player);
	init_sprite(game->sprite, game->param);
	game->mlx->mlx = mlx_init();
	init_texture(game);
	check_window(game->param, game);
	game->mlx->window = mlx_new_window(game->mlx->mlx,
	game->param->width, game->param->height, "cub3d");
	image_loop(game);
	mlx_hook(game->mlx->window, 2, 1L << 0, press_input, game);
	mlx_hook(game->mlx->window, 3, 1L << 1, released_input, game->player);
	mlx_hook(game->mlx->window, 33, 1L << 17, free_cross_exit, game);
	mlx_loop_hook(game->mlx->mlx, image_loop, game);
	mlx_loop(game->mlx->mlx);
}
