/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lifebar_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:26:59 by avarnier          #+#    #+#             */
/*   Updated: 2021/04/21 19:48:02 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lifebar_bonus.h"

static void	pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->data + (y * image->ls + x * (image->bpp / 8));
	*(int *)dst = color;
}

void		render_lifebar(t_game *game)
{
	int	x;
	int	y;

	x = game->param->width / 10;
	y = game->param->height / 10 * 9;
	while (y < game->param->height / 10 * 9.5)
	{
		while (x < game->param->width / 10 * 9)
		{
			pixel_put(game->image, x, y, 0xFF0000);
			x++;
		}
		x = game->param->width / 10;
		y++;
	}
}
