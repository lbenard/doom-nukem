/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:06:38 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/07 22:40:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/minimap_entity.h"
#include "maths/vec2i.h"

// void		minimap_entity_render(t_minimap_entity *const self,
// 				t_frame *const frame)
// {
// 	t_vec2f	pos;
// 	t_usize	frame_player_pos;
// 	size_t	i;
// 	t_usize	frame_ray_pos;

// 	pos = self->raycasting_ref->position;
// 	frame_player_pos = ft_usize(pos.x / self->raycasting_ref->map->size.x
// 		* self->minimap.size.x, pos.y / self->raycasting_ref->map->size.y
// 		* self->minimap.size.y);
// 	i = 0;
// 	while (i < self->raycasting_ref->columns_number)
// 	{
// 		frame_ray_pos = ft_usize(self->raycasting_ref->columns[i].hit_position.x
// 			/ self->raycasting_ref->map->size.x * self->minimap.size.x,
// 			self->raycasting_ref->columns[i].hit_position.y
// 			/ self->raycasting_ref->map->size.y * self->minimap.size.y);
// 		self->minimap.frame[frame_ray_pos.y * self->minimap.size.x
// 			+ frame_ray_pos.x] = ft_rgba(255, 0, 0, 255).integer;
// 		i++;
// 	}
// 	frame_layer(frame, &self->minimap, ft_isize(0, 0), blend_add);
// 	frame->frame[frame_player_pos.y * frame->size.x + frame_player_pos.x] =
// 		ft_rgba(255, 255, 255, 255).integer;
// }
