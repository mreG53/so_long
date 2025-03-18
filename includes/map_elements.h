/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elemnts.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 05:56:54 by emgumus           #+#    #+#             */
/*   Updated: 2025/03/15 05:56:54 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ELEMENTS_H
# define MAP_ELEMENTS_H

typedef struct s_elements
{
	int	player;
	int	exit;
	int	collectible;
	int enemy;
	int	valid;
}				t_elements;

void	count_elements(char c, t_elements *elements);
int		req_elements(char **map);

#endif
