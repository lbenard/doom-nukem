/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:54:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/15 03:14:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/delta.h"
#include "engine/animation.h"

void	animation_update(t_animation *const anim,
			const t_spritesheet *const ss)
{
	anim->delta_iter += get_last_delta() * 30.0f;
	anim->iter = (int)anim->delta_iter;
	if ((size_t)(anim->iter * anim->speed) >= ss->grid_size.x)
	{
		anim->iter = 0;
		anim->delta_iter = 0.0f;
	}
}