/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:29:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/11 20:54:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

#ifdef __SSE__f

# include <emmintrin.h>

static void	__memset(void *ptr, int c, size_t len)
{
	size_t			i;
	register char	*p = (char *) ptr;

	for (i = 0; i < len; i++) {
		p[i] = c;
	}
}

void		frame_fill(t_frame *const self, const t_rgba fill_color)
{
	void			*ptr = self->pixels;
	size_t			len = sizeof(t_rgba) * self->size.x * self->size.y;
	register size_t	i;
	size_t			loff = ((intptr_t) ptr) % 16;
	size_t			l16 = (len - loff) / 16;
	size_t			lrem = len - l16 * 16 - loff;
	register char	*p = (char *) ptr;
	t_u32			c = (t_u32) fill_color.integer;
	__m128i c16 = _mm_set_epi32(c, c, c, c);
	
	__memset(p, c, loff);
	p += loff;
	for (i = 0; i < l16; ++i) {
		_mm_store_si128((__m128i*)p, c16);
		p += 16;
	}
	__memset(p, c, lrem);
}

#else

void		frame_fill(t_frame *const self, const t_rgba fill_color)
{
	size_t	i;
	size_t	total_size;

	i = 0;
	total_size = self->size.x * self->size.y;
	while (i < total_size)
	{
		((t_rgba*)self->frame.array)[i] = fill_color;
		i++;
	}
}

#endif
