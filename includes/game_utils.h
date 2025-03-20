/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:17:44 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/19 18:21:57 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_H
# define GAME_UTILS_H

# include "game.h"

int		is_can_walk(char **map, int x, int y);
int		rem_col(char **map);
int		get_loaded_map_h(char **map);
void	free_map(char **map);

int		get_enemy_count(char **map);
void	set_player_position(t_game *game, char **map, int i, int j);
void	set_single_enemy(t_enemy *enemy, int x, int y);

#endif