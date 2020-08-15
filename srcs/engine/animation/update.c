/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:54:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 02:36:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/delta.h"
#include "engine/animation.h"

void	animation_update(t_animation *const anim,
			const t_spritesheet *const ss)
{
	anim->iter = (int)anim->delta_iter;
	if ((size_t)(anim->iter * anim->speed) >= ss->grid_size.x)
		anim->iter = 0;
}
