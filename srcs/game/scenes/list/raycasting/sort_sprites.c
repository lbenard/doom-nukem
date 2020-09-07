/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 10:54:54 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/07 10:56:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

static void	sort_sprites(t_raycasting_scene *const self)
{
	t_list_head		*pos;
	t_sprite_entity	*sprite;
	t_sprite_entity	*next_sprite;

	pos = &self->sprite_entities.list;
	while ((pos = pos->next) != &self->sprite_entities.list)
	{
		if (pos->next == &self->sprite_entities.list)
			break ;
		sprite = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		next_sprite = (t_sprite_entity*)((t_entity_node*)pos->next)->entity;
		if (sprite->perpendicular_distance
			< next_sprite->perpendicular_distance)
		{
			list_swap_next(pos);
			pos = &self->sprite_entities.list;
			continue ;
		}
	}
}

static void	sort_monsters(t_raycasting_scene *const self)
{
	t_list_head		*pos;
	t_sprite_entity	*sprite;
	t_sprite_entity	*next_sprite;

	pos = &self->monster_entities.list;
	while ((pos = pos->next) != &self->monster_entities.list)
	{
		if (pos->next == &self->monster_entities.list)
			break ;
		sprite = (t_sprite_entity*)((t_entity_node*)pos)->entity;
		next_sprite = (t_sprite_entity*)((t_entity_node*)pos->next)->entity;
		if (sprite->perpendicular_distance
			< next_sprite->perpendicular_distance)
		{
			list_swap_next(pos);
			pos = &self->monster_entities.list;
			continue ;
		}
	}
}

void		raycasting_scene_sort_sprites(t_raycasting_scene *const self)
{
	sort_sprites(self);
	sort_monsters(self);
}
