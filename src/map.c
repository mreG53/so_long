/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:36:42 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/08 00:23:09 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../includes/get_next_line.h"

static int	get_map_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static void	cleanup_map(char **map, int count)
{
	while (count >= 0)
	{
		free(map[count]);
		count--;
	}
	free(map);
}

static char	**process_lines(int fd, int height, char **map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && i < height)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map[i++] = line;
		line = get_next_line(fd);
	}
	free(line);
	return (map);
}

static char	**process_map_lines(int fd, int height)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i <= height)
		map[i++] = NULL;
	map = process_lines(fd, height, map);
	if (!map)
		return (NULL);
	i = 0;
	while (map[i] && i < height)
		i++;
	if (i != height)
	{
		cleanup_map(map, height);
		return (NULL);
	}
	return (map);
}

char	**read_map_file(char *filename)
{
	int		fd;
	char	**map;
	int		height;

	height = get_map_height(filename);
	if (height <= 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = process_map_lines(fd, height);
	close(fd);
	return (map);
}
