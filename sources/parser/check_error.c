/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:13:21 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/16 15:18:30 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "free.h"
#include "utils.h"

static void		read_error(char *s, t_game *game)
{
	ft_putstr_fd("Error\nRead error\n", 0);
	free(s);
	free_game(game);
}

void			check_error(int fd, char *s, t_game *game)
{
	int	ret;
	int	c;

	c = 0;
	ret = 1;
	while (c < 8 && ret == 1)
	{
		ret = get_next_line(fd, &s);
		if (ret == -1)
			read_error(s, game);
		if (check_space(s) == 0)
		{
			check_param(s, game);
			c++;
		}
		free(s);
	}
	if (ret == 0 && c != 8)
	{
		ft_putstr_fd("Error\nMissing parameter\n", 0);
		free_game(game);
	}
	check_map_line(fd, s, game);
}
