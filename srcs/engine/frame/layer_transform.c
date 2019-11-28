/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 16:59:57 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/28 17:39:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"
#include "maths/maths.h"

static t_bool				is_visible(const t_frame *const bg,
								const t_frame_coordinates coordinates)
{
	t_isize	start;
	t_usize	size;

	start.x = ft_ssmin(coordinates.start.x, coordinates.end.x);
	start.y = ft_ssmin(coordinates.start.y, coordinates.end.y);
	size.x = ft_ssmax(coordinates.start.x, coordinates.end.x) - start.x;
	size.y = ft_ssmax(coordinates.start.y, coordinates.end.y) - start.y;
	return (!(start.x >= (ssize_t)bg->size.x || start.y >= (ssize_t)bg->size.y
		|| (start.x + size.x <= 0 && start.y + size.y <= 0)));
}

static t_frame_coordinates	crop(const t_frame_coordinates layer,
								const t_usize view)
{
	t_frame_coordinates	ret;

	ret.start.x = ft_ssmin(ft_ssmax(layer.start.x, 0), view.x);
	ret.start.y = ft_ssmin(ft_ssmax(layer.start.y, 0), view.y);
	ret.end.x = ft_ssmin(ft_ssmax(layer.end.x, 0), view.x);
	ret.end.y = ft_ssmin(ft_ssmax(layer.end.y, 0), view.y);
	return (ret);
}

static t_frame_coordinates	normalize(const t_frame_coordinates coordinates)
{
	t_frame_coordinates	normalized;

	normalized.start.x = ft_ssmin(coordinates.start.x, coordinates.end.x);
	normalized.start.y = ft_ssmin(coordinates.start.y, coordinates.end.y);
	normalized.end.x = ft_ssmax(coordinates.start.x, coordinates.end.x);
	normalized.end.y = ft_ssmax(coordinates.start.y, coordinates.end.y);
	return (normalized);
}

static size_t				position(const t_frame *const fg,
								const t_isize i,
								const t_frame_coordinates coordinates)
{
	t_usize	pos;

	pos.x = (size_t)((((float)i.x - coordinates.start.x)
		/ (coordinates.end.x - coordinates.start.x
			- (coordinates.end.x < coordinates.start.x))) * fg->size.x);
	pos.y = (size_t)((((float)i.y - coordinates.start.y)
		/ (coordinates.end.y - coordinates.start.y
			- (coordinates.end.y < coordinates.start.y))) * fg->size.y);
	return (fg->size.x * pos.y + pos.x);
}

void						frame_layer_transform(t_frame *const self,
								const t_frame *const layer,
								const t_frame_transform transform,
								t_u32 (*const blend)(const t_rgba *const back,
									const t_rgba *const front))
{
	t_frame_coordinates	layer_coordinates;
	t_frame_coordinates	normalized;
	t_rgba				fg_pixel;
	t_isize				i;

	layer_coordinates = coordinates(layer, transform);
	if (transform.opacity == 0 || !is_visible(self, layer_coordinates))
		return ;
	normalized = normalize(crop(layer_coordinates, self->size));
	i.y = normalized.start.y;
	while (i.y < normalized.end.y)
	{
		i.x = normalized.start.x;
		while (i.x < normalized.end.x)
		{
			fg_pixel = ((t_rgba*)layer->frame.array)
				[position(layer, i, layer_coordinates)];
			fg_pixel.c.a *= (float)transform.opacity / 255.0f;
			((t_rgba*)self->frame.array)[self->size.x * i.y + i.x].integer =
				blend((t_rgba*)self->frame.array + (self->size.x * i.y + i.x),
					&fg_pixel);
			i.x++;
		}
		i.y++;
	}
}