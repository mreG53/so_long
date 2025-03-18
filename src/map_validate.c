/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:38:43 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/15 04:38:43 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_printf.h"
#include "../includes/get_next_line.h"
#include "../includes/map_elements.h"

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
	while (map[height])
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
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
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
