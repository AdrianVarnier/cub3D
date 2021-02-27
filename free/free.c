/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 01:38:24 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 23:51:41 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void	free_error(char *s1, char *s2, t_param *param)
{
	free(s2);
	free(param);
	perror(s1);
	exit(0);
}

void	free_map_line(char *s, int i, t_param *param)
{
	int c;

	c = 0;
	free(s);
	while (c < i)
	{
		free(param->map[c]);
		c++;
	}
	free(param->map);
	free(param);
	perror("map line malloc error");
	exit(0);
}

void	free_param_error(char *s, t_param *param)
{
	int	i;

	i = 0;
	free(param->north);
	free(param->south);
	free(param->west);
	free(param->east);
	free(param->sprite);
	while (param->map[i] != NULL)
	{
		free(param->map[i]);
		i++;
	}
	free(param->map[i]);
	free(param->map);
	free(param);
	perror(s);
	exit(0);
}
