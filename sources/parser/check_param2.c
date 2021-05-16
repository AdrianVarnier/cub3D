/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 01:58:58 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/16 15:37:09 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "free.h"
#include "utils.h"

void	check_resolution(char *s, t_game *game)
{
	int	i;

	i = 0;
	if (game->param->resolution_presence == 1)
		free_error("Error\nToo much resolution\n", s, game);
	while (s[i] != 'R')
		i++;
	i++;
	i = i + check_int(s + i, s, game);
	i = i + check_int(s + i, s, game);
	check_end(s + i, s, game);
	game->param->resolution_presence = 1;
}

void	check_ceil(char *s, t_game *game)
{
	int	i;

	i = 0;
	if (game->param->ceil_presence == 1)
		free_error("Error\nToo much ceiling\n", s, game);
	while (s[i] != 'C')
		i++;
	i++;
	i = i + check_color(s + i, s, game);
	check_end(s + i, s, game);
	game->param->ceil_presence = 1;
}

void	check_floor(char *s, t_game *game)
{
	int	i;

	i = 0;
	if (game->param->floor_presence == 1)
		free_error("Error\nToo much floor\n", s, game);
	while (s[i] != 'F')
		i++;
	i++;
	i = i + check_color(s + i, s, game);
	check_end(s + i, s, game);
	game->param->floor_presence = 1;
}

void	check_param(char *s, t_game *game)
{
	int	i;

	i = 0;
	check_type(s, game);
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == 'R')
		check_resolution(s, game);
	if (s[i] == 'F')
		check_floor(s, game);
	if (s[i] == 'C')
		check_ceil(s, game);
	if (s[i] == 'N')
		check_north(s, game);
	if (s[i] == 'S' && s[i + 1] == 'O')
		check_south(s, game);
	if (s[i] == 'W')
		check_west(s, game);
	if (s[i] == 'E')
		check_east(s, game);
	if (s[i] == 'S' && s[i + 1] != 'O')
		check_sprite(s, game);
}

void	check_map_line(int fd, char *s, t_game *game)
{
	int ret;
	int c;

	c = 0;
	ret = get_next_line(fd, &s);
	while (check_space(s) == 1 && ret == 1)
	{
		free(s);
		ret = get_next_line(fd, &s);
	}
	if (ret == 0)
		free_error("Error\nNo map\n", s, game);
	while (ret > 0)
	{
		check_map_char(s, game);
		if (game->param->map_width < (int)ft_strlen(s))
			game->param->map_width = ft_strlen(s);
		c++;
		free(s);
		ret = get_next_line(fd, &s);
	}
	free(s);
	game->param->map_height = c;
}
