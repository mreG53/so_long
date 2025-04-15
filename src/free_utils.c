/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 04:00:00 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/04 04:00:00 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

static void	free_images(t_game *game)
{
	int	i;

	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.floor)
		mlx_destroy_image(game->mlx, game->img.floor);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.door)
		mlx_destroy_image(game->mlx, game->img.door);
	if (game->img.enemy)
		mlx_destroy_image(game->mlx, game->img.enemy);
	i = 0;
	while (i < 4)
	{
		if (game->img.p_left[i])
			mlx_destroy_image(game->mlx, game->img.p_left[i]);
		if (game->img.p_right[i])
			mlx_destroy_image(game->mlx, game->img.p_right[i]);
		i++;
	}
}

void	free_all(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
	{
		free_images(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	exit(0);
}
