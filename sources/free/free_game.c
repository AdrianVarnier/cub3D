/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:28:49 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/11 21:47:49 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_game(t_game *game)
{
	free(game->param);
	free(game->player);
	free(game->sprite);
	free(game->texture->north);
	free(game->texture->south);
	free(game->texture->east);
	free(game->texture->west);
	free(game->texture->sprite);
	free(game->texture);
	free(game->image);
	free(game->mlx);
	free(game);
	exit(0);
}
