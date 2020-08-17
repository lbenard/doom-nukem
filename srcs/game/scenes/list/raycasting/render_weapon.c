/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:24:54 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/17 19:32:40 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/io.h"
#include "ft/str.h"

void	raycasting_scene_render_weapon(t_raycasting_scene *const self,
			t_frame *const fb)
{
	if (self->entities.weapon_ref)
		frame_layer_add(fb, &self->entities.weapon_ref->hud, ft_isize(0, 0));
}
