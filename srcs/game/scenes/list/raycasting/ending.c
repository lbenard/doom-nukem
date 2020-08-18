/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:49:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 19:19:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

void	ending_trigger(t_raycasting_scene *const self)
{
	t_game	*game;
	t_ray	*zbuffer;
	t_ray	*mid_ray;
	t_wall	*wall;

	game = game_singleton();
	if (input_get(&game->input, self->inputs.use) > 0.0f)
	{
		zbuffer = (t_ray*)self->zbuffer.array;
		mid_ray = &zbuffer[self->window_ref->size.x / 2];
		if (mid_ray->perpendicular_distance < 2.0f)
		{
			wall = &self->map.map[(int)mid_ray->hit.y * self->map.size.x
				+ (int)mid_ray->hit.x];
			if (wall->id == game->blocks_list.ending.id)
			{
				if (list_size(&self->monster_entities.list) != 0)
					self->tooltips.ending_triggered = TRUE;
				else
					window_close(&game->window);
			}
		}
	}
}
