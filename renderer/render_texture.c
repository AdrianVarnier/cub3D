/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:02:40 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/11 18:19:47 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "math.h"
#include "raycaster.h"

int			get_texture_pixel_north(t_texture *texture, double y)
{
	int		color;
	double	x;

	x = fmod(texture->texturex, TILE_SIZE) / TILE_SIZE * texture->north->width - 1;
	y = y * texture->north->height - 1;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	color = *(int *)(texture->north->data + ((int)y * texture->north->ls + (int)x * (texture->north->bpp / 8))) + 0.1;
	return (color);
}

int			get_texture_pixel_south(t_texture *texture, double y)
{
	int		color;
	double	x;

	x = fmod(texture->texturex, TILE_SIZE) / TILE_SIZE * texture->south->width - 1;
	y = y *  texture->south->height - 1;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	color = *(int *)(texture->south->data + ((int)y * texture->south->ls + (int)x * (texture->south->bpp / 8)));
	return (color);
}

int			get_texture_pixel_east(t_texture *texture, double y)
{
	int		color;
	double	x;

	x = fmod(texture->texturey, TILE_SIZE) / TILE_SIZE * texture->east->width - 1;
	y = y *  texture->east->height - 1;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	color = *(int *)(texture->east->data + ((int)y * texture->east->ls + (int)x * (texture->east->bpp / 8)));
	return (color);
}

int			get_texture_pixel_west(t_texture *texture, double y)
{
	int		color;
	double	x;

	x = fmod(texture->texturey, TILE_SIZE) / TILE_SIZE * texture->west->width - 1;
	y = y *  texture->west->height - 1;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	color = *(int *)(texture->west->data + ((int)y * texture->west->ls + (int)x * (texture->west->bpp / 8)));
	return (color);
}

int			get_texture_pixel_sprite(t_texture *texture, double x, double y)
{
		int		color;

	x = x * texture->sprite->width - 1;
	y = y * texture->sprite->height - 1;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	color = *(int *)(texture->sprite->data + ((int)y * texture->sprite->ls + (int)x * (texture->sprite->bpp / 8)));
	return (color);
}
