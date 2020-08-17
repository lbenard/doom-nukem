/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 04:36:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/26 20:28:13 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/window.h"
#include "engine/error.h"
#include "ft/str.h"

static void	add_modules(t_window *const self, const t_window_args *const args)
{
	module_add(&self->module, &self->name, string(args->name));
	module_add(&self->module, &self->frame,
		frame(self->size, ft_rgba(0, 0, 0, 255)));
	module_add(&self->module, &self->cursor,
		cursor_from_file("resources/cursors/cursor-upscale.bmp"));
}

static void	init_vars(t_window *const self, const t_window_args *const args)
{
	self->base_name = args->name;
	sfRenderWindow_setMouseCursorVisible(self->window, 0);
	self->is_cleared = FALSE;
}

/*
** SFML by default set the window position at the bottom of the screen, which is
** kinda annoying
*/

static void	center_window(t_window *const self)
{
	sfVideoMode	desktop_mode;
	sfVector2i	desktop_pos;

	desktop_mode = sfVideoMode_getDesktopMode();
	desktop_pos.x = desktop_mode.width / 2 - self->size.x / 2;
	desktop_pos.y = desktop_mode.height / 2 - self->size.y / 2;
	sfRenderWindow_setPosition(self->window, desktop_pos);
}

static void	init_window2(t_window *const self,
					const t_window_args *const args)
{
	sfVideoMode	desktop_mode;

	init_module(&self->module);
	desktop_mode = sfVideoMode_getDesktopMode();
	self->size.x = (args->fullscreen) ? desktop_mode.width : args->size.x;
	self->size.y = (args->fullscreen) ? desktop_mode.height : args->size.y;
	self->is_fullscreen = args->fullscreen;
}

t_result	init_window(t_window *const self, const t_window_args *const args)
{
	sfVideoMode	mode;
	sfUint32	style;

	init_window2(self, args);
	mode.width = self->size.x;
	mode.height = self->size.y;
	mode.bitsPerPixel = 32;
	style = sfClose;
	style |= (args->fullscreen) ? sfFullscreen : 0;
	if (!(self->window = sfRenderWindow_create(mode, args->name, style, NULL)))
	{
		return (throw_result_str("init_window()",
			"error while create sfRenderWindow"));
	}
	add_modules(self, args);
	init_vars(self, args);
	center_window(self);
	if (self->module.has_error)
	{
		destroy_window(self);
		return (throw_result_str("init_window()", "cannot create window"));
	}
	return (OK);
}
