/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cross_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:15:25 by avarnier          #+#    #+#             */
/*   Updated: 2021/06/01 17:37:38 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "mlx.h"

static void	free_cross_exit1(t_game *game)
{
	int	i;

	mlx_clear_window(game->mlx->mlx, game->mlx->window);
	mlx_destroy_window(game->mlx->mlx, game->mlx->window);
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

static void	free_cross_exit2(t_game *game)
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

int	free_cross_exit(t_game *game)
{
	mlx_do_key_autorepeaton(game->mlx->mlx);
	free_cross_exit1(game);
	free_cross_exit2(game);
	return (0);
}
