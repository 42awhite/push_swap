/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanco- <ablanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:57:50 by ablanco-          #+#    #+#             */
/*   Updated: 2023/03/06 21:00:17 by ablanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_sjoin_free(char *txt, char *buffer)
{
	char	*aux;

	aux = ft_gl_strjoin(txt, buffer);
	free(txt);
	return (aux);
}

char	*sread_join_buf(int fd, char *txt)
{
	char	*buffer;
	int		buf_size;

	buffer = ft_gl_calloc(BUFFER_SIZE + 1, sizeof (char));
	if (!buffer)
		return (NULL);
	buf_size = 1;
	while (buf_size > 0)
	{
		buf_size = read(fd, buffer, BUFFER_SIZE);
		if (buf_size == -1)
		{
			free (txt);
			free(buffer);
			return (NULL);
		}
		buffer[buf_size] = '\0';
		txt = ft_sjoin_free(txt, buffer);
		if (ft_gl_strchr(txt, '\n'))
			break ;
	}
	free (buffer);
	return (txt);
}

char	*ft_sline(char *buffer)
{
	size_t		pos_n;
	char		*str_line;

	pos_n = 0;
	if (!buffer[pos_n])
		return (NULL);
	while ((buffer[pos_n] != '\n' && buffer[pos_n] != '\0'))
			pos_n++;
	if (buffer[pos_n] == '\n')
		str_line = ft_gl_calloc(pos_n + 2, sizeof(char));
	else
		str_line = ft_gl_calloc(pos_n + 1, sizeof(char));
	if (!str_line)
		return (NULL);
	pos_n = -1;
	while (buffer[++pos_n] != '\n' && buffer[pos_n] != '\0')
		str_line[pos_n] = buffer[pos_n];
	if (buffer[pos_n] == '\n' && buffer[pos_n])
		str_line[pos_n] = '\n';
	return (str_line);
}

char	*ssave_txt(char *buffer)
{
	char	*txt;
	size_t	pos_n;
	size_t	c_txt;

	if (!buffer)
		return (NULL);
	pos_n = 0;
	while (buffer[pos_n] != '\n' && buffer[pos_n])
		pos_n++;
	if (!buffer[pos_n])
	{
		free (buffer);
		return (NULL);
	}
	txt = ft_gl_calloc(ft_gl_strlen(buffer) - pos_n + 1, sizeof(char));
	c_txt = 0;
	pos_n++;
	while (buffer[pos_n])
	{
		txt[c_txt] = buffer[pos_n];
		pos_n++;
		c_txt++;
	}
	free (buffer);
	return (txt);
}

char	*sget_next_line(int fd)
{
	static char		*buffer;
	char			*line;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = sread_join_buf(fd, buffer);
	line = ft_sline(buffer);
	buffer = ssave_txt(buffer);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*buf;
	int		cont;

	fd = open ("file.txt", O_RDONLY);
	cont = 1;
	while (cont <= 5)
	{	
		buf = sget_next_line(fd);
		printf("%s", buf);
		free(buf);
		cont++;
	}
	close(fd);
}
*/