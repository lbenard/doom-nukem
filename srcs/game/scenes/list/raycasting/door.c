/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 20:21:32 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/18 19:28:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

static void	remove_door(t_raycasting_scene *const self, char id)
{
	t_usize	i;

	i.y = 0;
	while (i.y < self->map.size.y)
	{
		i.x = 0;
		while (i.x < self->map.size.x)
		{
			if (self->map.map[self->map.size.x * i.y + i.x].id == id)
			{
				self->map.map[self->map.size.x * i.y + i.x].id = ' ';
				self->map.map[self->map.size.x * i.y + i.x].texture_ref = NULL;
				zbuffer(self, self->entities.player_ref->dir,
					self->entities.player_ref->plane);
			}
			i.x++;
		}
		i.y++;
	}
}

void		door_trigger(t_raycasting_scene *const self)
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
			if (wall->id == game->blocks_list.metallic_red_button.id)
				remove_door(self, game->blocks_list.metallic_red_door.id);
			if (wall->id == game->blocks_list.metallic_green_button.id)
				remove_door(self, game->blocks_list.metallic_green_door.id);
			if (wall->id == game->blocks_list.metallic_blue_button.id)
				remove_door(self, game->blocks_list.metallic_blue_door.id);
		}
	}
}
