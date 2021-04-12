/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:19:56 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 19:21:28 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = ft_strlen(s) + 1;
	if (!(cpy = (char *)malloc(sizeof(char) * len)))
		return (0);
	ft_memcpy(cpy, s, len);
	return (cpy);
}
