/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:15:28 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/02 19:48:14 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "raycaster.h"

int movement_press(int key, t_game *game)
{
	double	move_step;
	double	new_positionx;
	double	new_positiony;

	if (key == UP)
		game->player->walk_direction = 1;
	if (key == DOWN)
		game->player->walk_direction = -1;
	if (key == TURN_LEFT)
		game->player->turn_direction = 1;
	if (key == TURN_RIGHT)
		game->player->turn_direction = -1;
	game->player->rotation_angle = game->player->rotation_angle + game->player->turn_direction *
	game->player->rotation_speed;
	move_step = game->player->walk_direction * game->player->move_speed;
	new_positionx = game->player->x + cos(game->player->rotation_angle) * move_step;
	new_positiony = game->player->y + sin(game->player->rotation_angle) * move_step;
	if (game->param->map[(int)(new_positiony / TILE_SIZE)][(int)(new_positionx / TILE_SIZE)] != '1')
	{
		game->player->x = new_positionx;
		game->player->y = new_positiony;
	}
	return (0);
}

int	movement_released(int key, t_player *player)
{
	if (key == UP)
		player->walk_direction = 0;
	if (key == DOWN)
		player->walk_direction = 0;
	if (key == TURN_LEFT)
		player->turn_direction = 0;
	if (key == TURN_RIGHT)
		player->turn_direction = 0;
	return (0);
}
