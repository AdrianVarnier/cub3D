/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 02:06:11 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/05 04:24:22 by avarnier         ###   ########.fr       */
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
	if (!((*game)->texture = (t_texture *)malloc(sizeof(t_texture))))
		(*game)->texture = NULL;
	if (!((*game)->image = (t_image *)malloc(sizeof(t_image))))
		(*game)->image = NULL;
	if (!((*game)->minilibx = (t_minilibx *)malloc(sizeof(t_minilibx))))
		(*game)->minilibx = NULL;
}
