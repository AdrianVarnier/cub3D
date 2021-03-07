/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:49:15 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/06 22:01:17 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "struct.h"

void		render(t_game *game, double distance, int x);
int			get_texture_pixel_north(t_texture *texture, double y);
int			get_texture_pixel_south(t_texture *texture, double y);
int			get_texture_pixel_east(t_texture *texture, double y);
int			get_texture_pixel_west(t_texture *texture, double y);

#endif
