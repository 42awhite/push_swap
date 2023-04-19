/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:36:24 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/06 21:00:17 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_gl_strlen(const char *str);
char	*ft_gl_strjoin(char const *s1, char const *s2);
void	*ft_gl_bzero(void *s, size_t n);
void	*ft_gl_calloc(size_t cont, size_t size);
char	*ft_gl_strchr(const char *s, int c);
char	*sget_next_line(int fd);

#endif