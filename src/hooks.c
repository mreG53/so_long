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
#include "../includes/render.h"
#include <stdlib.h>
#include <stdio.h> // debug için

#define KEY_ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

void free_map(char **map)
{
	int i = 0;
	if (!map)
		return;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	handle_key(int keycode, t_game *game)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		free_map(game->map);
		exit(0);
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player.x++;
		game->player.dir = RIGHT;
		game->player.right_anim.current_frame = 
			(game->player.right_anim.current_frame + 1) % game->player.right_anim.frame_count;
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player.x--;
		game->player.dir = LEFT;
		game->player.left_anim.current_frame = 
			(game->player.left_anim.current_frame + 1) % game->player.left_anim.frame_count;
	}
	if (keycode == KEY_W || keycode == KEY_UP)
		game->player.y--;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		game->player.y++;
	mlx_clear_window(game->mlx, game->win);
	render_map(game->mlx, game->win, game->map, game->img);
	draw_player(game->mlx, game->win, &game->player, game->img);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, handle_key, game);
}
