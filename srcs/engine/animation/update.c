/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 18:54:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/12 18:54:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/animation.h"

void	animation_update(t_animation *const anim,
			const t_spritesheet *const ss)
{
	anim->iter++;
	if ((size_t)(anim->iter * anim->speed) >= ss->grid_size.x)
		anim->iter = 0;
}