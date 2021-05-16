/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:45:38 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/16 02:18:30 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

static void	free_param_error1(t_game *game)
{
	int	i;

	i = 0;
	free(game->param->north);
	free(game->param->south);
	free(game->param->west);
	free(game->param->east);
	free(game->param->sprite);
	while (game->param->map[i] != NULL)
	{
		free(game->param->map[i]);
		i++;
	}
	free(game->param->map[i]);
	free(game->param->map);
	free(game->param);
}

void		free_param_error(char *s, t_game *game)
{
	free_param_error1(game);
	free(game->texture->north);
	free(game->texture->south);
	free(game->texture->east);
	free(game->texture->west);
	free(game->texture->sprite);
	free(game->texture);
	free(game->image);
	free(game->mlx);
	free(game->sprite);
	free(game->player);
	free(game);
	ft_putstr_fd(s, 0);
	exit(0);
}
