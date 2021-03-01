/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:32:41 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/01 01:33:46 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include <math.h>
# include "struct.h"

# define FOV 60 * (M_PI / 180)
# define TILE_SIZE 32
# define WALL_STRIPE_WIDTH 1

double	check_horizontal_intersection(t_param *param, t_player *player, t_texture *texture, double angle);
double	check_vertical_intersection(t_param *param, t_player *player, t_texture *texture, double angle);
void	raycast(t_param *param, t_player *player, t_image *image, t_texture *texture);

#endif
