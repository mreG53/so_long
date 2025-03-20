/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:25:46 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/19 17:25:46 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/ft_printf.h"
#include "../includes/get_next_line.h"
#include "../includes/game_utils.h"
#include "../minilibx/mlx.h"

void	init_enemies(t_game *game, char **map)
{
	int	i;
	int	j;
	int	idx;

	idx = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'X')
			{
				set_single_enemy(&game->enemies[idx++], j, i);
				map[i][j] = '0';
			}
		}
	}
}

void	init_game(t_game *game, char **map)
{
	int	i;
	int	j;

	game->enemy_count = get_enemy_count(map);
	game->enemies = malloc(sizeof(t_enemy) * game->enemy_count);
	if (!game->enemies)
	{
		ft_printf("Memory allocation error\n");
		exit(1);
	}
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'P')
				set_player_position(game, map, i, j);
	}
	init_enemies(game, map);
}

void	init_window(t_game *game)
{
	int	map_w;
	int	map_h;

	map_w = (int)ft_strlen(game->map[0]);
	map_h = get_loaded_map_h(game->map);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map_w * TS, map_h * TS, "So Long");
}
