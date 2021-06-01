/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:46:58 by avarnier          #+#    #+#             */
/*   Updated: 2021/06/01 18:11:28 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"
#include "renderer.h"

static char	get_orientation(double d1, double d2,
				double angle, t_game *game)
{
	if (d1 == -1)
		d1 = d2 + 1;
	if (d2 == -1)
		d2 = d1 + 1;
	if (fabs(d1 - d2) < pow(10, -6))
	{
		return (get_orientation(check_horizontal_intersection2(game->param,
					game->player, angle + M_PI / 2 / game->param->width),
				check_vertical_intersection2(game->param, game->player,
					angle + M_PI / 2 / game->param->width),
				angle + M_PI / 2 / game->param->width, game));
	}
	if (d1 > d2)
	{
		if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
			return ('W');
		else
			return ('E');
	}
	if (angle > 0 && angle < M_PI)
		return ('N');
	else
		return ('S');
}

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

double	degree_to_radian(double angle)
{
	angle = angle * M_PI / 180;
	return (angle);
}

double	normalized_angle(double angle)
{
	while (angle >= 2 * M_PI)
		angle = angle - 2 * M_PI;
	while (angle < 0)
		angle = angle + 2 * M_PI;
	return (angle);
}

void	raycast(t_game *game)
{
	int		x;
	double	angle;
	double	distance;

	x = 0;
	game->wall_distance = (double *)malloc(sizeof(double)
			* (game->param->width + 1));
	check_raycast(game->wall_distance, game);
	game->wall_distance[game->param->width] = -1;
	while (x++ < game->param->width)
	{
		angle = normalized_angle(game->player->rotation_angle
				- atan((x - game->param->width / 2) / (game->param->width
						/ 2 / tan(degree_to_radian(FOV) / 2))));
		distance = get_smallest_distance(check_horizontal_intersection1(
					game->param, game->player, game->texture, angle),
				check_vertical_intersection1(game->param, game->player,
					game->texture, angle), angle, game->player);
		game->wall_distance[x] = distance;
		game->texture->orientation = get_orientation(
				check_horizontal_intersection2(game->param, game->player,
					angle), check_vertical_intersection2(game->param,
					game->player, angle), angle, game);
		render(game, distance, x - 1);
	}
}
