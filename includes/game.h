/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:33:08 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/16 05:33:08 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "images.h"
# include "anim.h"

typedef enum e_direction
{
	LEFT,
	RIGHT
}				t_direction;

typedef struct s_player
{
	int			x;
	int			y;
	t_direction	dir;
	t_anim		left_anim;
	t_anim		right_anim;
}				t_player;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			attacking;
	t_direction	dir;
	t_anim		idle_anim;
	t_anim		attack_anim;
}				t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_img		img;
	t_player	player;
	t_enemy		enemy;
}				t_game;

#endif
