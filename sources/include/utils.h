/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avarnier <avarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:26:55 by avarnier          #+#    #+#             */
/*   Updated: 2021/05/31 18:43:01 by avarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
int		ft_isdigit(int c);
int		ft_atoi(const char *s);
void	ft_bzero(void *s, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t len);
char	*ft_strdup(const char *s);
char	*ft_itoa_base(int n, char *base);
int		ft_atoi_base(char *s, char *base);
void	ft_putstr_fd(char *s, int fd);
char	*first_hexa(int x);
char	*last_hexa(int x, char *hexa);

#endif
