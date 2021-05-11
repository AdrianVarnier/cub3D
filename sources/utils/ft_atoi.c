/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:44:57 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/11 23:34:22 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_atoi(const char *s)
{
	int				i;
	unsigned int	x;
	int				signe;

	i = 0;
	x = 0;
	signe = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			signe = -1;
		i++;
	}
	while (ft_isdigit(s[i]) == 1)
	{
		x = 10 * x + s[i] - '0';
		i++;
	}
	if (x > 2147483647)
		x = 2147483647;
	return ((int)x * signe);
}
