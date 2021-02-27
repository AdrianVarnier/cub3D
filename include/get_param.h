/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 23:07:37 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 23:13:23 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_PARAM_H
# define GET_PARAM_H

#include <stdlib.h>
#include "struct.h"

void	get_map(int fd, char *s, t_param *param);
void	get_north(char *s, t_param *param);
void	get_south(char *s, t_param *param);
void	get_west(char *s, t_param *param);
void	get_east(char *s, t_param *param);
void	get_sprite(char *s, t_param *param);
void	get_res(char *s, t_param *param);
void	get_floor(char *s, t_param *param);
void	get_ceil(char *s, t_param *param);
void	get_param(char *s, t_param *param);
void	get_all_param(int fd, char *s, t_param *param);
char	*ft_strjoin_free(char *s1, char *s2);
int		get_color(char *s);
int		get_int(char *s);
int		pass_int(char *s);
char	*get_path(char *s);

#endif
