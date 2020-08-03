/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 01:26:40 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/30 21:43:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/script_scene.h"
#include "game/game.h"
#include "game/scenes/raycasting_scene.h"
#include "engine/delta.h"
#include "ft/str.h"
#include "maths/maths.h"

static void	write(t_script_scene *const self,
				const char *const paragraph,
				char *const writing)
{
	double	time;
	size_t	strokes;
	size_t	last_char_index;
	double	keystroke_time;

	time = get_wall_time();
	last_char_index = ft_ssmax(0, ft_strlen(writing) - 1);
	if (paragraph[last_char_index] == ' ')
		keystroke_time = 0.01;
	else if (paragraph[last_char_index] == '.')
		keystroke_time = 1.0;
	else if (paragraph[last_char_index] == ',')
		keystroke_time = 0.5;
	else if (paragraph[last_char_index] == '\n')
		keystroke_time = 0.2;
	else
		keystroke_time = 0.07;
	keystroke_time /= self->speed + 1.0f;
	strokes = (time - self->last_keystroke) / keystroke_time;
	if (strokes > 0)
		self->last_keystroke = time;
	ft_strncpy(writing, paragraph,
		ft_smin(ft_strlen(paragraph), ft_strlen(writing) + strokes));
}

void	script_scene_update(t_script_scene *const self)
{
	text_set_ref(&self->paragraph1_text,
		static_string_as_ref(ft_static_string(self->writing_paragraph1)));
	text_set_ref(&self->paragraph2_text,
		static_string_as_ref(ft_static_string(self->writing_paragraph2)));
	if (ft_strlen(self->writing_paragraph1) != ft_strlen(self->paragraph1))
		write(self, self->paragraph1, self->writing_paragraph1);
	else
		write(self, self->paragraph2, self->writing_paragraph2);
	if (self->skip)
		game_set_scene(raycasting_scene(self->window, self->path));
	self->speed *= 0.8f;
}