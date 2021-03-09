/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:15:28 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/09 23:20:52 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "raycaster.h"
#include "free.h"

static void	move_up_down_turn(t_game *game)
{
	double	move_step;
	double	new_positionx;
	double	new_positiony;

	game->player->rotation_angle = normalized_angle(game->player->rotation_angle
	+ game->player->turn_direction * game->player->rotation_speed);
	move_step = game->player->walk_direction * game->player->move_speed;
	new_positionx = game->player->x
	+ cos(game->player->rotation_angle) * move_step;
	new_positiony = game->player->y
	- sin(game->player->rotation_angle) * move_step;
	if (game->param->map[(int)(new_positiony / TILE_SIZE)]
	[(int)(new_positionx / TILE_SIZE)] != '1')
	{
		game->player->x = new_positionx;
		game->player->y = new_positiony;
	}
}

static void	move_left_right(t_game *game)
{
	double	move_step;
	double	new_positionx;
	double	new_positiony;

	move_step = game->player->walk_direction * game->player->move_speed;
	new_positionx = game->player->x
	+ cos(game->player->rotation_angle + M_PI / 2) * move_step;
	new_positiony = game->player->y
	- sin(game->player->rotation_angle + M_PI / 2) * move_step;
	if (game->param->map[(int)(new_positiony / TILE_SIZE)]
	[(int)(new_positionx / TILE_SIZE)] != '1')
	{
		game->player->x = new_positionx;
		game->player->y = new_positiony;
	}
}

int			press_input(int key, t_game *game)
{
	if (key == ESCAPE)
		free_exit(game);
	if (key == UP || key == LEFT)
		game->player->walk_direction = 1;
	if (key == DOWN || key == RIGHT)
		game->player->walk_direction = -1;
	if (key == TURN_LEFT)
		game->player->turn_direction = 1;
	if (key == TURN_RIGHT)
		game->player->turn_direction = -1;
	if (key == LEFT || key == RIGHT)
		move_left_right(game);
	else
		move_up_down_turn(game);
	return (0);
}

int			released_input(int key, t_player *player)
{
	if (key == UP)
		player->walk_direction = 0;
	if (key == DOWN)
		player->walk_direction = 0;
	if (key == LEFT)
		player->walk_direction = 0;
	if (key == RIGHT)
		player->walk_direction = 0;
	if (key == TURN_LEFT)
		player->turn_direction = 0;
	if (key == TURN_RIGHT)
		player->turn_direction = 0;
	return (0);
}
