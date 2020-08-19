/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_health.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 03:41:06 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 03:52:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/monster_entity.h"

static t_frame_coordinates	health_bar_coordinates(
								const t_monster_entity *const self)
{
	t_frame_coordinates	coordinates;

	coordinates.start.x = self->super.start_x;
	coordinates.end.x = self->super.end_x;
	coordinates.start.y = self->super.start_y;
	coordinates.end.y = self->super.start_y
		+ (self->super.end_x - self->super.start_x) / 20;
	return (coordinates);
}

void						monster_entity_render_health(
								const t_monster_entity *const self,
								t_frame *const fb,
								const float distance_opacity)
{
	t_frame_coordinates	coordinates;
	t_usize				i;
	t_rgba				*bg;

	coordinates = health_bar_coordinates(self);
	i.y = (size_t)ft_ssmax(coordinates.start.y, 0);
	while ((ssize_t)i.y < coordinates.end.y && i.y < fb->size.y)
	{
		i.x = (size_t)ft_ssmax(coordinates.start.x, 0);
		while ((ssize_t)i.x < coordinates.end.x && i.x < fb->size.x)
		{
			bg = &fb->pixels[i.y * fb->size.x + i.x];
			if ((float)(i.x - coordinates.start.x + i.y - coordinates.start.y)
				/ (float)(coordinates.end.x - coordinates.start.x)
				> self->health / self->full_health)
				*bg = blend_add(*bg, ft_rgba(0, 31, 0, distance_opacity));
			else
				*bg = blend_add(*bg, ft_rgba(0, 255, 0, distance_opacity));
			i.x++;
		}
		i.y++;
	}
}
