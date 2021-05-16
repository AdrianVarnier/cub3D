/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:05:01 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/16 15:36:37 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "free.h"

void	check_north(char *s, t_game *game)
{
	int	i;

	i = 0;
	if (game->param->north_presence == 1)
		free_error("Error\nToo much north\n", s, game);
	while (s[i] != 'O')
		i++;
	i++;
	i = i + check_path(s + i);
	check_end(s + i, s, game);
	game->param->north_presence = 1;
}

void	check_south(char *s, t_game *game)
{
	int	i;

	i = 0;
	if (game->param->south_presence == 1)
		free_error("Error\nToo much south\n", s, game);
	while (s[i] != 'O')
		i++;
	i++;
	i = i + check_path(s + i);
	check_end(s + i, s, game);
	game->param->south_presence = 1;
}

void	check_west(char *s, t_game *game)
{
	int	i;

	i = 0;
	if (game->param->west_presence == 1)
		free_error("Error\nToo much west\n", s, game);
	while (s[i] != 'E')
		i++;
	i++;
	i = i + check_path(s + i);
	check_end(s + i, s, game);
	game->param->west_presence = 1;
}

void	check_east(char *s, t_game *game)
{
	int	i;

	i = 0;
	if (game->param->east_presence == 1)
		free_error("Error\nToo much east\n", s, game);
	while (s[i] != 'A')
		i++;
	i++;
	i = i + check_path(s + i);
	check_end(s + i, s, game);
	game->param->east_presence = 1;
}

void	check_sprite(char *s, t_game *game)
{
	int	i;

	i = 0;
	if (game->param->sprite_presence == 1)
		free_error("Error\nToo much sprite\n", s, game);
	while (s[i] != 'S')
		i++;
	i++;
	i = i + check_path(s + i);
	check_end(s + i, s, game);
	game->param->sprite_presence = 1;
}
