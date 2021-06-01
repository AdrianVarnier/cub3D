/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:47:16 by avarnier          #+#    #+#             */
/*   Updated: 2021/06/01 17:45:09 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "mlx.h"

static void	free_save1(t_game *game)
{
	mlx_destroy_image(game->mlx->mlx, game->texture->north->image);
	mlx_destroy_image(game->mlx->mlx, game->texture->south->image);
	mlx_destroy_image(game->mlx->mlx, game->texture->east->image);
	mlx_destroy_image(game->mlx->mlx, game->texture->west->image);
	mlx_destroy_image(game->mlx->mlx, game->texture->sprite->image);
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

void	free_save(t_game *game)
{
	int	i;

	mlx_do_key_autorepeaton(game->mlx->mlx);
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
	free_save1(game);
}
