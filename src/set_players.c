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

void	set_player_position(t_game *game, char **map, int i, int j)
{
	game->player.x = j;
	game->player.y = i;
	game->player.dir = RIGHT;
	game->player.left_anim.current_frame = 0;
	game->player.left_anim.frame_count = 4;
	game->player.right_anim.current_frame = 0;
	game->player.right_anim.frame_count = 4;
	map[i][j] = '0';
}
