/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:55:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 20:14:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/animation.h"
#include "maths/maths.h"

t_frame	*animation_current(t_animation *const self,
			const t_spritesheet *const ss)
{
	int	line;

	line = ss->grid_size.x * self->anim;
	return (&ss->sprite[(int)(line
		+ ft_min(self->iter * self->speed, ss->grid_size.x - 1))]);
}
