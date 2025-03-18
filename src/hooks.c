/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 06:02:20 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/16 06:02:20 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/game.h"
#include <stdlib.h>

#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game->map);
		exit(0);
	}
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player.x--;
		game->player.dir = LEFT;
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player.x++;
		game->player.dir = RIGHT;
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		game->player.y--;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->player.y++;
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
}
