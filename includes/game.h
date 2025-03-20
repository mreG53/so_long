/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:33:08 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/20 23:07:02 by emgumus          ###   ########.fr       */
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
	t_direction	dir;
}				t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	t_img		img;
	t_player	player;
	t_enemy		*enemies;
	int			enemy_count;
	int			move_count;
}				t_game;

typedef struct s_pos
{
	int		x;
	int		y;
	char	type;
	char	**map;
}	t_pos;

#endif
