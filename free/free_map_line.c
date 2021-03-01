/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:44:55 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/28 14:45:22 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

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
