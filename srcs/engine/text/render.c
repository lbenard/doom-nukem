/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:16:37 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/25 15:09:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/text.h"
#include "maths/maths.h"

void	text_render(t_text *const self, const t_text_settings settings)
{
	char	*string_ptr;
	t_usize	letter_size;
	size_t	length;
	size_t	column;
	size_t	line;
	t_usize	i;

	string_ptr = self->text.str;
	frame_fill(&self->target, ft_rgba(0, 0, 0, 0));
	letter_size = ft_usize(self->font.raster.size.x / 95,
		self->font.raster.size.y);
	length = settings.height * ((float)letter_size.x / letter_size.y);
	line = 0;
	column = 0;
	while (*string_ptr)
	{
		i.y = 0;
		if (*string_ptr == '\n')
		{
			line++;
			string_ptr++;
			column = 0;
			continue ;
		}
		while (i.y < settings.height
			&& settings.position.y + i.y < self->target.size.y)
		{
			i.x = 0;
			while (i.x < length
				&& settings.position.x + i.x < self->target.size.x)
			{
				t_usize	frame_pos;
				frame_pos.x = settings.position.x + column * length + i.x;
				frame_pos.y = line * settings.height + i.y;
				t_usize	font_pos;
				font_pos.x = (lerp(0, letter_size.x, inverse_lerp(0, length, i.x)) + (letter_size.x * (*string_ptr - ' ')));
				font_pos.y = (lerp(0, letter_size.y, inverse_lerp(0, settings.height, i.y)));
				((t_rgba*)self->target.frame.array)[self->target.size.x * frame_pos.y + frame_pos.x] = ((t_rgba*)self->font.raster.frame.array)[self->font.raster.size.x * font_pos.y + font_pos.x];
				i.x++;
			}
			i.y++;
		}
		column++;
		string_ptr++;
	}
}