/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 02:06:11 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/09 14:39:51 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_game(t_game **game)
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
	if (!((*game)->image = (t_image *)malloc(sizeof(t_image))))
		(*game)->image = NULL;
	if (!((*game)->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		(*game)->mlx = NULL;
}
