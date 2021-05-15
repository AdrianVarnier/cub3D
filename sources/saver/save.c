/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:44:09 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/15 21:10:28 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"

static void	bmp_header(t_game *game, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 54 + 4 * game->param->width * game->param->height;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &game->param->width, 4);
	write(fd, &game->param->height, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &game->image->bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void		save(t_game *game)
{
	int	fd;
	int	x;
	int	y;

	y = game->param->height - 1;
	if ((fd = open("./image.bmp", O_RDWR  | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
		exit(0);
	bmp_header(game, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < game->param->width)
		{
			write(fd, &game->image->data[y * game->image->ls + x
			* (game->image->bpp / 8)], 4);
			x++;
		}
		y--;
	}
	close(fd);
}
