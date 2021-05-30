/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 13:15:28 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/07 16:14:45 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "raycaster.h"
#include "free.h"

static void	move_up_down(t_game *game)
{
	double	move_step;
	double	new_positionx;
	double	new_positiony;

	move_step = game->player->walk_direction1 * game->player->move_speed;
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

	move_step = game->player->walk_direction2 * game->player->move_speed;
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

void	movement(t_game *game)
{
	game->player->rotation_angle = normalized_angle(game->player->rotation_angle
			+ game->player->turn_direction * game->player->rotation_speed);
	move_up_down(game);
	move_left_right(game);
}

int	press_input(int key, t_game *game)
{
	if (key == ESCAPE)
		free_exit(game);
	if (key == UP)
		game->player->walk_direction1 = 1;
	if (key == DOWN)
		game->player->walk_direction1 = -1;
	if (key == LEFT)
		game->player->walk_direction2 = 1;
	if (key == RIGHT)
		game->player->walk_direction2 = -1;
	if (key == TURN_LEFT)
		game->player->turn_direction = 1;
	if (key == TURN_RIGHT)
		game->player->turn_direction = -1;
	return (0);
}

int	released_input(int key, t_player *player)
{
	if (key == UP)
		player->walk_direction1 = 0;
	if (key == DOWN)
		player->walk_direction1 = 0;
	if (key == LEFT)
		player->walk_direction2 = 0;
	if (key == RIGHT)
		player->walk_direction2 = 0;
	if (key == TURN_LEFT)
		player->turn_direction = 0;
	if (key == TURN_RIGHT)
		player->turn_direction = 0;
	return (0);
}
