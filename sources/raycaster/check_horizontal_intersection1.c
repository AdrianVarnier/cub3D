/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal_intersection1.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:25:40 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/09 00:37:44 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static int	ray_up1(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (-1);
	return (1);
}

static int	ray_up2(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (1);
	return (0);
}

static int	ray_down(double angle)
{
	if (angle > M_PI && angle < 2 * M_PI)
		return (TILE_SIZE);
	return (0);
}

static int	ray_left(double angle)
{
	if ((angle > M_PI / 2 && angle < 3 * M_PI / 2 && tan(angle) > 0) ||
	((angle > 3 * M_PI / 2 || angle < M_PI / 2) && tan(angle) < 0))
		return (-1);
	return (1);
}

double		check_horizontal_intersection1(t_param *param, t_player *player,
			t_texture *texture, double angle)
{
	double	wallx;
	double	wally;
	double	stepx;
	double	stepy;
	double	offset;

	wally = floor(player->y / TILE_SIZE) * TILE_SIZE + ray_down(angle);
	wallx = player->x + (player->y - wally) / tan(angle);
	stepy = TILE_SIZE * ray_up1(angle);
	stepx = TILE_SIZE / tan(angle) * ray_left(angle);
	offset = ray_up2(angle);
	while (wallx >= 0 && wallx < (param->map_width + 2) * TILE_SIZE
	&& wally >= 0 && wally < (param->map_height + 2) * TILE_SIZE)
	{
		if (param->map[(int)floor((wally - offset) / TILE_SIZE)]
		[(int)floor(wallx / TILE_SIZE)] == '1')
		{
			texture->texturex = wallx;
			return
			(sqrt(pow(player->x - wallx, 2) + pow(player->y - wally, 2)));
		}
		wallx = wallx + stepx;
		wally = wally + stepy;
	}
	return (-1);
}
