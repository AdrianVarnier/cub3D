/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:10:16 by avarnier          #+#    #+#             */
/*   Updated: 2021/04/30 12:47:39 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

static void	get_resolution(char *s, t_param *param)
{
	int	i;

	i = 0;
	while (s[i] != 'R')
		i++;
	i++;
	param->width = get_int(s + i);
	i = i + pass_int(s + i);
	param->height = get_int(s + i);
}

static void	get_floor(char *s, t_param *param)
{
	int	i;

	i = 0;
	while (s[i] != 'F')
		i++;
	i++;
	param->floor = get_color(s + i);
}

static void	get_ceil(char *s, t_param *param)
{
	int	i;

	i = 0;
	while (s[i] != 'C')
		i++;
	i++;
	param->ceil = get_color(s + i);
}

static void	get_param(char *s, t_param *param)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == 'R')
		get_resolution(s, param);
	if (s[i] == 'N')
		get_north(s, param);
	if (s[i] == 'S' && s[i + 1] == 'O')
		get_south(s, param);
	if (s[i] == 'W')
		get_west(s, param);
	if (s[i] == 'E')
		get_east(s, param);
	if (s[i] == 'S' && s[i + 1] != 'O')
		get_sprite(s, param);
	if (s[i] == 'F')
		get_floor(s, param);
	if (s[i] == 'C')
		get_ceil(s, param);
}

void		get_all_param(int fd, char *s, t_game *game)
{
	int	c;

	c = 0;
	while (c < 8)
	{
		get_next_line(fd, &s);
		if (check_space(s) == 0)
		{
			get_param(s, game->param);
			c++;
		}
		free(s);
	}
	get_map(fd, s, game);
}
