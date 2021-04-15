/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:56:48 by avarnier          #+#    #+#             */
/*   Updated: 2021/04/15 17:41:25 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap_bonus.h"

static void	pixel_put(t_image *image, int x, int y, int color)
{
	char *dst;

	dst = image->data + (y * image->ls + x * (image->bpp / 8));
	*(int *)dst = color;
}

static void	print_wall_square(int i, int j, t_game *game)
{
	int	x;
	int	y;

	i = i * game->param->width / game->param->map_width / 10;
	j = j * game->param->width / game->param->map_width / 10;
	x = j;
	y = i;
	while (y < i + game->param->width / game->param->map_width / 10)
	{
		while (x < j + game->param->width / game->param->map_width / 10)
		{
			pixel_put(game->image, x, y, 0xFFFFFF);
			x++;
		}
		x = j;
		y++;
	}
}

static void	print_sprite_square(int i, int j, t_game *game)
{
	int	x;
	int	y;

	i = i * game->param->width / game->param->map_width / 10;
	j = j * game->param->width / game->param->map_width / 10;
	x = j;
	y = i;
	while (y < i + game->param->width / game->param->map_width / 10)
	{
		while (x < j + game->param->width / game->param->map_width / 10)
		{
			pixel_put(game->image, x, y, 0x000000);
			x++;
		}
		x = j;
		y++;
	}
	pixel_put(game->image, j + game->param->width
	/ game->param->map_width / 2 / 10,
	i + game->param->width / game->param->map_width / 2 / 10, 0xFFFFFF);
}

static void	print_empty_square(int i, int j, t_game *game)
{
	int	x;
	int	y;

	i = i * game->param->width / game->param->map_width / 10;
	j = j * game->param->width / game->param->map_width / 10;
	x = j;
	y = i;
	while (y < i + game->param->width / game->param->map_width / 10)
	{
		while (x < j + game->param->width / game->param->map_width / 10)
		{
			pixel_put(game->image, x, y, 0x000000);
			x++;
		}
		x = j;
		y++;
	}
}

void		render_minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->param->map[i] != NULL)
	{
		while (game->param->map[i][j] != '\0')
		{
			if (game->param->map[i][j] == '1')
				print_wall_square(i, j, game);
			else if (game->param->map[i][j] == '2')
				print_sprite_square(i, j, game);
			else if (game->param->map[i][j] == '0'
			|| game->param->map[i][j] == 'N'
			|| game->param->map[i][j] == 'S' || game->param->map[i][j] == 'E'
			|| game->param->map[i][j] == 'W')
				print_empty_square(i, j, game);
			j++;
		}
		j = 0;
		i++;
	}
}
