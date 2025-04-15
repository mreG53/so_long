/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgumus <<emgumus@student.42kocaeli.com.tr +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 05:33:11 by emgumus           #+#    #+#             */
/*   Updated: 2025/04/14 03:14:52 by emgumus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIM_H
# define ANIM_H

typedef struct s_anim
{
	void	**frames;
	int		frame_count;
	int		current_frame;
}				t_anim;

void	update_anim(t_anim	*anim);

#endif