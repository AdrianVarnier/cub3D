/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:45:38 by avarnier          #+#    #+#             */
/*   Updated: 2021/04/14 12:56:25 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_param_error(char *s, t_game *game)
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
	free(game);
	perror(s);
	exit(0);
}
