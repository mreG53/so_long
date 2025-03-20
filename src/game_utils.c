/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:21:40 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/19 18:25:44 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"
#include "../includes/get_next_line.h"

int		get_enemy_count(char **map);
void	set_player_position(t_game *game, char **map, int i, int j);
void	set_single_enemy(t_enemy *enemy, int x, int y);

int	get_loaded_map_h(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
		i++;
	return (i);
}

int	is_can_walk(char **map, int x, int y)
{
	if (!map || !map[y])
		return (0);
	if (map[y][x] == '1')
		return (0);
	return (1);
}

int	rem_col(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
