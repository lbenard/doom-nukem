/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 00:49:14 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/20 20:34:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/scenes/script_scene.h"
#include "engine/error.h"
#include "engine/delta.h"
#include "ft/str.h"

static void			paragraphs_helper(t_script_scene *const self)
{
	self->paragraph1 =
		"          During a long and furious battle against this\n"
		"  segfault you've been having for the last couple of hours, your\n"
		"doorbell rang. Once the door was opened, the only thing you saw was\n"
		"   an enormous shadow standing in front of you. And then, nothing.\n"
		"         This was the last thing you saw before passing out.\n";
	self->paragraph2 =
		"After being unconscious for what seemed like an eternity, you hear\n"
		"an helicopter, slowly going away whilst you're beginning to regain\n"
		"             your thoughts. They left you a note.\n";
}

static t_result		paragraphs(t_script_scene *const self)
{
	paragraphs_helper(self);
	self->writing_paragraph1 = ft_strnew(ft_strlen(self->paragraph1));
	self->writing_paragraph2 = ft_strnew(ft_strlen(self->paragraph1));
	if (!self->writing_paragraph1 || !self->writing_paragraph2)
	{
		free(self->writing_paragraph1);
		free(self->writing_paragraph2);
		return (throw_result_str("init_script_scene()",
			"failed to create paragraphs"));
	}
	module_add(&self->super.module, &self->paragraph1_text,
		text("resources/fonts/haxorville.bmp", ft_usize(5 * 67, 9 * 5)));
	module_add(&self->super.module, &self->paragraph2_text,
		text("resources/fonts/haxorville.bmp", ft_usize(5 * 66, 9 * 3)));
	module_add(&self->super.module, &self->skip_text,
		text("resources/fonts/haxorville.bmp", ft_usize(5 * 21, 9 * 1)));
	return (self->super.module.has_error ? ERROR : OK);
}

static t_result		init_script_scene2(t_script_scene *const self)
{
	module_add(&self->super.module, &self->tig,
		frame_from_file("resources/textures/tig.bmp"));
	event_handler_add_callback(&self->super.input_manager, new_skip_event());
	if (self->super.module.has_error)
	{
		destroy_script_scene(self);
		return (throw_result_str("init_script_scene()",
			"failed to create new script scene"));
	}
	text_set_ref(&self->paragraph1_text,
		static_string_as_ref(ft_static_string(self->writing_paragraph1)));
	text_set_ref(&self->paragraph2_text,
		static_string_as_ref(ft_static_string(self->writing_paragraph2)));
	text_set_ref(&self->skip_text,
		static_string_as_ref(ft_static_string("Press any key to skip")));
	text_render(&self->skip_text, ft_text_settings(ft_isize(0, 0), 9));
	frame_fill_blend(&self->skip_text.target, ft_rgba(255, 255, 255, 255),
		blend_colorize);
	frame_fill_blend(&self->tig, ft_rgba(255, 255, 255, 255), blend_invert);
	cursor_set_visibility(&self->window->cursor, FALSE);
	return (OK);
}

t_result			init_script_scene(t_script_scene *const self,
					t_script_scene_args *const args)
{
	if (init_scene(&self->super,
		"Script",
		script_scene_update,
		script_scene_render) == ERROR)
	{
		destroy_scene(&self->super);
		return (throw_result_str("init_script_scene()",
			"failed to create scene"));
	}
	self->window = args->window;
	self->path = args->path;
	self->text_finished_time = 0.0;
	self->skip = FALSE;
	self->last_keystroke = get_wall_time();
	self->keystroke_time = 0.1;
	self->speed = 0.0f;
	if (paragraphs(self) == ERROR)
	{
		destroy_script_scene(self);
		return (throw_result_str("init_script_scene()",
			"failed to create paragraphs"));
	}
	return (init_script_scene2(self));
}
