/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:51:22 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/06 15:53:56 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "free.h"
#include "mlx.h"

static void	init_texture1(t_game *game)
{
	game->texture->north->image = mlx_xpm_file_to_image(game->mlx->mlx,
	game->param->north, &game->texture->north->width,
	&game->texture->north->height);
	game->texture->south->image = mlx_xpm_file_to_image(game->mlx->mlx,
	game->param->south, &game->texture->south->width,
	&game->texture->south->height);
	game->texture->east->image = mlx_xpm_file_to_image(game->mlx->mlx,
	game->param->east, &game->texture->east->width,
	&game->texture->east->height);
	game->texture->west->image = mlx_xpm_file_to_image(game->mlx->mlx,
	game->param->west, &game->texture->west->width,
	&game->texture->west->height);
	game->texture->sprite->image = mlx_xpm_file_to_image(game->mlx->mlx,
	game->param->sprite, &game->texture->sprite->width,
	&game->texture->sprite->height);
	if (game->texture->north->image == NULL ||
	game->texture->south->image == NULL
	|| game->texture->east->image == NULL || game->texture->west->image == NULL
	|| game->texture->sprite->image == NULL)
		free_texture_exit(game);
}

static void	init_texture2(t_game *game)
{
	game->texture->north->data = mlx_get_data_addr(game->texture->north->image,
	&game->texture->north->bpp, &game->texture->north->ls,
	&game->texture->north->endian);
	game->texture->south->data = mlx_get_data_addr(game->texture->south->image,
	&game->texture->south->bpp, &game->texture->south->ls,
	&game->texture->south->endian);
	game->texture->east->data = mlx_get_data_addr(game->texture->east->image,
	&game->texture->east->bpp, &game->texture->east->ls,
	&game->texture->east->endian);
	game->texture->west->data = mlx_get_data_addr(game->texture->west->image,
	&game->texture->west->bpp, &game->texture->west->ls,
	&game->texture->west->endian);
	game->texture->sprite->data = mlx_get_data_addr(
	game->texture->sprite->image, &game->texture->sprite->bpp,
	&game->texture->sprite->ls, &game->texture->sprite->endian);
}

void		init_texture(t_game *game)
{
	init_texture1(game);
	init_texture2(game);
}
