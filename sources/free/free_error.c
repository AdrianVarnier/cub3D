/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 14:43:39 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/16 02:21:38 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_error(char *s1, char *s2, t_game *game)
{
	free(s2);
	ft_putstr_fd(s1, 0);
	free_game(game);
}
