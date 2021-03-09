/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 22:49:15 by avarnier          #+#    #+#             */
/*   Updated: 2021/03/09 15:37:42 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "struct.h"

void		render_sprite(t_game *game);
void		render(t_game *game, double distance, int x);
int			get_texture_pixel_north(t_texture *texture, double y);
int			get_texture_pixel_south(t_texture *texture, double y);
int			get_texture_pixel_east(t_texture *texture, double y);
int			get_texture_pixel_west(t_texture *texture, double y);

#endif
