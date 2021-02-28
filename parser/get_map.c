/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 21:08:43 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/28 00:43:17 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "free.h"
#include "utils.h"

static char	*get_map_line(char *s, t_param *param)
{
	int		i;
	int		j;
	int		l;
	char	*cpy;

	l = param->width;
	if (!(cpy = (char *)malloc(sizeof(char) * (l + 1 + 4))))
		return (NULL);
	i = 2;
	j = 0;
	cpy[0] = ' ';
	cpy[1] = ' ';
	while (s[j] != '\0')
	{
		cpy[i] = s[j];
		i++;
		j++;
	}
	while (i < l + 4)
	{
		cpy[i] = ' ';
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

void		get_map(int fd, char *s, t_param *param)
{
	int	ret;
	int	i;

	i = 2;
	ret = get_next_line(fd, &s);
	while (check_space(s) == 1 && ret == 1)
	{
		free(s);
		ret = get_next_line(fd, &s);
	}
	while (ret > 0)
	{
		if (!(param->map[i] = get_map_line(s, param)))
			free_map_line(s, i, param);
		i++;
		free(s);
		ret = get_next_line(fd, &s);
	}
	free(s);
	param->map[i] = get_map_line("", param);
	param->map[i + 1] = get_map_line("", param);
	param->map[0] = get_map_line("", param);
	param->map[1] = get_map_line("", param);
}
