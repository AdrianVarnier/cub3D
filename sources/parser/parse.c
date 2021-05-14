/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 22:12:37 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/14 14:58:40 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "parser.h"
#include "init.h"
#include "free.h"

void	parse(char *pathname, t_game *game)
{
	int		fd;
	char	*s;

	s = NULL;
	check_pathname(pathname, game);
	if ((fd = open(pathname, O_RDONLY)) == -1)
	{
		ft_putstr_fd("Error\nCannot open file.cub\n", 0);
		free_game(game);
	}
	check_error(fd, s, game->param, game);
	close(fd);
	fd = open(pathname, O_RDONLY);
	if (!(game->param->map = (char **)malloc(sizeof(char *) *
	(game->param->map_height + 1 + 4))))
		free_param_error("Error\nmap malloc error\n", game);
	game->param->map[game->param->map_height + 4] = NULL;
	get_all_param(fd, s, game);
	close(fd);
	check_map(game);
}
