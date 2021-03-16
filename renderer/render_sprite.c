/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:51:04 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/16 22:34:12 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "raycaster.h"

static void	pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->data + (y * image->ls + x * (image->bpp / 8));
	if (color != 0xFF00FF)
		*(int *)dst = color;
}

static void	sort_sprite(t_sprite *sprite, t_player *player)
{
	double	tmpx;
	double	tmpy;
	int		i;

	i = 0;
	tmpx = 0;
	tmpy = 0;
	while (sprite->x[i] != -1)
	{
		if (sqrt(pow(player->x - sprite->x[i], 2) + pow(player->y - sprite->y[i], 2)) <
		sqrt(pow(player->x - sprite->x[i + 1], 2) + pow(player->y - sprite->y[i + 1], 2))
		&& sprite->x[i + 1] != -1)
		{
			tmpx = sprite->x[i];
			tmpy = sprite->y[i];
			sprite->x[i] = sprite->x[i + 1];
			sprite->y[i] = sprite->y[i + 1];
			sprite->x[i + 1] = tmpx;
			sprite->y[i + 1] = tmpy;
			i = 0;
		}
		else
			i++;
	}
}

void	render_sprite(t_game *game)
{
	
}
