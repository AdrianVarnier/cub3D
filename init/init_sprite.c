/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:20:29 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/11 18:23:30 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "raycaster.h"

static int	get_sprite_number(t_param *param)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	c = 0;
	while (param->map[j] != NULL)
	{
		while (param->map[j][i] != '\0')
		{
			if (param->map[j][i] == '2')
				c++;
			i++;
		}
		i = 0;
		j++;
	}
	return (c);
}

static void	get_sprite_position(t_sprite *sprite, t_param *param)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (param->map[j] != NULL)
	{
		while (param->map[j][i] != '\0')
		{
			if (param->map[j][i] == '2')
			{
				sprite->x[k] = i * TILE_SIZE;
				sprite->y[k] = j * TILE_SIZE;
				k++;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

void		init_sprite(t_sprite *sprite, t_param *param)
{
	int	sprite_number;
	
	sprite_number = get_sprite_number(param);
	if (!(sprite->x = (double *)malloc(sizeof(double) * (sprite_number + 1))))
		sprite->x = NULL;
	sprite->x[sprite_number] = -1;
	if (!(sprite->y = (double *)malloc(sizeof(double) * (sprite_number + 1))))
		sprite->y = NULL;
	sprite->y[sprite_number] = -1;
	get_sprite_position(sprite, param);
}
