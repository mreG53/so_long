/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 06:02:20 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/14 21:48:11 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/game.h"
#include "../includes/ft_printf.h"
#include "../includes/move.h"
#include <stdlib.h>

void	free_all(t_game *game);

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
		free_all(g);
	update_direction(g, key, &nx, &ny);
	check_tile(g, &nx, &ny);
	update_move(g, nx, ny);
	refresh_game(g);
	check_enemy_collision(g);
	return (0);
}

int	handle_destroy(t_game *game)
{
	free_all(game);
	return (0);
}

void	setup_hooks(t_game *g)
{
	if (!g || !g->win)
		return ;
	mlx_expose_hook(g->win, refresh_game, g);
	mlx_hook(g->win, 2, 1L << 0, handle_key, g);
	mlx_hook(g->win, 17, 0, handle_destroy, g);
}
