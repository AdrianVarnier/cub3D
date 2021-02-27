/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 01:38:24 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 04:01:24 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

void	free_error(char *s1, char *s2, t_param *param)
{
	free(s2);
	free(param);
	perror(s1);
	exit(0);
}


