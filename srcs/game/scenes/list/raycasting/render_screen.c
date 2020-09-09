/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 09:54:40 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/09 10:24:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

void	raycasting_scene_render_screen(t_raycasting_scene *const self)
{
	t_frame	*screen_texture;

	screen_texture = &game_singleton()->blocks_list.wood_screen.texture;
	frame_layer_transform_add(screen_texture,
		&self->last_frame,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(screen_texture->size.x / 2, screen_texture->size.y / 2),
			ft_vec2f(16.0f / self->last_frame.size.x * 6.0f,
				9.0f / self->last_frame.size.y * 6.0f),
			255));
}
