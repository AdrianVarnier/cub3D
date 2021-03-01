/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_param_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:45:38 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/28 14:48:01 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_param_error(char *s, t_param *param)
{
	int	i;

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
	perror(s);
	exit(0);
}
