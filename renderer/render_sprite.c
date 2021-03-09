/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:51:04 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/09 15:59:00 by avarnier         ###   ########.fr       */
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

/*static void	sort_sprite(t_param *param)
{
	double	tmpx;
	double	tmpy;
	int		i;

	i = 0;
	tmpx = 0;
	tmpy = 0;
	while (param->sprite_pos[0][i] != -1)
	{
		if (sqrt(pow(param->camx - param->sprite_pos[0][i], 2) + pow(param->camy - param->sprite_pos[1][i], 2)) <
		sqrt(pow(param->camx - param->sprite_pos[0][i + 1], 2) + pow(param->camy - param->sprite_pos[1][i + 1], 2))
		&& param->sprite_pos[0][i + 1] != -1 && param->sprite_pos[1][i + 1] != -1)
		{
			tmpx = param->sprite_pos[0][i];
			tmpy = param->sprite_pos[1][i];
			param->sprite_pos[0][i] = param->sprite_pos[0][i + 1];
			param->sprite_pos[1][i] = param->sprite_pos[1][i + 1];
			param->sprite_pos[0][i + 1] = tmpx;
			param->sprite_pos[1][i + 1] = tmpy;
			i = 0;
		}
		else
			i++;
	}
}*/

void		render_sprite(t_game *game)
{
	int		i;
	double	angle;
	double	sprite_angle;
	double	distance;
	double	sprite_height;
	double	x;
	double	projection_plane_distance;
	int		c1;
	int		c2;

	i = 0;
	projection_plane_distance = game->param->width / 2 / tan(degree_to_radian(FOV) / 2);
	while (game->sprite->x[i] != -1)
	{
		sprite_angle = game->player->rotation_angle
		- atan2(game->sprite->y[i] - game->player->y, game->sprite->x[i] - game->player->x);
		if (sprite_angle > M_PI)
			sprite_angle = sprite_angle - 2 * M_PI;
		if (sprite_angle < -M_PI)
			sprite_angle = sprite_angle + 2 * M_PI;
		sprite_angle = fabs(sprite_angle);
		if (sprite_angle < FOV / 2)
		{
			distance = sqrt(pow(game->player->x - game->sprite->x[i], 2) + pow(game->player->y - game->sprite->y[i], 2));
			sprite_height = (TILE_SIZE / distance) * projection_plane_distance;
			angle = atan2(game->sprite->y[i] - game->player->y, game->sprite->x[i] - game->player->x)
			- game->player->rotation_angle;
			x = tan(angle) * projection_plane_distance;
			c1 = game->param->width / 2 + x;
			c2 = game->param->height / 2 - sprite_height / 2;
			while (c1 < game->param->width / 2 + x + sprite_height)
			{
				while (c2 < game->param->height / 2 + sprite_height / 2)
				{
					pixel_put(game->image, c1, c2, 0);
					c2++;
				}
				c2 = game->param->height / 2 - sprite_height / 2;
				c1++;
			}
		}
		i++;
	}
}
