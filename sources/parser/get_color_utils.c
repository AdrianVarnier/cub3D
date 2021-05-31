/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:24:13 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/31 18:47:22 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

char	*first_hexa(int x)
{
	if (x == 0)
		return (ft_strdup("00"));
	return (ft_itoa_base(x, "0123456789abcdef"));
}

char	*last_hexa(int x, char *hexa)
{
	if (x == 0)
		return (ft_strjoin_free(hexa, ft_strdup("00")));
	return (ft_strjoin_free(hexa, ft_itoa_base(x, "0123456789abcdef")));
}
