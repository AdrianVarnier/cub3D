/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:05:01 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 03:48:29 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"

void	check_north(char *s, t_param *param)
{
	int	i;

	i = 0;
	if (param->north_presence == 1)
		free_error("Too much north\n", s, param);
	while (s[i] != 'O')
		i++;
	i++;
	i = i + check_path(s + i, s, param);
	check_end(s + i, s, param);
	param->north_presence = 1;
}

void	check_south(char *s, t_param *param)
{
	int	i;

	i = 0;
	if (param->south_presence == 1)
		free_error("Too much south\n", s, param);
	while (s[i] != 'O')
		i++;
	i++;
	i = i + check_path(s + i, s, param);
	check_end(s + i, s, param);
	param->south_presence = 1;
}

void	check_west(char *s, t_param *param)
{
	int	i;

	i = 0;
	if (param->west_presence == 1)
		free_error("Too much west\n", s, param);
	while (s[i] != 'E')
		i++;
	i++;
	i = i + check_path(s + i, s, param);
	check_end(s + i, s, param);
	param->west_presence = 1;
}

void	check_east(char *s, t_param *param)
{
	int	i;

	i = 0;
	if (param->east_presence == 1)
		free_error("Too much east\n", s, param);
	while (s[i] != 'A')
		i++;
	i++;
	i = i + check_path(s + i, s, param);
	check_end(s + i, s, param);
	param->east_presence = 1;
}

void	check_sprite(char *s, t_param *param)
{
	int	i;

	i = 0;
	if (param->sprite_presence == 1)
		free_error("Too much sprite\n", s, param);
	while (s[i] != 'S')
		i++;
	i++;
	i = i + check_path(s + i, s, param);
	check_end(s + i, s, param);
	param->sprite_presence = 1;
}
