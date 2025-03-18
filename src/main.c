/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 04:27:51 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/15 04:27:51 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/ft_printf.h"
#include "../minilibx-linux/mlx.h"
#include "../includes/get_next_line.h"
#include "../includes/game.h"
#include "../includes/render.h"

char	**read_map_file(char *filename);
int		validate_map(char **map);
t_img	load_images(void *mlx);
void	setup_hooks(t_game *game);

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		map_width;
	int		map_height;

	if (argc != 2)
		return (ft_printf("Usage: %s <map_file.ber>\n", argv[0]));
	game.map = read_map_file(argv[1]);
	if (!game.map || !validate_map(game.map))
		return (ft_printf("Invalid map. Please fix your map file.\n"));
	map_width = (int)ft_strlen(game.map[0]);
	map_height = get_map_height(game.map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map_width
		* TS, map_height * TS, "So Long");
	game.img = load_images(game.mlx);
	game.player.x = 1;
	game.player.y = 1;
	game.player.dir = RIGHT;
	render_map(game.mlx, game.win, game.map, game.img);
	draw_player(game.mlx, game.win, &game.player, game.img);
	setup_hooks(&game);
	return (0);
}
