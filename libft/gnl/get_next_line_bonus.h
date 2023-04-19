/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:36:24 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/06 20:40:14 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_gnl_strlen(const char *str);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
void	*ft_gnl_bzero(void *s, size_t n);
void	*ft_gnl_calloc(size_t cont, size_t size);
char	*ft_gnl_strchr(const char *s, int c);
char	*get_next_line_bonus(int fd);

#endif