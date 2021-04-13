/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:29:43 by avarnier          #+#    #+#             */
/*   Updated: 2021/04/13 18:27:51 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "raycaster.h"

static void	pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->data + (y * image->ls + x * (image->bpp / 8));
	*(int *)dst = color;
}

static void	render_ceil_floor(t_game *game, int x, double wall_stripe_height)
{
	int	c;

	c = 0;
	while (c < (game->param->height - 1) / 2 - wall_stripe_height / 2)
	{
		pixel_put(game->image, x, c, game->param->ceil);
		c++;
	}
	c = (game->param->height - 1) / 2 + wall_stripe_height / 2;
	while (c < game->param->height)
	{
		pixel_put(game->image, x, c, game->param->floor);
		c++;
	}
}

static void	render_wall1(t_game *game, int x, double wall_stripe_height,
double real_wall_stripe_height)
{
	int	c;

	c = 0;
	while (c <= wall_stripe_height)
	{
		if (game->texture->orientation == 'N')
			pixel_put(game->image, x, (game->param->height - 1) / 2
			- wall_stripe_height / 2 + c, get_texture_pixel_north(game->texture,
			(c + real_wall_stripe_height / 2 - wall_stripe_height / 2)
			/ real_wall_stripe_height));
		if (game->texture->orientation == 'S')
			pixel_put(game->image, x, (game->param->height - 1) / 2
			- wall_stripe_height / 2 + c, get_texture_pixel_south(game->texture,
			(c + real_wall_stripe_height / 2 - wall_stripe_height / 2)
			/ real_wall_stripe_height));
		c++;
	}
}

static void	render_wall2(t_game *game, int x, double wall_stripe_height,
double real_wall_stripe_height)
{
	int	c;

	c = 0;
	while (c <= wall_stripe_height)
	{
		if (game->texture->orientation == 'E')
			pixel_put(game->image, x, (game->param->height - 1) / 2
			- wall_stripe_height / 2 + c, get_texture_pixel_east(game->texture,
			(c + real_wall_stripe_height / 2 - wall_stripe_height / 2)
			/ real_wall_stripe_height));
		if (game->texture->orientation == 'W')
			pixel_put(game->image, x, (game->param->height - 1) / 2
			- wall_stripe_height / 2 + c, get_texture_pixel_west(game->texture,
			(c + real_wall_stripe_height / 2 - wall_stripe_height / 2)
			/ real_wall_stripe_height));
		c++;
	}
}

void		render(t_game *game, double distance, int x)
{
	double	wall_stripe_height;
	double	real_wall_stripe_height;
	double	projection_plane_distance;

	projection_plane_distance = game->param->width / 2
	/ tan(degree_to_radian(FOV) / 2);
	wall_stripe_height = TILE_SIZE / distance * projection_plane_distance;
	real_wall_stripe_height = TILE_SIZE / distance * projection_plane_distance;
	if (wall_stripe_height >= game->param->height)
		wall_stripe_height = game->param->height - 1;
	render_ceil_floor(game, x, wall_stripe_height);
	render_wall1(game, x, wall_stripe_height, real_wall_stripe_height);
	render_wall2(game, x, wall_stripe_height, real_wall_stripe_height);
}
