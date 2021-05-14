/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 01:33:24 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/14 14:56:55 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "free.h"
#include "utils.h"

int		check_int(char *s1, char *s2, t_param *param)
{
	int	i;

	i = 0;
	while (s1[i] == ' ' || (s1[i] >= 9 && s1[i] <= 13))
		i++;
	if (ft_isdigit(s1[i]) == 0)
		free_error("Error\nMissing resolution\n", s2, param);
	while (ft_isdigit(s1[i]) > 0)
		i++;
	if (s1[i] == '.')
		free_error("Error\nDo not accept float\n", s2, param);
	return (i);
}

int		check_color(char *s1, char *s2, t_param *param)
{
	int	i;
	int c;

	i = 0;
	c = 3;
	while (c > 0)
	{
		while (s1[i] == ' ' || (s1[i] >= 9 && s1[i] <= 13))
			i++;
		if (ft_isdigit(s1[i]) == 0)
			free_error("Error\nMissing color\n", s2, param);
		if (ft_atoi(s1 + i) > 255 || ft_atoi(s1 + i) < 0)
			free_error("Error\nWrong color\n", s2, param);
		while (ft_isdigit(s1[i]) > 0)
			i++;
		while (s1[i] == ' ' || (s1[i] >= 9 && s1[i] <= 13))
			i++;
		if (s1[i] != ',' && c != 1)
			free_error("Error\nMissing color\n", s2, param);
		if (c != 1)
			i++;
		c--;
	}
	return (i);
}

int		check_path(char *s1)
{
	int	i;

	i = 0;
	while (s1[i] == ' ' || (s1[i] >= 9 && s1[i] <= 13))
		i++;
	while (s1[i] != ' ' && (!(s1[i] >= 9 && s1[i] <= 13)) && s1[i] != '\0')
		i++;
	return (i);
}

void	check_end(char *s1, char *s2, t_param *param)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (!(s1[i] == ' ' || (s1[i] >= 9 && s1[i] <= 13)))
			free_error("Error\nToo much arguments\n", s2, param);
		i++;
	}
}

int		check_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}
