/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tooltips.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:59:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 21:00:57 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "game/scenes/raycasting_scene.h"

void	init_raycasting_scene_tooltips(t_raycasting_scene *const self)
{
	module_add(&self->super.module, &self->tooltips.use_key_animation,
		animation(0, 2, 0.1f));
	module_add(&self->super.module, &self->tooltips.use_key_text,
		text("haxorville.bmp", ft_usize(5 * ft_strlen("Press"), 9)));
	if (self->super.module.has_error == FALSE)
	{
		text_set_ref(&self->tooltips.use_key_text,
			static_string_as_ref(ft_static_string("Press")));
		text_render(&self->tooltips.use_key_text,
			ft_text_settings(ft_isize(0, 0), 9));
		frame_fill_blend(&self->tooltips.use_key_text.target,
			ft_rgba(255, 255, 255, 255), blend_colorize);
	}
	module_add(&self->super.module, &self->tooltips.pick_key_animation,
		animation(0, 2, 0.1f));
	module_add(&self->super.module, &self->tooltips.pick_key_text,
		text("haxorville.bmp", ft_usize(5 * 20, 9)));
}
