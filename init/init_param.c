/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:33:18 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/28 14:42:56 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_param(t_param *param)
{
	param->width = 0;
	param->height = 0;
	param->map_width = 0;
	param->map_height = 0;
	param->floor = 0;
	param->ceil = 0;
	param->north = NULL;
	param->south = NULL;
	param->east = NULL;
	param->west = NULL;
	param->map = NULL;
	param->resolution_presence = 0;
	param->north_presence = 0;
	param->south_presence = 0;
	param->east_presence = 0;
	param->west_presence = 0;
	param->sprite_presence = 0;
	param->floor_presence = 0;
	param->ceil_presence = 0;
}
