/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 15:16:37 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/18 16:30:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/text.h"
#include "maths/maths.h"

#include <stdio.h>

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
	printf("letter size: x: %lu y: %lu\n", length, settings.height);
	printf("raster size: x: %lu y: %lu\n", self->font.raster.size.x, self->font.raster.size.y);
	line = 0;
	column = 0;
	while (*string_ptr)
	{
		printf("printing: %c\n", *string_ptr);
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
			// printf("line %lu\n", i.y);
			while (i.x < length
				&& settings.position.x + i.x < self->target.size.x)
			{
				// printf("frame x %lu\n", settings.position.x + i.x);
				// printf("frame y %lu\n", i.y * line);
				// size_t	font_pos = (size_t)lerp(0, letter_size.x, inverse_lerp(0, length - 1, i.x)) + (letter_size.x * (*string_ptr - ' '));
				// printf("%f\n", lerp(0, letter_size.y - 1, inverse_lerp(0, settings.height - 1, i.y)));
				t_usize	frame_pos;
				frame_pos.x = settings.position.x + column * length + i.x;
				frame_pos.y = line * settings.height + i.y;
				t_usize	font_pos;
				font_pos.x = (lerp(0, letter_size.x, inverse_lerp(0, length, i.x)) + (letter_size.x * (*string_ptr - ' ')));
				font_pos.y = (lerp(0, letter_size.y, inverse_lerp(0, settings.height, i.y)));
				// printf("pixel %lu x: %lu y: %lu\n", i.x, font_pos.x, font_pos.y);
				// printf(" y: %f\n", lerp(0, letter_size.y - 1, inverse_lerp(0, settings.height - 1, i.y)));
				((t_rgba*)self->target.frame.array)[self->target.size.x * frame_pos.y + frame_pos.x] = ((t_rgba*)self->font.raster.frame.array)[self->font.raster.size.x * font_pos.y + font_pos.x];
					// ((t_rgba*)self->font.raster.frame.array)[self->font.raster.size.x * font_pos.y + font_pos.x];
				// ((t_rgba*)self->target.frame.array)[frame_pos] = ft_rgba()
				i.x++;
			}
			i.y++;
		}
		column++;
		string_ptr++;
	}
}