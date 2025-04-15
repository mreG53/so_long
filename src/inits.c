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
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

size_t	ft_strlen(char *s);

void	init_game(t_game *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				set_player_position(game, map, i, j);
		}
	}
}

void	init_window(t_game *game)
{
	int	map_w;
	int	map_h;

	map_w = (int)ft_strlen(game->map[0]);
	map_h = get_loaded_map_h(game->map);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: mlx_init didn't initialized.");
		exit (1);
	}
	game->win = mlx_new_window(game->mlx, map_w * TS, map_h * TS, "So Long");
	if (!game->win)
	{
		ft_printf("Error: mlx_new_window didn't initialized.");
		exit (1);
	}
}
