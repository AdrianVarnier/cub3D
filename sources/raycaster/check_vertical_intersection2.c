/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical_intersection2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 00:36:10 by avarnier          #+#    #+#             */
/*   Updated: 2021/06/01 17:25:42 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static int	ray_left1(double angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (-1);
	return (1);
}

static int	ray_left2(double angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (1);
	return (0);
}

static int	ray_right(double angle)
{
	if (angle >= 3 * M_PI / 2 || angle <= M_PI / 2)
		return (TILE_SIZE);
	return (0);
}

static int	ray_up(double angle)
{
	if ((angle > 0 && angle < M_PI && tan(angle) > 0)
		|| ((angle > M_PI && angle < 2 * M_PI) && tan(angle) < 0))
		return (-1);
	return (1);
}

double	check_vertical_intersection2(t_param *param, t_player *player,
			double angle)
{
	double	wallx;
	double	wally;
	double	stepx;
	double	stepy;
	double	offset;

	wallx = floor(player->x / TILE_SIZE) * TILE_SIZE + ray_right(angle);
	wally = player->y + (player->x - wallx) * tan(angle);
	stepx = TILE_SIZE * ray_left1(angle);
	stepy = TILE_SIZE * tan(angle) * ray_up(angle);
	offset = ray_left2(angle);
	while (wallx >= 0 && wallx < (param->map_width + 2) * TILE_SIZE
		&& wally >= 0 && wally < (param->map_height + 2) * TILE_SIZE)
	{
		if (param->map[(int)floor(wally / TILE_SIZE)]
			[(int)floor((wallx - offset) / TILE_SIZE)] == '1')
			return (
				sqrt(pow(player->x - wallx, 2) + pow(player->y - wally, 2)));
		wallx = wallx + stepx;
		wally = wally + stepy;
	}
	return (-1);
}
