/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 19:11:33 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 19:24:09 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*cpy;

	if (!s1 || !s2)
		return (0);
	if (!(cpy = (char *)malloc(sizeof(char)
	* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	ft_strlcpy(cpy, s1, ft_strlen(s1) + 1);
	ft_strlcat(cpy, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free(s1);
	free(s2);
	return (cpy);
}

int		get_color(char *s)
{
	int		i;
	char	*hexa;
	int		x;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	x = ft_atoi(s + i);
	hexa = (x == 0 ? ft_strdup("00") : ft_itoa_base(x, "0123456789abcdef"));
	while (s[i] != ',')
		i++;
	i++;
	x = ft_atoi(s + i);
	hexa = (x == 0 ? ft_strjoin_free(hexa, ft_strdup("00")) :
	ft_strjoin_free(hexa, ft_itoa_base(x, "0123456789abcdef")));
	while (s[i] != ',')
		i++;
	i++;
	x = ft_atoi(s + i);
	hexa = (x == 0 ? ft_strjoin_free(hexa, ft_strdup("00")) :
	ft_strjoin_free(hexa, ft_itoa_base(x, "0123456789abcdef")));
	x = ft_atoi_base(hexa, "0123456789abcdef");
	free(hexa);
	return (x);
}

int		get_int(char *s)
{
	int		i;
	int		x;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	x = ft_atoi(s + i);
	return (x);
}

int		pass_int(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (ft_isdigit(s[i]) > 0)
		i++;
	return (i);
}

char	*get_path(char *s)
{
	int		i;
	int		j;
	int		k;
	char	*cpy;

	i = 0;
	j = ft_strlen(s) - 1;
	k = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	while (s[j] == ' ' || (s[j] >= 9 && s[j] <= 13))
		j--;
	if (!(cpy = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (i <= j)
	{
		cpy[k] = s[i];
		i++;
		k++;
	}
	cpy[k] = '\0';
	return (cpy);
}
