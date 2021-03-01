/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:29:43 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/01 03:23:22 by avarnier         ###   ########.fr       */
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

static void	put_ceil(int x, int wall_stripe_height, t_param *param, t_image *image)
{
	int	c;

	c = 0;
	while (c < (param->height - 1) / 2 - wall_stripe_height / 2)
	{
		pixel_put(image, x, c, param->ceil);
		c++;
	}
}

static void	put_floor(int c, int x, t_param *param, t_image *image)
{
	while (c < param->height)
	{
		pixel_put(image, x, c, param->floor);
		c++;
	}
}

static void	put_wall(int wall_stripe_height, int x, t_param *param, t_image *image)
{
	int	c;

	c = 0;
	while (c <= wall_stripe_height)
	{
		pixel_put(image, x, (param->height - 1) / 2 - wall_stripe_height / 2 + c, 0xFF0000);
		c++;
	}
}

void		render_wall(t_param *param, t_image *image, double distance, int x)
{
	int		c;	
	int		wall_stripe_height;
	double	projection_plane_distance;

	c = 0;
	wall_stripe_height = TILE_SIZE / distance * (param->width / 2 / tan(FOV / 2)) + 0.1;
	if (wall_stripe_height >= param->height)
		wall_stripe_height = param->height - 1;
	put_ceil(x * WALL_STRIPE_WIDTH, wall_stripe_height, param, image);
	put_wall(wall_stripe_height, x * WALL_STRIPE_WIDTH, param, image);
	c = (param->height - 1) / 2 + wall_stripe_height / 2;
	put_floor(c, x * WALL_STRIPE_WIDTH, param, image);
}
