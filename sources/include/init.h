/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 18:49:05 by avarnier          #+#    #+#             */
/*   Updated: 2021/06/02 18:21:37 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "struct.h"
# include "stdio.h"
# include <stdlib.h>

void	init_param(t_param *param);
void	init_player(t_param *param, t_player *player);
void	init_game(t_game **game);
void	init_texture(t_game *game);
void	init_sprite(t_sprite *sprite, t_param *param, t_game *game);

#endif
