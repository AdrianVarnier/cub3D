/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal_intersection.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:25:40 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/03 10:38:32 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

double	check_horizontal_intersection(t_param *param, t_player *player, t_texture *texture, double angle)
{
	double yintercept = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (angle > M_PI && angle < 2 * M_PI)
		yintercept = yintercept + TILE_SIZE;
	double xintercept = player->x + (player->y - yintercept) / tan(angle);
	double ystep = TILE_SIZE;
	if (angle > 0 && angle < M_PI)
		ystep = ystep * -1;
	double xstep = TILE_SIZE / tan(angle);
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2 && xstep > 0)
		xstep = xstep * -1;
	if ((angle > 3 * M_PI / 2 || angle < M_PI / 2) && xstep < 0)
		xstep = xstep * -1;
	double nexthorztouchx = xintercept;
	double nexthorztouchy = yintercept;
	double offset = 0;
	if (angle > 0 && angle < M_PI)
		offset = 1;
	while (nexthorztouchx >= 0 && nexthorztouchx < (param->map_width + 2) * TILE_SIZE
	&& nexthorztouchy >= 0 && nexthorztouchy < (param->map_height + 2) * TILE_SIZE)
	{
		if (param->map[(int)floor((nexthorztouchy-offset) / TILE_SIZE)][(int)floor(nexthorztouchx / TILE_SIZE)] == '1')
			return (sqrt(pow(player->x - nexthorztouchx, 2) + pow(player->y - nexthorztouchy, 2)));
		else
		{
			nexthorztouchx += xstep;
			nexthorztouchy += ystep;
		}
	}
	return (-1);
}

double	check_vertical_intersection(t_param *param, t_player *player, t_texture *texture, double angle)
{
	double xintercept = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (angle > 3 * M_PI / 2 || angle < M_PI / 2)
		xintercept = xintercept + TILE_SIZE;
	double yintercept = player->y + (player->x - xintercept) * tan(angle);
	double xstep = TILE_SIZE;
	if (angle > M_PI / 2 && angle < 3 * M_PI)
		xstep = xstep * -1;
	double ystep = TILE_SIZE * tan(angle);
	if (angle > 0 && angle < M_PI && ystep > 0)
		ystep = ystep * -1;
	if ((angle > M_PI || angle < 2 * M_PI) && ystep < 0)
		ystep = ystep * -1;
	double nexthorztouchx = xintercept;
	double nexthorztouchy = yintercept;
	double offset = 0;
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		offset = 1;
	while (nexthorztouchx >= 0 && nexthorztouchx < (param->map_width + 2) * TILE_SIZE
	&& nexthorztouchy >= 0 && nexthorztouchy < (param->map_height + 2) * TILE_SIZE)
	{
		if (param->map[(int)floor(nexthorztouchy / TILE_SIZE)][(int)floor((nexthorztouchx-offset) / TILE_SIZE)] == '1')
			return (sqrt(pow(player->x - nexthorztouchx, 2) + pow(player->y - nexthorztouchy, 2)));
		else
		{
			nexthorztouchx += xstep;
			nexthorztouchy += ystep;
		}
	}
	return (-1);
}
