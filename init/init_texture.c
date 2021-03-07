/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:51:22 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/06 18:37:10 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "mlx.h"

void	init_texture(t_game *game)
{
	game->texture->north->image = mlx_xpm_file_to_image(game->minilibx->minilibx,
	game->param->north, &game->texture->north->width, &game->texture->north->height);
	game->texture->north->data = mlx_get_data_addr(game->texture->north->image,
	&game->texture->north->bpp, &game->texture->north->ls, &game->texture->north->endian);
	game->texture->south->image = mlx_xpm_file_to_image(game->minilibx->minilibx,
	game->param->south, &game->texture->south->width, &game->texture->south->height);
	game->texture->south->data = mlx_get_data_addr(game->texture->south->image,
	&game->texture->south->bpp, &game->texture->south->ls, &game->texture->south->endian);
	game->texture->east->image = mlx_xpm_file_to_image(game->minilibx->minilibx,
	game->param->east, &game->texture->east->width, &game->texture->east->height);
	game->texture->east->data = mlx_get_data_addr(game->texture->east->image,
	&game->texture->east->bpp, &game->texture->east->ls, &game->texture->east->endian);
	game->texture->west->image = mlx_xpm_file_to_image(game->minilibx->minilibx,
	game->param->west, &game->texture->west->width, &game->texture->west->height);
	game->texture->west->data = mlx_get_data_addr(game->texture->west->image,
	&game->texture->west->bpp, &game->texture->west->ls, &game->texture->west->endian);
//	game->texture->sprite = mlx_xpm_file_to_image(game->minilibx->minilibx,
//	game->param->sprite, &game->texture->sprite->width, &game->texture->sprite->height);
//	game->texture->sprite->data = mlx_get_data_addr(game->texture->sprite->image,
//	&game->texture->sprite->bpp, &game->texture->sprite->ls, &game->texture->sprite->endian);
}
