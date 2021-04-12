/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:24:59 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/25 20:39:49 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster.h"

void			get_sprite_variables(t_game *game, double width, double height)
{
	game->sprite->offset = tan(game->sprite->angle)
	* game->param->width / 2 / tan(degree_to_radian(FOV) / 2);
	game->sprite->left = game->param->width / 2
	+ game->sprite->offset - width / 2;
	game->sprite->top = game->param->height / 2 - height / 2;
}

double			get_width(double real_width_height, t_game *game)
{
	double width;

	width = real_width_height;
	if (width > game->param->width)
		width = game->param->width - 1;
	return (width);
}

double			get_height(double real_width_height, t_game *game)
{
	double	height;

	height = real_width_height;
	if (height > game->param->height)
		height = game->param->height - 1;
	return (height);
}

void			get_angle_distance(t_game *game, int i)
{
	game->sprite->distance = sqrt(pow(game->player->x
	- game->sprite->x[i], 2)
	+ pow(game->player->y - game->sprite->y[i], 2))
	* cos(game->sprite->angle);
	game->sprite->angle = atan2(game->player->y - game->sprite->y[i],
	game->player->x - game->sprite->x[i])
	+ game->player->rotation_angle;
}
