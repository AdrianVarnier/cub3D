/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 02:06:11 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/11 22:24:09 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "utils.h"

static void	free_init(t_game *game)
{
	if (game->param != NULL)
		free(game->param);
	if (game->player != NULL)
		free(game->player);
	if (game->sprite != NULL)
		free(game->sprite);
	if (game->texture->north != NULL)
		free(game->texture->north);
	if (game->texture->south != NULL)
		free(game->texture->south);
	if (game->texture->east != NULL)
		free(game->texture->east);
	if (game->texture->west != NULL)
		free(game->texture->west);
	if (game->texture->sprite != NULL)
		free(game->texture->sprite);
	if (game->texture != NULL)
		free(game->texture);
	if (game->image != NULL)
		free(game->image);
	if (game->mlx != NULL)
		free(game->mlx);
	ft_putstr_fd("malloc error initialization", 0);
	exit(0);
}

static void	check_init(t_game *game)
{
	if (game == NULL || game->param == NULL
	|| game->player == NULL
	|| game->sprite == NULL
	|| game->texture == NULL
	|| game->texture->north == NULL
	|| game->texture->south == NULL
	|| game->texture->east == NULL
	|| game->texture->west == NULL
	|| game->texture->sprite == NULL
	|| game->image == NULL || game->mlx == NULL)
		free_init(game);
}

static void	init_game1(t_game **game)
{
	if (!((*game)->image = (t_image *)malloc(sizeof(t_image))))
		(*game)->image = NULL;
	if (!((*game)->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		(*game)->mlx = NULL;
}

void		init_game(t_game **game)
{
	if (!(*game = (t_game *)malloc(sizeof(t_game))))
		*game = NULL;
	if (!((*game)->param = (t_param *)malloc(sizeof(t_param))))
		(*game)->param = NULL;
	init_param((*game)->param);
	if (!((*game)->player = (t_player *)malloc(sizeof(t_player))))
		(*game)->player = NULL;
	if (!((*game)->sprite = (t_sprite *)malloc(sizeof(t_sprite))))
		(*game)->sprite = NULL;
	if (!((*game)->texture = (t_texture *)malloc(sizeof(t_texture))))
		(*game)->texture = NULL;
	if (!((*game)->texture->north = (t_image *)malloc(sizeof(t_image))))
		(*game)->texture->north = NULL;
	if (!((*game)->texture->south = (t_image *)malloc(sizeof(t_image))))
		(*game)->texture->south = NULL;
	if (!((*game)->texture->east = (t_image *)malloc(sizeof(t_image))))
		(*game)->texture->east = NULL;
	if (!((*game)->texture->west = (t_image *)malloc(sizeof(t_image))))
		(*game)->texture->west = NULL;
	if (!((*game)->texture->sprite = (t_image *)malloc(sizeof(t_image))))
		(*game)->texture->sprite = NULL;
	init_game1(game);
	check_init(*game);
}
