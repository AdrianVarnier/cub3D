/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 01:58:58 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/28 00:42:35 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "free.h"
#include "utils.h"

void	check_resolution(char *s, t_param *param)
{
	int	i;

	i = 0;
	if (param->resolution_presence == 1)
		free_error("Too much resolution\n", s, param);
	while (s[i] != 'R')
		i++;
	i++;
	i = i + check_int(s + i, s, param);
	i = i + check_int(s + i, s, param);
	check_end(s + i, s, param);
	param->resolution_presence = 1;
}

void	check_ceil(char *s, t_param *param)
{
	int	i;

	i = 0;
	if (param->ceil_presence == 1)
		free_error("Too much ceiling\n", s, param);
	while (s[i] != 'C')
		i++;
	i++;
	i = i + check_color(s + i, s, param);
	check_end(s + i, s, param);
	param->ceil_presence = 1;
}

void	check_floor(char *s, t_param *param)
{
	int	i;

	i = 0;
	if (param->floor_presence == 1)
		free_error("Too much floor\n", s, param);
	while (s[i] != 'F')
		i++;
	i++;
	i = i + check_color(s + i, s, param);
	check_end(s + i, s, param);
	param->floor_presence = 1;
}

void	check_param(char *s, t_param *param)
{
	int	i;

	i = 0;
	check_type(s, param);
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == 'R')
		check_resolution(s, param);
	if (s[i] == 'F')
		check_floor(s, param);
	if (s[i] == 'C')
		check_ceil(s, param);
	if (s[i] == 'N')
		check_north(s, param);
	if (s[i] == 'S' && s[i + 1] == 'O')
		check_south(s, param);
	if (s[i] == 'W')
		check_west(s, param);
	if (s[i] == 'E')
		check_east(s, param);
	if (s[i] == 'S' && s[i + 1] != 'O')
		check_sprite(s, param);
}

void	check_map_line(int fd, char *s, t_param *param)
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
		free_error("No map\n", s, param);
	while (ret > 0)
	{
		check_map_char(s, param);
		if (param->map_width < (int)ft_strlen(s))
			param->map_width = ft_strlen(s);
		c++;
		free(s);
		ret = get_next_line(fd, &s);
	}
	free(s);
	param->map_height = c;
}
