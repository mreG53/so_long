/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:27:05 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/08 03:59:35 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/ft_printf.h"
#include "../includes/move.h"
#include "../includes/render.h"
#include "../minilibx/mlx.h"
#include <stdlib.h>

char	*ft_itoa(int n);
void	free_all(t_game *game);
size_t	ft_strlen(char *s);

int	update_direction(t_game *g, int key, int *nx, int *ny)
{
	if (key == KEY_D || key == KEY_RIGHT)
	{
		*nx = g->player.x + 1;
		g->player.dir = RIGHT;
		g->player.right_anim.current_frame++;
		g->player.right_anim.current_frame %= g->player.right_anim.frame_count;
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		*nx = g->player.x - 1;
		g->player.dir = LEFT;
		g->player.left_anim.current_frame++;
		g->player.left_anim.current_frame %= g->player.left_anim.frame_count;
	}
	else if (key == KEY_W || key == KEY_UP)
		*ny = g->player.y - 1;
	else if (key == KEY_S || key == KEY_DOWN)
		*ny = g->player.y + 1;
	return (1);
}

int	check_tile(t_game *g, int *nx, int *ny)
{
	if (g->map[*ny][*nx] == 'E' && rem_col(g->map) == 0)
	{
		ft_printf("You Win! Moves: %d\n", g->move_count);
		free_all(g);
	}
	else if (!is_can_walk(g->map, *nx, *ny))
	{
		*nx = g->player.x;
		*ny = g->player.y;
	}
	return (1);
}

int	update_move(t_game *g, int nx, int ny)
{
	if (nx != g->player.x || ny != g->player.y)
		g->move_count++;
	g->player.x = nx;
	g->player.y = ny;
	if (g->map[ny][nx] == 'C')
		g->map[ny][nx] = '0';
	return (1);
}

int	check_enemy_collision(t_game *g)
{
	int	k;

	k = 0;
	while (k < g->enemy_count)
	{
		if (g->player.x == g->enemies[k].x
			&& g->player.y == g->enemies[k].y)
		{
			ft_printf("Game Over! Moves: %d\n", g->move_count);
			free_all(g);
		}
		k++;
	}
	return (1);
}

int	refresh_game(t_game *g)
{
	int		mw;
	int		mh;
	char	*ms;

	mw = ft_strlen(g->map[0]);
	mh = get_loaded_map_h(g->map);
	mlx_clear_window(g->mlx, g->win);
	render_map(g->mlx, g->win, g->map, g->img);
	draw_player(g->mlx, g->win, &g->player, g->img);
	draw_enemies(g->mlx, g->win, g, g->img);
	ms = ft_itoa(g->move_count);
	if (!ms)
		return (1);
	mlx_string_put(g->mlx, g->win, (mw * TS) - 100,
		(mh * TS) - 20, 0xFFFFFF, ms);
	free(ms);
	return (1);
}
