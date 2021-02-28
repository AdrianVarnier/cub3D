/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:55:05 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/28 01:04:34 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "parser.h"

static void	check_one_map(t_param *param)
{
	int	i;

	i = 2;
	while (i < param->map_height + 1)
	{
		if (check_space(param->map[i]) == 1 &&
		check_space(param->map[i + 1]) == 0)
			free_param_error("More than one map", param);
		i++;
	}
}

static void	check_map_space1(char **map, t_param *param)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (map[i + 1] != NULL)
	{
		while (map[i][j + 1] != '\0')
		{
			if (map[i][j] == ' ')
			{
				if ((map[i][j - 1] != '1' && map[i][j - 1] != ' ')
				|| (map[i][j + 1] != '1' && map[i][j + 1] != ' ')
				|| (map[i - 1][j] != '1' && map[i - 1][j] != ' ')
				|| (map[i + 1][j] != '1' && map[i + 1][j] != ' '))
					free_param_error("Map is open", param);
			}
			j++;
		}
		j = 1;
		i++;
	}
}

static void	check_map_space2(char **map, t_param *param)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (map[i + 1] != NULL)
	{
		while (map[i][j + 1] != '\0')
		{
			if (map[i][j] == ' ')
			{
				if ((map[i - 1][j - 1] != '1' && map[i - 1][j - 1] != ' ')
				|| (map[i + 1][j - 1] != '1' && map[i + 1][j - 1] != ' ')
				|| (map[i - 1][j + 1] != '1' && map[i - 1][j + 1] != ' ')
				|| (map[i + 1][j + 1] != '1' && map[i + 1][j + 1] != ' '))
					free_param_error("Map is open", param);
			}
			j++;
		}
		j = 1;
		i++;
	}
}

static void	check_one_player(char **map, t_param *param)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (k == 1)
					free_param_error("Too much player", param);
				else
					k = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void		check_map(t_param *param)
{
	check_one_map(param);
	check_map_space1(param->map, param);
	check_map_space2(param->map, param);
	check_one_player(param->map, param);
}
