/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon_tooltip.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:01:29 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 20:39:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "game/scenes/raycasting_scene.h"

void	raycasting_scene_render_weapon_tooltip(t_raycasting_scene *const self,
				t_frame *const fb)
{
	frame_layer_transform_add(fb,
		&self->tooltips.pick_key_text.target,
		ft_frame_transform(ft_vec2f(0.0f, 0.5f),
			ft_isize(fb->size.x / 2 + 20,
				fb->size.y / 2 + 20 + 40 * self->tooltips.use_triggered),
			ft_vec2f(2.0f, 2.0f),
			255));
	frame_layer_transform_add(fb,
		animation_current(&self->tooltips.pick_key_animation,
			&self->assets.pick_key_spritesheet),
		ft_frame_transform(ft_vec2f(0.0f, 0.5f),
			ft_isize(fb->size.x / 2
				+ ft_strlen(self->tooltips.pick_key_display) * 5 * 2 + 25,
				fb->size.y / 2 + 20 + 40 * self->tooltips.use_triggered),
			ft_vec2f(2.0f, 2.0f),
			255));
}
