/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:13:21 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/28 00:41:59 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "free.h"
#include "utils.h"

void		check_error(int fd, char *s, t_param *param)
{
	int	ret;
	int	c;

	c = 0;
	ret = 1;
	while (c < 8 && ret == 1)
	{
		ret = get_next_line(fd, &s);
		if (check_space(s) == 0)
		{
			check_param(s, param);
			c++;
		}
		free(s);
	}
	if (ret == 0 && c != 8)
	{
		free(param);
		perror("Missing parameter");
		exit(0);
	}
	check_map_line(fd, s, param);
}
