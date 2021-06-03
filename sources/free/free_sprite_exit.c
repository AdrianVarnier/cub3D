/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprite_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:30:01 by avarnier          #+#    #+#             */
/*   Updated: 2021/06/02 18:51:27 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

static void	free_sprite_exit1(t_game *game)
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
	if (game->sprite->x != NULL)
		free(game->sprite->x);
	if (game->sprite->y != NULL)
		free(game->sprite->y);
	free(game->sprite);
}

static void	free_sprite_exit2(t_game *game)
{
	free(game->texture->north);
	free(game->texture->south);
	free(game->texture->east);
	free(game->texture->west);
	free(game->texture->sprite);
	free(game->texture);
	free(game->image);
	free(game->mlx);
	free(game);
	ft_putstr_fd("Error\nmalloc sprite error\n", 0);
	exit(0);
}

void	free_sprite_exit(t_game *game)
{
	free_sprite_exit1(game);
	free_sprite_exit2(game);
}
