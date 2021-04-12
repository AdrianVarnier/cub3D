/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:02:40 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/11 19:14:48 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "math.h"
#include "raycaster.h"

int			get_texture_pixel_north(t_texture *texture, double y)
{
	int		color;
	double	x;

	x = fmod(texture->texturex, TILE_SIZE) / TILE_SIZE * texture->north->width;
	y = y * texture->north->height;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	color = *(int *)(texture->north->data + ((int)y * texture->north->ls + (int)x * (texture->north->bpp / 8)));
	return (color);
}

int			get_texture_pixel_south(t_texture *texture, double y)
{
	int		color;
	double	x;

	x = fmod(texture->texturex, TILE_SIZE) / TILE_SIZE * texture->south->width;
	y = y *  texture->south->height;
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

	x = fmod(texture->texturey, TILE_SIZE) / TILE_SIZE * texture->east->width;
	y = y *  texture->east->height;
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

	x = fmod(texture->texturey, TILE_SIZE) / TILE_SIZE * texture->west->width;
	y = y *  texture->west->height;
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

	x = x * texture->sprite->width;
	y = y * texture->sprite->height;
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	color = *(int *)(texture->sprite->data + ((int)y * texture->sprite->ls + (int)x * (texture->sprite->bpp / 8)));
	return (color);
}
