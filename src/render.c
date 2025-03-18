/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:43:23 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/16 05:43:23 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/images.h"
#include "../includes/render.h"
#include "../includes/game.h"

void	render_map(void *mlx, void *win, char **map, t_img img)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img.wall, j * TS, i * TS);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, win, img.floor, j * TS, i * TS);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, img.collectible, j * TS, i * TS);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img.door, j * TS, i * TS);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img.player, j * TS, i * TS);
			else if (map[i][j] == 'X')
				mlx_put_image_to_window(mlx, win, img.enemy[0], j * TS, i * TS);
			j++;
		}
		i++;
	}
}

void draw_player(void *mlx, void *win, t_player *player, t_img img)
{
	int frame;

	if (player->dir == LEFT)
		frame = player->left_anim.current_frame;
	else
		frame = player->right_anim.current_frame;
	mlx_put_image_to_window(mlx, win,
		(player->dir == LEFT ? img.p_left[frame] : img.p_right[frame]),
		player->x * TS, player->y * TS);
}

void draw_enemy(void *mlx, void *win, t_enemy *enemy, t_img img)
{
	int frame;

	if (enemy->attacking)
		frame = enemy->attack_anim.current_frame;
	else
		frame = enemy->idle_anim.current_frame;

	mlx_put_image_to_window(mlx, win,
		(enemy->attacking ? img.enemy_attack[frame] : img.enemy[frame]),
		enemy->x * TS, enemy->y * TS);
}
