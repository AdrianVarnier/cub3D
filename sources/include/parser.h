/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:20:19 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/06 23:13:58 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <stdio.h>
# include "struct.h"

void	check_north(char *s, t_param *param);
void	check_south(char *s, t_param *param);
void	check_west(char *s, t_param *param);
void	check_east(char *s, t_param *param);
void	check_sprite(char *s, t_param *param);
void	check_map_line(int fd, char *s, t_param *param);
void	check_param(char *s, t_param *param);
void	check_floor(char *s, t_param *param);
void	check_ceil(char *s, t_param *param);
void	check_resolution(char *s, t_param *param);
int		check_int(char *s1, char *s2, t_param *param);
int		check_color(char *s1, char *s2, t_param *param);
int		check_path(char *s1, char *s2, t_param *param);
void	check_end(char *s1, char *s2, t_param *param);
int		check_space(char *s);
void	check_type(char *s, t_param *param);
void	check_pathname(char *s);
void	check_map_char(char *s, t_param *param);
void	check_error(int fd, char *s, t_param *param);
void	get_map(int fd, char *s, t_game *game);
void	get_north(char *s, t_param *param);
void	get_south(char *s, t_param *param);
void	get_west(char *s, t_param *param);
void	get_east(char *s, t_param *param);
void	get_sprite(char *s, t_param *param);
void	get_all_param(int fd, char *s, t_game *game);
char	*ft_strjoin_free(char *s1, char *s2);
int		get_color(char *s);
int		get_int(char *s);
int		pass_int(char *s);
char	*get_path(char *s);
void	check_map(t_game *game);
void	parse(char *pathname, t_game *game);

#endif
