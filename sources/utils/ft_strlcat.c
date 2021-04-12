/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:15:39 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 19:16:20 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = ft_strlen(dst);
	if (i >= len)
		return (len + ft_strlen(src));
	ft_strlcpy(dst + i, src, len - i);
	return (i + ft_strlen(src));
}
