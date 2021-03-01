/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:22:47 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/01 01:15:30 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "raycaster.h"

static void	get_position(t_param *param, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (param->map[j] != NULL)
	{
		while (param->map[j][i] != '\0')
		{
			if (param->map[j][i] == 'N' || param->map[j][i] == 'S'
			|| param->map[j][i] == 'E' || param->map[j][i] == 'W')
			{
				player->x = i * TILE_SIZE + TILE_SIZE / 2;
				player->y = j * TILE_SIZE + TILE_SIZE / 2;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

static void	get_rotation_angle(t_param *param, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (param->map[j] != NULL)
	{
		while (param->map[j][i] != '\0')
		{
			if (param->map[j][i] == 'N')
				player->rotation_angle = M_PI / 2;
			if (param->map[j][i] == 'S')
				player->rotation_angle = 3 * M_PI / 2;
			if (param->map[j][i] == 'W')
				player->rotation_angle = M_PI;
			if (param->map[j][i] == 'E')
				player->rotation_angle = 0;
			i++;
		}
		i = 0;
		j++;
	}
}

void	init_player(t_param *param, t_player *player)
{
	get_position(param, player);
	player->turn_direction = 0;
	player->walk_direction = 0;
	get_rotation_angle(param, player);
	player->move_speed = 2;
	player->rotation_speed = 2 * (M_PI / 180);
}
