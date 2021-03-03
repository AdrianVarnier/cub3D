/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 23:29:43 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/02 23:04:58 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "raycaster.h"
#include "stdio.h"

static void	pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->data + (y * image->ls + x * (image->bpp / 8));
	*(int *)dst = color;
}

void		render_wall(t_param *param, t_image *image, double distance, int x)
{
	int		c;
	int		wall_stripe_height;
	double	projection_plane_distance;

	c = 0;
	projection_plane_distance = param->width / 2 / tan(degree_to_radian(FOV) / 2);
	wall_stripe_height = TILE_SIZE / distance * projection_plane_distance;
	if (wall_stripe_height >= param->height)
		wall_stripe_height = param->height - 1;
	while (c <= wall_stripe_height)
	{
		pixel_put(image, x, (param->height - 1) / 2 - wall_stripe_height / 2 + c, 0xFFFFFF);
		c++;
	}
}
