/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 01:35:22 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 03:24:54 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"

void	check_type(char *s, t_param *param)
{
	if (s[0] != 'R' && s[0] != 'S' && s[0] != 'F' && s[0] != 'C' &&
	s[0] != 'N' && s[0] != 'W' && s[0] != 'E')
		free_error("wrong type\n", s, param);
	if ((s[0] == 'N' && s[1] != 'O') || (s[0] == 'W' && s[1] != 'E') ||
	(s[0] == 'E' && s[1] != 'A') || (s[0] == 'S' && s[1] != 'O' &&
	(!(s[1] == ' ' || (s[1] >= 9 && s[1] <= 13)))))
		free_error("wrong type\n", s, param);
}

void	check_pathname(char *s)
{
	int	i;

	i = 1;
	while (s[i] != '\0' && s[i] != '.')
		i++;
	if (s[i + 1] != 'c' || s[i + 2] != 'u' || s[i + 3] != 'b')
	{
		perror("No .cub file\n");
		exit(0);
	}
}

void	check_map_char(char *s, t_param *param)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '0' && s[i] != '1' && s[i] != '2' &&
		s[i] != 'N' && s[i] != 'S' && s[i] != 'W' && s[i] != 'E'
		&& s[i] != ' ' && (!(s[i] >= 9 && s[i] <= 13)))
			free_error("Wrong map\n", s, param);
		i++;
	}
}
