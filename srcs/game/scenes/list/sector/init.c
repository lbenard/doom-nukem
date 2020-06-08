/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 20:21:41 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/08 20:30:11 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "game/scenes/sector_scene.h"
#include "engine/error.h"
#include "engine/game.h"

t_result	init_sector_scene(t_sector_scene *const self)
{
	if (init_scene(
		&self->super,
		"Sector",
		sector_scene_update,
		sector_scene_render) == ERROR)
	{
		return (throw_result_str("init_sector_scene", "failed to init scene"));
	}
	module_add(&self->super.module, &self->wall_texture, frame_from_file("resources/textures/plaster.jpg"));
	if (!(self->sectors = (t_sector*)malloc(sizeof(t_sector) * 1)))
	{
		destroy_sector_scene(self);
		return (throw_result_str("init_sector_scene", "failed to allocate sectors"));
	}
	self->sectors[0].wall_number = 4;
	if (!(self->sectors[0].walls = (t_wall*)malloc(sizeof(t_wall) * self->sectors[0].wall_number)))
	{
		destroy_sector_scene(self);
		return (throw_result_str("init_sector_scene", "failed to allocate sectors"));
	}
	self->sectors[0].walls[0].a = ft_vec2f(-5.0f, 5.0f);
	self->sectors[0].walls[0].b = ft_vec2f(5.0f, 5.0f);
	self->sectors[0].walls[0].is_portal = FALSE;
	self->sectors[0].walls[0].color = ft_rgb(255, 255, 255);
	self->sectors[0].walls[0].texture_ref = &self->wall_texture;
	
	self->sectors[0].walls[1].a = ft_vec2f(5.0f, 5.0f);
	self->sectors[0].walls[1].b = ft_vec2f(5.0f, -5.0f);
	self->sectors[0].walls[1].is_portal = FALSE;
	self->sectors[0].walls[1].color = ft_rgb(255, 0, 0);
	self->sectors[0].walls[1].texture_ref = &self->wall_texture;
	
	self->sectors[0].walls[2].a = ft_vec2f(5.0f, -5.0f);
	self->sectors[0].walls[2].b = ft_vec2f(-5.0f, -5.0f);
	self->sectors[0].walls[2].is_portal = FALSE;
	self->sectors[0].walls[2].color = ft_rgb(0, 255, 0);
	self->sectors[0].walls[2].texture_ref = &self->wall_texture;
	
	self->sectors[0].walls[3].a = ft_vec2f(-5.0f, -5.0f);
	self->sectors[0].walls[3].b = ft_vec2f(-5.0f, 5.0f);
	self->sectors[0].walls[3].is_portal = FALSE;
	self->sectors[0].walls[3].color = ft_rgb(0, 0, 255);
	self->sectors[0].walls[3].texture_ref = &self->wall_texture;

	self->current_sector = &self->sectors[0];

	self->camera.position = ft_vec2f(0.0f, 0.0f);
	self->camera.angle = M_PI / 2.0f;
	self->camera.direction_vector = ft_vec2f(
		cos(self->camera.angle),
		sin(self->camera.angle));
	self->camera.fov = 120.0f / 180.0f * M_PI;
	self->camera.plan_width = game_singleton()->window.size.x;
	self->camera.camera_to_plan_dist = (self->camera.plan_width / 2.0) / tan(self->camera.fov / 2.0);
	self->camera.to_plan = vec2f_scalar(self->camera.direction_vector, self->camera.camera_to_plan_dist);
	self->camera.plan = ft_vec2f(self->camera.direction_vector.y, -self->camera.direction_vector.x);

	self->w = input_get_id(&game_singleton()->input, "Forward");
	self->a = input_get_id(&game_singleton()->input, "Left");
	self->s = input_get_id(&game_singleton()->input, "Backward");
	self->d = input_get_id(&game_singleton()->input, "Right");
	self->left_arrow = input_get_id(&game_singleton()->input, "TurnLeft");
	self->right_arrow = input_get_id(&game_singleton()->input, "TurnRight");
	if (self->super.module.has_error)
	{
		destroy_sector_scene(self);
		return (throw_result_str("init_sector_scene",
			"failed to init new sector scene"));
	}
	return (OK);
}