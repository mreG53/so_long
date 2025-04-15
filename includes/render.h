/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:33:02 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/14 02:48:33 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "images.h"
# include "game.h"

void	render_map(void *mlx, void *win, char **map, t_img img);
void	draw_player(void *mlx, void *win, t_player *player, t_img img);

#endif