/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:00:00 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/20 22:38:33 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

int	update_direction(t_game *g, int key, int *nx, int *ny);
int	check_tile(t_game *g, int *nx, int *ny);
int	update_move(t_game *g, int nx, int ny);
int	check_enemy_collision(t_game *g);
int	refresh_game(t_game *g);

#endif
