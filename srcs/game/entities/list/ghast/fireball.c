/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fireball.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 18:27:11 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/04 18:41:09 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/fireball_entity.h"
#include "engine/error.h"
#include "engine/delta.h"

void			fireball_entity_update(t_fireball_entity *const self)
{   
	t_vec3f	direction;
	t_vec3f	player_pos;
	t_vec3f	difference;
	int		distance;
	t_raycasting_scene	*scene;

	sprite_entity_update(&self->super);
	scene = (t_raycasting_scene*)game_singleton()->scene;
	direction = self->super.super.transform.direction;
	player_pos = self->super.player_ref->super.transform.position;
	difference = ft_vec3f(player_pos.x - self->super.super.transform.position.x,
    	player_pos.y - self->super.super.transform.position.y,
   			 player_pos.z - self->super.super.transform.position.z);
	distance = difference.x * difference.x
		+ difference.y * difference.y
			+ difference.z * difference.z; 
	direction = vec3f_scalar(direction, get_last_delta());
	direction = vec3f_scalar(direction, 6);
	self->super.super.transform.position.x += direction.x;
	self->super.super.transform.position.y += direction.y;
	self->super.super.transform.position.z += direction.z;
	if (distance <= 1)
	{
		player_entity_take_damage(scene->player_ref, self->damage);
		entity_list_remove(&scene->super.entities, &self->super.super);
		return ;
	}
	// (void)self;
	ft_putendl("ouais mon gars");
}

t_result		init_fireball_entity(t_fireball_entity *const self,
					const t_fireball_entity_args *const args)
{
	t_raycasting_scene	*scene;

	scene = (t_raycasting_scene*)game_singleton()->scene;
	if (static_module_create(self,
		sprite_entity(args->pos, args->texture_path,
			args->player_ref, &scene->window_ref->frame)) == ERROR)
	{
		return (throw_result_str("init_fireball_entity()",
			"failed to create fireball entity"));
	}
	self->super.super.transform.position = args->pos;
	self->super.super.transform.direction = args->direction;
	self->damage = 50;
	self->super.super.vtable.update = fireball_entity_update;
	return (OK);
}

t_constructor	fireball_entity(const t_vec3f pos, const t_vec3f direction,
	t_player_entity *player_ref)
{
	static t_fireball_entity_args args;

	args.pos = pos;
	args.direction = direction;
	args.texture_path = "resources/sprites/fireball.bmp";
	args.player_ref = player_ref;
	return (ft_constructor(init_fireball_entity, destroy_fireball_entity,
		sizeof(t_fireball_entity), &args));
}

void	destroy_fireball_entity(t_fireball_entity *const self)
{
	(void)self;
	ft_putendl("je detruis");
	destroy_sprite_entity(&self->super);
	ft_putendl("apres desrtroy sprite entity");
}