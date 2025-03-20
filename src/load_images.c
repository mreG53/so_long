/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 06:13:40 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/19 17:46:45 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/images.h"
#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static void	load_array(void *mlx, void **dst, char *path, int cnt)
{
	int		i;
	int		w;
	int		h;
	char	buf[64];

	i = 0;
	while (i < cnt)
	{
		sprintf(buf, "%s%d.xpm", path, i + 1);
		dst[i] = mlx_xpm_file_to_image(mlx, buf, &w, &h);
		i++;
	}
}

static void	load_main_textures(void *mlx, t_img *img)
{
	int	w;
	int	h;

	img->floor = mlx_xpm_file_to_image(mlx, "textures/floor.xpm", &w, &h);
	img->wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &w, &h);
	img->player = mlx_xpm_file_to_image(mlx, "textures/p_wait1.xpm", &w, &h);
	img->collectible = mlx_xpm_file_to_image(mlx, "textures/key.xpm", &w, &h);
	img->door = mlx_xpm_file_to_image(mlx, "textures/door.xpm", &w, &h);
}

t_img	load_images(void *mlx)
{
	t_img	img;

	load_main_textures(mlx, &img);
	load_array(mlx, img.enemy, "textures/enemy", 4);
	load_array(mlx, img.p_left, "textures/p_left", 4);
	load_array(mlx, img.p_right, "textures/p_right", 4);
	if (!img.floor || !img.wall || !img.player
		|| !img.collectible || !img.door)
	{
		ft_printf("Error: Texture loading failed!\n");
		exit(1);
	}
	return (img);
}
