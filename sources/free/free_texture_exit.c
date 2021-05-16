/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:42:27 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/16 16:04:02 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "mlx.h"

static void	free_texture_exit1(t_game *game)
{
	int	i;

	free(game->param->north);
	free(game->param->south);
	free(game->param->east);
	free(game->param->west);
	free(game->param->sprite);
	i = 0;
	while (game->param->map[i] != NULL)
	{
		free(game->param->map[i]);
		i++;
	}
	free(game->param->map);
	free(game->param);
	free(game->player);
	free(game->sprite->x);
	free(game->sprite->y);
	free(game->sprite);
}

static void	free_texture_exit2(t_game *game)
{
	if (game->texture->north->image != NULL)
		mlx_destroy_image(game->mlx->mlx, game->texture->north->image);
	if (game->texture->south->image != NULL)
		mlx_destroy_image(game->mlx->mlx, game->texture->south->image);
	if (game->texture->east->image != NULL)
		mlx_destroy_image(game->mlx->mlx, game->texture->east->image);
	if (game->texture->west->image != NULL)
		mlx_destroy_image(game->mlx->mlx, game->texture->west->image);
	if (game->texture->sprite->image != NULL)
		mlx_destroy_image(game->mlx->mlx, game->texture->sprite->image);
}

static void	free_texture_exit3(t_game *game)
{
	free(game->texture->north);
	free(game->texture->south);
	free(game->texture->east);
	free(game->texture->west);
	free(game->texture->sprite);
	free(game->texture);
	free(game->image);
	mlx_destroy_display(game->mlx->mlx);
	free(game->mlx->mlx);
	free(game->mlx);
	free(game);
	exit(0);
}

void		free_texture_exit(t_game *game)
{
	free_texture_exit1(game);
	free_texture_exit2(game);
	free_texture_exit3(game);
}
