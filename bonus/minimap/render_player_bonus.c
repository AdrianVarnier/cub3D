/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 18:19:28 by avarnier          #+#    #+#             */
/*   Updated: 2021/04/20 18:28:00 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"

static void	pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->data + (y * image->ls + x * (image->bpp / 8));
	*(int *)dst = color;
}

void	render_player(t_game *game)
{
	pixel_put(game->image,
	game->player->x / 64 * game->param->width / game->param->map_width / 10,
	game->player->y / 64 * game->param->width / game->param->map_width / 10,
	0xFF0000);
}
