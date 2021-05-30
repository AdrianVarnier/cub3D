/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:51:04 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/25 20:37:34 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "raycaster.h"

static void	pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

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
		if (sqrt(pow(player->x - sprite->x[i], 2) + pow(player->y
					- sprite->y[i], 2)) < sqrt(pow(player->x
					- sprite->x[i + 1], 2) + pow(player->y
					- sprite->y[i + 1], 2)) && sprite->x[i + 1] != -1)
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

static double	get_angle_player_sprite(t_player *player,
t_sprite *sprite, int i)
{
	double	angle;

	angle = player->rotation_angle + atan2(sprite->y[i]
			- player->y, sprite->x[i] - player->x);
	if (angle > M_PI)
		angle = angle - 2 * M_PI;
	if (angle < -M_PI)
		angle = angle + 2 * M_PI;
	angle = fabs(angle);
	return (angle);
}

static void	print_sprite(t_game *game, double width, double height,
double real_width_height)
{
	int		cx;
	int		cy;

	cx = -1;
	cy = 0;
	get_sprite_variables(game, width, height);
	while (++cx < width)
	{
		while (cy < height)
		{
			if (game->sprite->left + cx > 0 && game->sprite->top + cy > 0
				&& game->sprite->left + cx < game->param->width
				&& game->sprite->top + cy < game->param->height
				&& game->wall_distance[game->sprite->left + cx]
				> game->sprite->distance)
				pixel_put(game->image, game->sprite->left
					+ cx, game->sprite->top + cy,
					get_texture_pixel_sprite(game->texture,
						(cx + real_width_height / 2 - width / 2)
						/ real_width_height, (cy + real_width_height
							/ 2 - height / 2) / real_width_height));
			cy++;
		}
		cy = 0;
	}
}

void	render_sprite(t_game *game)
{
	int		i;
	double	width;
	double	height;
	double	real_width_height;

	i = 0;
	sort_sprite(game->sprite, game->player);
	while (game->sprite->x[i] != -1)
	{
		game->sprite->angle = get_angle_player_sprite(game->player,
				game->sprite, i);
		if (game->sprite->angle < degree_to_radian(FOV / 2) + 0.5)
		{
			get_angle_distance(game, i);
			real_width_height = TILE_SIZE / game->sprite->distance
				* game->param->width / 2 / tan(degree_to_radian(FOV) / 2);
			width = get_width(real_width_height, game);
			height = get_height(real_width_height, game);
			print_sprite(game, width, height, real_width_height);
		}
		i++;
	}
}
