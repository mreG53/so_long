/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <emgumus@student.42kocaeli.com.tr>   +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:36:42 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/15 04:36:42 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../includes/get_next_line.h"

int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror("Error opening map file");
	return (fd);
}

char	**process_map_lines(int fd)
{
	char	*line;
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * 100);
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}


char	**read_map_file(char *filename)
{
	int		fd;
	char	**map;

	fd = open_map_file(filename);
	if (fd == -1)
		return (NULL);
	map = process_map_lines(fd);
	close(fd);
	return (map);
}
