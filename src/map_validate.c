/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:38:43 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/08 01:56:46 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/map_elements.h"
#include <stddef.h>

size_t	ft_strlen(char *s);

int	is_rect(char **map)
{
	int	i;
	int	width;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

int	is_wall(char **map)
{
	int	i;
	int	width;
	int	height;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	height = 0;
	while (map[height] && map[height][0] != '\0')
		height++;
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	count_elements(char c, t_elements *elements)
{
	if (c == 'P')
		elements->player++;
	else if (c == 'E')
		elements->exit++;
	else if (c == 'C')
		elements->collectible++;
	else if (c == 'X')
		elements->enemy++;
	else if (c != '0' && c != '1')
		elements->valid = 0;
}

int	req_elements(char **map)
{
	t_elements	elements;
	int			i;
	int			j;

	elements.player = 0;
	elements.exit = 0;
	elements.collectible = 0;
	elements.enemy = 0;
	elements.valid = 1;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			count_elements(map[i][j], &elements);
			j++;
		}
		i++;
	}
	if (elements.player != 1 || elements.exit != 1 || elements.collectible < 1)
		return (0);
	return (elements.valid);
}

int	validate_map(char **map)
{
	if (!is_rect(map))
	{
		ft_printf("ERROR: Map is not rectangular!\n");
		return (0);
	}
	if (!is_wall(map))
	{
		ft_printf("ERROR: Map is not enclosed by walls!\n");
		return (0);
	}
	if (!req_elements(map))
	{
		ft_printf("ERROR: Map is missing required elements(P,E,C).\n");
		return (0);
	}
	return (1);
}
