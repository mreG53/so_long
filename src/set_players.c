/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:16:18 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/04 04:00:00 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

int	get_enemy_count(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'X')
				count++;
	}
	return (count);
}

void	set_player_position(t_game *game, char **map, int i, int j)
{
	game->player.x = j;
	game->player.y = i;
	game->player.dir = RIGHT;
	game->player.left_anim.current_frame = 0;
	game->player.left_anim.frame_count = 4;
	game->player.right_anim = game->player.left_anim;
	map[i][j] = '0';
}

void	set_single_enemy(t_enemy *enemy, int x, int y)
{
	enemy->x = x;
	enemy->y = y;
}
