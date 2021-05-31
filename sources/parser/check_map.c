/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:55:05 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/14 14:53:45 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "parser.h"

static void	check_one_map(t_game *game)
{
	int	i;

	i = 2;
	while (i < game->param->map_height + 1)
	{
		if (check_space(game->param->map[i]) == 1
			&& check_space(game->param->map[i + 1]) == 0)
			free_param_error("Error\nMore than one map\n", game);
		i++;
	}
}

static void	check_map_space1(char **map, t_game *game)
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
					free_param_error("Error\nMap is open\n", game);
			}
			j++;
		}
		j = 1;
		i++;
	}
}

static void	check_map_space2(char **map, t_game *game)
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
					free_param_error("Error\nMap is open\n", game);
			}
			j++;
		}
		j = 1;
		i++;
	}
}

static void	check_one_player(char **map, t_game *game)
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
				k++;
			j++;
		}
		j = 0;
		i++;
	}
	if (k != 1)
		free_param_error("Error\nWrong number player\n", game);
}

void	check_map(t_game *game)
{
	check_one_map(game);
	check_map_space1(game->param->map, game);
	check_map_space2(game->param->map, game);
	check_one_player(game->param->map, game);
}
