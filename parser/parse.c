/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 22:12:37 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/28 01:23:05 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "parser.h"
#include "init.h"

t_param	*parse(char *pathname)
{
	int		fd;
	char	*s;
	t_param	*param;

	s = NULL;
	check_pathname(pathname);
	if ((fd = open(pathname, O_RDONLY)) == -1)
	{
		perror("Cannot open file.cub");
		exit(0);
	}
	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	init_param(param);
	check_error(fd, s, param);
	close(fd);
	fd = open(pathname, O_RDONLY);
	if (!(param->map = (char **)malloc(sizeof(char *) *
	(param->map_height + 1 + 4))))
		param->map = NULL;
	param->map[param->map_height + 4] = NULL;
	get_all_param(fd, s, param);
	close(fd);
	check_map(param);
	return (param);
}
