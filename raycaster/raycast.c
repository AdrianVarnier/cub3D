/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:46:58 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/06 14:17:18 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "renderer.h"

static double	get_smallest_distance(double d1, double d2,
				double angle, t_player *player)
{
	double	correction;

	correction = cos(angle - player->rotation_angle);
	if (d1 == -1)
		return (d2 * correction);
	if (d2 == -1)
		return (d1 * correction);
	if (d1 > d2)
		return (d2 * correction);
	return (d1 * correction);
}

double			degree_to_radian(double angle)
{
	angle = angle * M_PI / 180;
	return (angle);
}

double			normalized_angle(double angle)
{
	while (angle >= 2 * M_PI)
		angle = angle - 2 * M_PI;
	while (angle < 0)
		angle = angle + 2 * M_PI;
	return (angle);
}

void			raycast(t_game *game)
{
	int		x;
	double	angle;
	double	distance;
	double	ray_number;

	x = 0;
	angle = normalized_angle(game->player->rotation_angle + degree_to_radian(FOV) / 2);
	ray_number = game->param->width;
	while (x < ray_number)
	{
		distance = get_smallest_distance(check_horizontal_intersection(game->param, game->player, game->texture, angle),
		check_vertical_intersection(game->param, game->player, game->texture, angle), angle, game->player);	
		render(game, distance, x);
		angle = normalized_angle(angle - degree_to_radian(FOV) / ray_number);
		x++;
	}
}
