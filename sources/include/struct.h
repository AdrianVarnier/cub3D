/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:16:37 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/07 15:27:53 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_param
{
	int			width;
	int			height;
	int			map_width;
	int			map_height;
	int			floor;
	int			ceil;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	char		**map;
	int			resolution_presence;
	int			north_presence;
	int			south_presence;
	int			east_presence;
	int			west_presence;
	int			sprite_presence;
	int			floor_presence;
	int			ceil_presence;
}				t_param;

typedef struct	s_player
{
	double		x;
	double		y;
	int			turn_direction;
	int			walk_direction1;
	int			walk_direction2;
	double		rotation_angle;
	double		move_speed;
	double		rotation_speed;
}				t_player;

typedef struct	s_texture
{
	double			texturex;
	double			texturey;
	char			orientation;
	struct s_image	*north;
	struct s_image	*south;
	struct s_image	*east;
	struct s_image	*west;
	struct s_image	*sprite;
}				t_texture;

typedef struct	s_image
{
	void		*image;
	char		*data;
	int			ls;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_image;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
}				t_mlx;

typedef struct	s_sprite
{
	double	*x;
	double	*y;
	double	angle;
	double	distance;
	double	offset;
	int		top;
	int		left;
}				t_sprite;

typedef struct	s_game
{
	double				*wall_distance;
	struct s_param		*param;
	struct s_player		*player;
	struct s_sprite		*sprite;
	struct s_texture	*texture;
	struct s_image		*image;
	struct s_mlx		*mlx;
}				t_game;

#endif
