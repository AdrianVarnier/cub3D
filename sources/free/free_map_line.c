/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:44:55 by avarnier          #+#    #+#             */
/*   Updated: 2021/06/01 17:42:05 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_map_line(char *s, int i, t_game *game)
{
	int	c;

	c = 0;
	free(game->param->north);
	free(game->param->south);
	free(game->param->west);
	free(game->param->east);
	free(game->param->sprite);
	free(s);
	while (c < i)
	{
		free(game->param->map[c]);
		c++;
	}
	free(game->param->map);
	free(game->param);
	free(game);
	ft_putstr_fd("Eroor\nmap line malloc error\n", 0);
	exit(0);
}
