/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 04:01:23 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/08 00:54:09 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "mlx.h"

void	free_exit(t_game *game)
{
	int	i;

	mlx_clear_window(game->minilibx->minilibx, game->minilibx->window);
	mlx_destroy_window(game->minilibx->minilibx, game->minilibx->window);
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
	mlx_destroy_image(game->minilibx->minilibx, game->texture->north->image);
	mlx_destroy_image(game->minilibx->minilibx, game->texture->south->image);
	mlx_destroy_image(game->minilibx->minilibx, game->texture->east->image);
	mlx_destroy_image(game->minilibx->minilibx, game->texture->west->image);
	mlx_destroy_image(game->minilibx->minilibx, game->texture->sprite->image);
	free(game->texture->north);
	free(game->texture->south);
	free(game->texture->east);
	free(game->texture->west);
	free(game->texture->sprite);
	free(game->texture);
	free(game->image);
	mlx_destroy_display(game->minilibx->minilibx);
	free(game->minilibx->minilibx);
	free(game->minilibx);
	free(game);
	exit(0);
}
