/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:27:05 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/14 21:30:51 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/ft_printf.h"
#include "../includes/move.h"
#include "../includes/render.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

#define W 0xFFFFFF

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
	if (!g || !g->map || !nx || !ny)
		return (0);
	if (g->map[*ny][*nx] == 'E' && rem_col(g->map) == 0)
	{
		ft_printf("\nYou Win! Moves: %d\n", g->move_count);
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
	if (g->map[g->player.y][g->player.x] == 'X')
	{
		ft_printf("\nGame Over! Moves: %d\n", g->move_count);
		free_all(g);
	}
	return (1);
}

int	refresh_game(t_game *g)
{
	int			mw;
	int			mh;
	char		*ms;

	mw = ft_strlen(g->map[0]);
	mh = get_loaded_map_h(g->map);
	mlx_clear_window(g->mlx, g->win);
	render_map(g->mlx, g->win, g->map, g->img);
	draw_player(g->mlx, g->win, &g->player, g->img);
	ms = ft_itoa(g->move_count);
	if (!ms)
	{
		ft_printf("Error: Failed to convert move count.\n");
		return (1);
	}
	mlx_string_put(g->mlx, g->win, (mw * TS) - 20, (mh * TS) - 20, W, ms);
	ft_printf("\rNow Moves: %d", g->move_count);
	free(ms);
	return (1);
}
