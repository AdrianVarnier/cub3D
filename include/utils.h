/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:26:55 by avarnier          #+#    #+#             */
/*   Updated: 2021/02/27 03:00:36 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line);
int	ft_isdigit(int c);
int	ft_atoi(const char *s);
void	ft_bzero(void *s, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif
