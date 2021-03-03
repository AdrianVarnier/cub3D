/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical_intersection.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 19:58:19 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/04 00:24:31 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

static int	ray_left1(angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (-1);
	return (1);
}

double	check_vertical_intersection(t_param *param, t_player *player,
		t_texture *texture, double angle)
{
	double	wallx;
	double	wally;
	double	stepx;
	double	stepy;

	wallx = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (angle > 3 * M_PI / 2 || angle < M_PI / 2)
		wallx = wallx + TILE_SIZE;
	wally = player->y + (player->x - wallx) * tan(angle);
	stepx = TILE_SIZE * ray_left1(angle);
	stepy = TILE_SIZE * tan(angle);
	if (angle > 0 && angle < M_PI && ystep > 0)
		stepy = stepy * -1;
	if ((angle > M_PI && angle < 2 * M_PI) && ystep < 0)
		stepy = stepy * -1;
	offset = 0;
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		offset = 1;
	while (wallx >= 0 && wallx < (param->map_width + 2) * TILE_SIZE
	&& wally >= 0 && wally < (param->map_height + 2) * TILE_SIZE)
	{
		if (param->map[(int)floor(wally / TILE_SIZE)]
		[(int)floor((wallx-offset) / TILE_SIZE)] == '1')
			return
			(sqrt(pow(player->x - wallx, 2) + pow(player->y - wally, 2)));
			wallx = wallx + xstep;
			wally = wally + ystep;
	}
	return (-1);
}
