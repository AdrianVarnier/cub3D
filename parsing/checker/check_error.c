/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:13:21 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 04:09:29 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"

static void	check_map_line(int fd, char *s, t_param *param)
{
	int ret;
	int c;

	c = 0;
	ret = get_next_line(fd, &s);
	while (check_space(s) == 1 && ret == 1)
	{
		free(s);
		ret = get_next_line(fd, &s);
	}
	if (ret == 0)
		free_error("No map\n", s, param);
	while (ret > 0)
	{
		check_map_char(s, param);
		if (param->map_width < (int)ft_strlen(s))
			param->map_width = ft_strlen(s);
		c++;
		free(s);
		ret = get_next_line(fd, &s);
	}
	free(s);
	param->map_height = c;
}

t_param		*check_error(char *pathname)
{
	int		fd;
	char	*s;
	t_param	*param;

	s = NULL;
	check_pathname(pathname);
	if ((fd = open(pathname, O_RDONLY)) == -1)
	{
		perror("Cannot open file.cub\n");
		exit(0);
	}
	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
//	init(param);
	check_all_param(fd, s, param);
	check_map_line(fd, s, param);
	close(fd);
	return (param);
}
