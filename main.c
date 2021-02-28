/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 03:25:12 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/28 01:26:13 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include "parser.h"

int main()
{
	int i;

	t_param	*param;
	param = parse("map/map.cub");
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
	printf(":)\n");
	
	return (0);
}
