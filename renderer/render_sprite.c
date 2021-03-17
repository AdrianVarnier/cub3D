/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:51:04 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/17 01:48:10 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "raycaster.h"

static void	pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->data + (y * image->ls + x * (image->bpp / 8));
	if (color != 0xFF00FF)
		*(int *)dst = color;
}

static void	sort_sprite(t_sprite *sprite, t_player *player)
{
	double	tmpx;
	double	tmpy;
	int		i;

	i = 0;
	tmpx = 0;
	tmpy = 0;
	while (sprite->x[i] != -1)
	{
		if (sqrt(pow(player->x - sprite->x[i], 2) + pow(player->y - sprite->y[i], 2)) <
		sqrt(pow(player->x - sprite->x[i + 1], 2) + pow(player->y - sprite->y[i + 1], 2))
		&& sprite->x[i + 1] != -1)
		{
			tmpx = sprite->x[i];
			tmpy = sprite->y[i];
			sprite->x[i] = sprite->x[i + 1];
			sprite->y[i] = sprite->y[i + 1];
			sprite->x[i + 1] = tmpx;
			sprite->y[i + 1] = tmpy;
			i = 0;
		}
		else
			i++;
	}
}

void	render_sprite(t_game *game)
{
	int	i = 0;
	double dist_to_projection_plane = game->param->width / 2 / tan(degree_to_radian(FOV) / 2);
	while (game->sprite->x[i] != -1)
	{
		double angle = game->player->rotation_angle + atan2(game->sprite->y[i] - game->player->y, game->sprite->x[i] - game->player->x);
		if (angle > M_PI)
			angle = angle - 2 * M_PI;
		if (angle < -M_PI)
			angle = angle + 2 * M_PI;
		angle = fabs(angle);
		if (angle < degree_to_radian(FOV / 2) + 0.5)
		{
			double dx = game->sprite->x[i] - game->player->x;
			double dy = game->sprite->y[i] - game->player->y;
			double distance = sqrt(dx * dx + dy * dy);
			angle = atan2(dy, dx) + game->player->rotation_angle;
			double width = TILE_SIZE / distance * dist_to_projection_plane;
			double real_width = width;
			double height = width;
			double real_height = width;
			if (width > game->param->width)
				width = game->param->width - 1;
			if (height > game->param->height)
				height = game->param->height - 1;
			double x = tan(angle) * dist_to_projection_plane;
			int left = game->param->width / 2 + x - width / 2;
			int top = game->param->height / 2 - height / 2;
			int cx = 0;
			int cy = 0;
			while (cx < width)
			{
				while (cy < height)
				{
					if (left + cx > 0 && top + cy > 0 && left + cx < game->param->width && top + cy < game->param->height
					&& game->wall_distance[left + cx] > distance)
						pixel_put(game->image, left + cx, top + cy, get_texture_pixel_sprite(game->texture, 
						(cx + real_width / 2 - width / 2) / real_width,
						(cy + real_height / 2 - height / 2) / real_height));
					cy++;
				}
				cy = 0;
				cx++;
			}
		}
	i++;
	}
}
