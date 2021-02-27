/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:55:14 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 21:07:50 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_param.h"

void	get_north(char *s, t_param *param)
{
	int	i;

	i = 0;
	while (s[i] != 'O')
		i++;
	i++;
	param->north = get_path(s + i);
}

void	get_south(char *s, t_param *param)
{
	int	i;

	i = 0;
	while (s[i] != 'O')
		i++;
	i++;
	param->south = get_path(s + i);
}

void	get_west(char *s, t_param *param)
{
	int	i;

	i = 0;
	while (s[i] != 'E')
		i++;
	i++;
	param->west = get_path(s + i);
}

void	get_east(char *s, t_param *param)
{
	int	i;

	i = 0;
	while (s[i] != 'A')
		i++;
	i++;
	param->east = get_path(s + i);
}

void	get_sprite(char *s, t_param *param)
{
	int	i;

	i = 0;
	while (s[i] != 'S')
		i++;
	i++;
	param->sprite = get_path(s + i);
}
