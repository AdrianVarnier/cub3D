/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 03:25:12 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 04:04:55 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"

int main()
{
	t_param	*param;
	param = check_error("map/map.cub");
	free(param);
	printf(":)");
	
	return (0);
}
