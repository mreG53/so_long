/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 06:13:40 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/14 21:34:19 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../includes/images.h"
#include "../includes/ft_printf.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);
size_t	ft_strlen(char *s);

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

static void	load_array(void *mlx, void **dst, char *path, int cnt)
{
	int		i;
	char	*index_str;
	char	*tmp;
	char	*full_path;
	int		wh[2];

	if (!mlx || !dst || !path || cnt <= 0)
		return ;
	i = -1;
	while (++i < cnt)
	{
		index_str = ft_itoa(i + 1);
		tmp = ft_strjoin(ft_strdup(path), index_str);
		if (!tmp)
			return ;
		free(index_str);
		full_path = ft_strjoin(tmp, ".xpm");
		dst[i] = mlx_xpm_file_to_image(mlx, full_path, &wh[0], &wh[1]);
		if (!dst[i])
		{
			ft_printf("Error: FTL anim frame %d from %s\n", i + 1, path);
			exit (1);
		}
		free(full_path);
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
	img.enemy = mlx_xpm_file_to_image(mlx, "textures/enemy1.xpm", &w, &h);
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
