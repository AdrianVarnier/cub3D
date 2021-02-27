/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:16:37 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 18:28:02 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_param
{
	int		width;
	int		height;
	int		map_width;
	int		map_height;
	int		floor;
	int		ceil;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	char	*sprite;
	char	**map;
	int		resolution_presence;
	int		north_presence;
	int		south_presence;
	int		east_presence;
	int		west_presence;
	int		sprite_presence;
	int		floor_presence;
	int		ceil_presence;
}				t_param;

#endif
