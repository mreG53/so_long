/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 06:02:20 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/19 17:07:40 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/game.h"
#include "../includes/render.h"
#include "../includes/game_utils.h"
#include "../includes/ft_printf.h"
#include "../includes/move.h"
#include <stdlib.h>
#include <stdio.h>

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	handle_key(int key, t_game *g)
{
	int	nx;
	int	ny;

	nx = g->player.x;
	ny = g->player.y;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(g->mlx, g->win);
		free_map(g->map);
		free(g->enemies);
		exit(0);
	}
	update_direction(g, key, &nx, &ny);
	check_tile(g, &nx, &ny);
	update_move(g, nx, ny);
	check_enemy_collision(g);
	refresh_game(g);
	return (0);
}

void	setup_hooks(t_game *g)
{
	mlx_hook(g->win, 2, 1L << 0, handle_key, g);
}
