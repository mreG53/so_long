/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 05:55:43 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/15 05:55:43 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/get_next_line.h"
#include "../includes/map_elements.h"

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
	else if (c != '0' && c != '1' && c != '\n')
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
	if (elements.player != 1 || elements.exit != 1 || elements.collectible < 1 || elements.enemy < 1)
		return (0);
	return (elements.valid);
}
