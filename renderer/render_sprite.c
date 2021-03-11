/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:51:04 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/11 18:24:05 by avarnier         ###   ########.fr       */
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
	int i = 0;
	double projection_plane_distance = game->param->width / 2 / tan(degree_to_radian(FOV) / 2);

	sort_sprite(game->sprite, game->player);
	while (game->sprite->x[i] != -1)
	{
		double angle_sprite_player = game->player->rotation_angle + atan2(game->sprite->y[i] - game->player->y, game->sprite->x[i] - game->player->x);
		if (angle_sprite_player > M_PI)
			angle_sprite_player = angle_sprite_player - 2 * M_PI;
		if (angle_sprite_player < -M_PI)
			angle_sprite_player = angle_sprite_player + 2 * M_PI;
		angle_sprite_player = fabs(angle_sprite_player);
		if (angle_sprite_player < degree_to_radian(FOV) / 2)
		{
			double distance = sqrt(pow(game->player->x - game->sprite->x[i], 2) + pow(game->player->y - game->sprite->y[i], 2));
			double sprite_height = TILE_SIZE / distance * projection_plane_distance;
			double real_sprite_height = sprite_height;
			if (sprite_height > game->param->height - 1)
				sprite_height = sprite_height - 1;
			double sprite_width = TILE_SIZE / distance * projection_plane_distance;
			double real_sprite_width = sprite_width;
			if (sprite_width > game->param->width - 1)
				sprite_width = sprite_width - 1;
			double sprite_angle = atan2(game->sprite->y[i] - game->player->y, game->sprite->x[i] - game->player->x) + game->player->rotation_angle;
			double x = tan(sprite_angle) * projection_plane_distance;
			int cx = 0;
			int cy = 0;
			while (cx < sprite_height)
			{
				while (cy < sprite_height)
				{
					if (game->param->width / 2 + x + cx < game->param->width && game->param->height / 2 - sprite_height / 2 + cy < game->param->height
						&& game->param->width / 2 + x + cx > 0 && game->param->height / 2 - sprite_height / 2 + cy > 0)
						pixel_put(game->image, game->param->width / 2 + x + cx, game->param->height / 2 - sprite_height / 2 + cy,
						get_texture_pixel_sprite(game->texture, (cx + real_sprite_width / 2 - sprite_width / 2) / (double)real_sprite_width,
						(cy + real_sprite_height / 2 - sprite_height / 2) / (double)real_sprite_height));
					cy++;
				}
				cy = 0;
				cx++;
			}

		}
		i++;
	}
}
