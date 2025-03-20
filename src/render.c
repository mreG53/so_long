/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:43:23 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/20 23:04:21 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/images.h"
#include "../includes/render.h"
#include "../includes/game.h"
#include "../includes/game_utils.h"

#include "../minilibx/mlx.h"
#include "../includes/images.h"
#include "../includes/render.h"
#include "../includes/game.h"
#include "../includes/game_utils.h"

static void	render_tile(void *mlx, void *win, t_img img, t_pos pos)
{
	if (pos.type == '1')
		mlx_put_image_to_window(mlx, win, img.wall, pos.x, pos.y);
	else if (pos.type == '0')
		mlx_put_image_to_window(mlx, win, img.floor, pos.x, pos.y);
	else if (pos.type == 'C')
		mlx_put_image_to_window(mlx, win, img.collectible, pos.x, pos.y);
	else if (pos.type == 'P')
		mlx_put_image_to_window(mlx, win, img.player, pos.x, pos.y);
}

static void	render_exit(void *mlx, void *win, t_img img, t_pos pos)
{
	if (pos.type == 'E' && rem_col(pos.map) > 0)
		mlx_put_image_to_window(mlx, win, img.wall, pos.x, pos.y);
	else
		mlx_put_image_to_window(mlx, win, img.door, pos.x, pos.y);
}

void	render_map(void *mlx, void *win, char **map, t_img img)
{
	int		i;
	int		j;
	t_pos	pos;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			pos.x = j * TS;
			pos.y = i * TS;
			pos.type = map[i][j];
			pos.map = map;
			if (map[i][j] == 'E')
				render_exit(mlx, win, img, pos);
			else
				render_tile(mlx, win, img, pos);
		}
	}
}

void	draw_player(void *mlx, void *win, t_player *player, t_img img)
{
	int	frame;

	frame = player->right_anim.current_frame;
	if (player->dir == LEFT)
	{
		frame = player->left_anim.current_frame;
		mlx_put_image_to_window(mlx, win, img.p_left[frame],
			player->x * TS, player->y * TS);
	}
	else
	{
		mlx_put_image_to_window(mlx, win, img.p_right[frame],
			player->x * TS, player->y * TS);
	}
}

void	draw_enemies(void *mlx, void *win, t_game *game, t_img img)
{
	int		i;
	t_pos	pos;

	i = -1;
	while (++i < game->enemy_count)
	{
		pos.x = game->enemies[i].x * TS;
		pos.y = game->enemies[i].y * TS;
		mlx_put_image_to_window(mlx, win, img.enemy[0], pos.x, pos.y);
	}
}
