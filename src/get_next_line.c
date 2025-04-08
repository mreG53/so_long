/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 01:20:27 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/05 23:27:14 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*g_buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	g_buffer = ft_read(fd, g_buffer);
	if (!g_buffer)
		return (NULL);
	line = ft_getline(g_buffer);
	g_buffer = ft_getrm(g_buffer);
	return (line);
}

char	*ft_read(int fd, char *str)
{
	char	*tmp;
	int		byte;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	byte = 1;
	while (byte > 0 && !ft_strchr(str, '\n'))
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte == -1)
		{
			free(tmp);
			free(str);
			return (NULL);
		}
		tmp[byte] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*ft_getline(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_getrm(char *buffer)
{
	int		i;
	int		j;
	char	*remain;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	remain = malloc(sizeof(char) * (ft_strlen(buffer) - i));
	if (!remain)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		remain[j++] = buffer[i++];
	remain[j] = '\0';
	free(buffer);
	return (remain);
}
