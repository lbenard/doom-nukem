/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:55:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/12 18:55:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/animation.h"

t_frame	*animation_current(t_animation *const self,
			const t_spritesheet *const ss)
{
	int	line;

	line = ss->grid_size.x * self->anim;
	return (&ss->sprite[(int)(line + self->iter * self->speed)]);
}
