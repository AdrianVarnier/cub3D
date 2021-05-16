/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 01:35:22 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/16 02:24:38 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "free.h"

void	check_type(char *s, t_game *game)
{
	if (s[0] != 'R' && s[0] != 'S' && s[0] != 'F' && s[0] != 'C' &&
	s[0] != 'N' && s[0] != 'W' && s[0] != 'E')
		free_error("Error\nwrong type\n", s, game);
	if ((s[0] == 'N' && s[1] != 'O') || (s[0] == 'W' && s[1] != 'E') ||
	(s[0] == 'E' && s[1] != 'A') || (s[0] == 'S' && s[1] != 'O' &&
	(!(s[1] == ' ' || (s[1] >= 9 && s[1] <= 13)))))
		free_error("Error\nwrong type\n", s, game);
}

void	check_pathname(char *s, t_game *game)
{
	int	i;

	i = 1;
	while (s[i] != '\0' && s[i] != '.')
		i++;
	if (s[i + 1] != 'c' || s[i + 2] != 'u' || s[i + 3] != 'b')
	{
		ft_putstr_fd("Error\nNo .cub file\n", 0);
		free_game(game);
	}
}

void	check_map_char(char *s, t_game *game)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != '2' &&
		s[i] != 'N' && s[i] != 'S' && s[i] != 'W' && s[i] != 'E'
		&& s[i] != ' ' && (!(s[i] >= 9 && s[i] <= 13)))
			free_error("Error\nWrong map\n", s, game);
		i++;
	}
}
