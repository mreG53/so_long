/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <emgumus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:33:02 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/18 16:30:24 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "images.h"
# include "game.h"

void	render_map(void *mlx, void *win, char **map, t_img img);
void	draw_player(void *mlx, void *win, t_player *player, t_img img);
void	draw_enemies(void *mlx, void *win, t_game *game, t_img img);

#endif