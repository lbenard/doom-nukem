/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 01:36:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/30 21:28:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/script_scene.h"
#include "engine/delta.h"
#include "maths/maths.h"
#include "ft/str.h"

static void	script_scene_render3(t_script_scene *const self,
				t_frame *const fb, t_bool is_over, float tig_fade)
{
	if (is_over)
	{
		if (self->text_finished_time == 0.0)
			self->text_finished_time = get_wall_time();
		frame_layer_transform_add(fb,
			&self->tig,
			ft_frame_transform(ft_vec2f(0.5f, 0.5f),
				ft_isize(fb->size.x / 2, fb->size.y / 2 + 350 - tig_fade * 250),
				ft_vec2f(1.0f, 1.0f),
				tig_fade * 255));
	}
	frame_layer_transform_add(fb,
		&self->skip_text.target,
		ft_frame_transform(ft_vec2f(1.0f, 1.0f),
			ft_isize(fb->size.x - 10, fb->size.y - 10),
			ft_vec2f(2.0f, 2.0f),
			127));
}

static void	script_scene_render2(t_script_scene *const self,
				t_frame *const fb, float tig_fade)
{
	frame_fill_blend(&self->paragraph2_text.target,
		ft_rgba(255, 255, 255, 255),
		blend_colorize);
	frame_layer_transform_add(fb,
		&self->paragraph1_text.target,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(fb->size.x / 2, fb->size.y / 2 - 50 - tig_fade * 250),
			ft_vec2f(2.0f, 2.0f),
			255));
	frame_layer_transform_add(fb,
		&self->paragraph2_text.target,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
			ft_isize(fb->size.x / 2, fb->size.y / 2 + 50 - tig_fade * 250),
			ft_vec2f(2.0f, 2.0f),
			255));
}

void		script_scene_render(t_script_scene *const self,
				t_frame *const fb)
{
	t_bool	is_over;
	float	tig_fade;

	is_over = ft_strlen(self->writing_paragraph2) ==
		ft_strlen(self->paragraph2);
	if (!is_over)
		tig_fade = 0.0f;
	else
		tig_fade = ft_fmin((get_wall_time() - self->text_finished_time) / 8.0f,
		1.0f);
	if (!is_over)
		frame_fill_blend(fb, ft_rgba(0, 0, 0, 1), blend_add);
	else
		frame_fill_blend(fb, ft_rgba(0, 0, 0, 255), blend_add);
	text_render(&self->paragraph1_text, ft_text_settings(ft_isize(0, 0), 9));
	text_render(&self->paragraph2_text, ft_text_settings(ft_isize(0, 0), 9));
	frame_fill_blend(&self->paragraph1_text.target,
		ft_rgba(255, 255, 255, 255),
		blend_colorize);
	script_scene_render2(self, fb, tig_fade);
	script_scene_render3(self, fb, is_over, tig_fade);
}
