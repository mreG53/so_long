/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 06:13:40 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/16 06:13:40 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/images.h"
#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static void	load_array(void *mlx, void **dest, const char *base, int count, int *w, int *h)
{
	int		i;
	char	buf[64];

	i = 0;
	while (i < count)
	{
		sprintf(buf, "textures/%s%d.xpm", base, i + 1);
		dest[i] = mlx_xpm_file_to_image(mlx, buf, w, h);
		i++;
	}
}

t_img	load_images(void *mlx)
{
	t_img	img;
	int		w;
	int		h;

	img.floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &w, &h);
	img.wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &w, &h);
	img.player = mlx_xpm_file_to_image(mlx, "textures/p_wait1.xpm", &w, &h);
	img.collectible = mlx_xpm_file_to_image(mlx, "textures/key.xpm", &w, &h);
	img.door = mlx_xpm_file_to_image(mlx, "textures/door.xpm", &w, &h);
	load_array(mlx, img.enemy, "enemy", 4, &w, &h);
	load_array(mlx, img.enemy_attack, "enemy_attack", 3, &w, &h);
	load_array(mlx, img.p_left, "p_left", 4, &w, &h);
	load_array(mlx, img.p_right, "p_right", 4, &w, &h);
	if (!img.floor || !img.wall || !img.player || !img.collectible || !img.door)
	{
		ft_printf("Error: Texture loading failed!\n");
		exit(1);
	}
	return (img);
}
