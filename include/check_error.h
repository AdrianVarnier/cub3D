/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:20:19 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 03:46:26 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERROR_H
# define CHECK_ERROR_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "struct.h"
# include "free.h"
# include "utils.h"

void	check_north(char *s, t_param *param);
void	check_south(char *s, t_param *param);
void	check_west(char *s, t_param *param);
void	check_east(char *s, t_param *param);
void	check_sprite(char *s, t_param *param);
int	check_int(char *s1, char *s2, t_param *param);
int	check_color(char *s1, char *s2, t_param *param);
int	check_path(char *s1, char *s2, t_param *param);
void	check_end(char *s1, char *s2, t_param *param);
int	check_space(char *s);
void	check_type(char *s, t_param *param);
void	check_pathname(char *s);
void	check_map_char(char *s, t_param *param);
t_param	*check_error(char *pathname);
void	check_all_param(int fd, char *s, t_param *param);

#endif
