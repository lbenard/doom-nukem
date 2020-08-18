/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_use_tooltip.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:00:32 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 19:37:05 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

void	raycasting_scene_render_use_tooltip(t_raycasting_scene *const self,
			t_frame *const fb)
{
	frame_layer_transform_add(fb,
		&self->tooltips.use_key_text.target,
		ft_frame_transform(ft_vec2f(0.0f, 0.5f),
			ft_isize(fb->size.x / 2 + 20, fb->size.y / 2 + 20),
			ft_vec2f(2.0f, 2.0f),
			255));
	frame_layer_transform_add(fb,
		animation_current(&self->tooltips.use_key_animation,
			&self->assets.use_key_spritesheet),
		ft_frame_transform(ft_vec2f(0.0f, 0.5f),
			ft_isize(fb->size.x / 2
				+ self->tooltips.use_key_text.target.size.x * 2 + 25,
				fb->size.y / 2 + 20),
			ft_vec2f(2.0f, 2.0f),
			255));
}
