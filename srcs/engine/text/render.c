/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:16:37 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 02:13:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/text.h"
#include "maths/maths.h"

static void	render_character(t_text *const self,
				const t_text_settings settings,
				const t_usize pos,
				const char character)
{
	t_usize	i;
	t_usize	letter_size;
	size_t	length;
	t_usize	frame_pos;
	size_t	pixel_pos;

	letter_size.x = self->font.raster.size.x / 95;
	letter_size.y = self->font.raster.size.y;
	length = settings.height * ((float)letter_size.x / letter_size.y);
	i.y = 0;
	while (i.y < settings.height
		&& settings.position.y + i.y < self->target.size.y)
	{
		i.x = 0;
		while (i.x < length && settings.position.x + i.x < self->target.size.x)
		{
			frame_pos.x = settings.position.x + pos.x * length + i.x;
			frame_pos.y = pos.y * settings.height + i.y;
			pixel_pos = self->font.raster.size.x * (int)lerp(0, letter_size.y,
				inverse_lerp(0, settings.height, i.y))
				+ (int)lerp(0, letter_size.x, inverse_lerp(0, length, i.x))
				+ (letter_size.x * (character - ' '));
			self->pixels[self->target.size.x * frame_pos.y + frame_pos.x] =
				self->font.raster.pixels[pixel_pos];
			i.x++;
		}
		i.y++;
	}
}

void		text_render(t_text *const self, const t_text_settings settings)
{
	char	*string_ptr;
	t_usize	pos;

	string_ptr = self->text.str;
	frame_fill(&self->target, ft_rgba(0, 0, 0, 0));
	pos = ft_usize(0, 0);
	while (*string_ptr)
	{
		if (*string_ptr == '\n')
		{
			pos.y++;
			pos.x = 0;
			string_ptr++;
			continue ;
		}
		render_character(self, settings, pos, *string_ptr);
		pos.x++;
		string_ptr++;
	}
}
