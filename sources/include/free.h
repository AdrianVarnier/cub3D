/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:38:40 by avarnier          #+#    #+#             */
/*   Updated: 2021/04/14 13:51:10 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "struct.h"
# include <stdlib.h>
# include <stdio.h>

void	free_error(char *s1, char *s2, t_param *param);
void	free_map_line(char *s, int i, t_game *game);
void	free_param_error(char *s, t_game *game);
void	free_exit(t_game *game);
void	free_save(t_game *game);
int		free_cross_exit(t_game *game);

#endif
