/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:58:19 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/01 14:03:53 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static int	is_ray_left(double angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (-1);
	else
		return (1);
}

static int	is_ray_right(double angle)
{
	if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		return (TILE_SIZE);
	else
		return (0);
}

static int	is_ray_up(double angle)
{
	if ((angle > 0 && angle < M_PI && tan(angle) > 0)
	|| (angle > M_PI && angle < 2 * M_PI && tan(angle) < 0))
		return (-1);
	else
		return (1);
}

double		check_vertical_intersection(t_param *param, t_player *player,
			t_texture *texture, double angle)
{
	double	wallx;
	double	wally;
	double	stepx;
	double	stepy;

	if (angle == M_PI / 2 || angle == 3 * M_PI / 2)
		return (-1);
	wallx = floor(player->x / TILE_SIZE) * TILE_SIZE + is_ray_right(angle);
	wally = player->y + (wallx - player->x) / tan(angle);
	stepx = TILE_SIZE * is_ray_left(angle);
	stepy = TILE_SIZE / tan(angle) * is_ray_up(angle);
	while (wallx > 0 && wally > 0 && wallx < (param->map_width + 2) * TILE_SIZE
	&& wally < (param->map_height + 2) * TILE_SIZE)
	{
		if (param->map[(int)wally / TILE_SIZE][(int)wallx / TILE_SIZE] == '1')
		{
			texture->texture_y = wally;
			return (sqrt(pow(player->x - wallx, 2)
					+ pow(player->y - wally, 2)));
		}
		wally = wally + stepy;
		wallx = wallx + stepx;
	}
	return (-1);
}
