/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 04:36:35 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 17:44:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL_mixer.h>
#include "engine/window.h"
#include "engine/error.h"
#include "ft/str.h"

static void	add_modules(t_window *const self, const t_window_args *const args)
{
	module_add(&self->module, &self->name, string(args->name));
	module_add(&self->module, &self->frame,
		frame(self->size, ft_rgba(0, 0, 0, 255)));
	module_add(&self->module, &self->cursor,
		cursor_from_file("resources/cursors/cursor.bmp"));
}

static void	init_vars(t_window *const self, const t_window_args *const args)
{
	self->base_name = args->name;
	SDL_ShowCursor(SDL_DISABLE);
	SDL_CaptureMouse(SDL_TRUE);
	self->is_cleared = FALSE;
	self->is_opened = TRUE;
}

t_result	init_window(t_window *const self, const t_window_args *const args)
{
	init_module(&self->module);
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
		return (throw_result_str("init_window()", "failed to init SDL Mixer"));
	if (!(self->window = SDL_CreateWindow(args->name,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		args->size.x,
		args->size.y,
		(args->fullscreen) ? SDL_WINDOW_FULLSCREEN : 0)))
	{
		return (throw_result_str("init_window()", "cannot create window"));
	}
	if (!(self->surface = SDL_GetWindowSurface(self->window)))
	{
		destroy_window(self);
		return (throw_result_str("init_window()", "cannot get window surface"));
	}
	self->size = args->size;
	add_modules(self, args);
	init_vars(self, args);
	if (self->module.has_error)
	{
		destroy_window(self);
		return (throw_result_str("init_window()", "cannot create window"));
	}
	return (OK);
}
