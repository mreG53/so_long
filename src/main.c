/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:27:51 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/19 18:18:22 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_printf.h"
#include "../includes/game.h"
#include "../includes/render.h"
#include "../minilibx/mlx.h"

char	**read_map_file(char *filename);
int		validate_map(char **map);
t_img	load_images(void *mlx);
void	setup_hooks(t_game *game);
void	init_game(t_game *game, char **map);
void	init_window(t_game *game);

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Usage: %s <map_file.ber>\n", argv[0]));
	game.map = read_map_file(argv[1]);
	if (!game.map || !validate_map(game.map))
		return (ft_printf("Invalid map. Fix map file.\n"));
	init_game(&game, game.map);
	init_window(&game);
	game.img = load_images(game.mlx);
	render_map(game.mlx, game.win, game.map, game.img);
	draw_player(game.mlx, game.win, &game.player, game.img);
	draw_enemies(game.mlx, game.win, &game, game.img);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
