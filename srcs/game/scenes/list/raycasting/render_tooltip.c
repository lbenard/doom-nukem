/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tooltip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:07:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/16 21:13:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "game/scenes/raycasting_scene.h"

static void	render_door_tooltip(t_raycasting_scene *const self,
				t_frame *const fb)
{
	frame_layer_transform_add(fb,
		&self->tooltips.use_key_text.target,
		ft_frame_transform(ft_vec2f(0.0f, 0.5f),
			ft_isize(fb->size.x / 2 + 20, fb->size.y / 2 + 20),
			ft_vec2f(2.0f, 2.0f),
			255));
	frame_layer_transform_add(fb,
		animation_current(&self->tooltips.use_key_animation,
			&self->assets.use_key_spritesheet),
		ft_frame_transform(ft_vec2f(0.0f, 0.5f),
			ft_isize(fb->size.x / 2
				+ self->tooltips.use_key_text.target.size.x * 2 + 25,
				fb->size.y / 2 + 20),
			ft_vec2f(2.0f, 2.0f),
			255));
}

static void	door_tooltip(t_raycasting_scene *const self,
				t_frame *const fb)
{
	t_game	*game;
	t_ray	*zbuffer;
	t_ray	*mid_ray;
	t_wall	*wall;

	game = game_singleton();
	zbuffer = (t_ray*)self->zbuffer.array;
	mid_ray = &zbuffer[self->window_ref->size.x / 2];
	wall = &self->map.map[(int)mid_ray->hit.y * self->map.size.x
		+ (int)mid_ray->hit.x];
	if ((wall->id == game->blocks_list.metallic_red_button.id
		|| wall->id == game->blocks_list.metallic_green_button.id
		|| wall->id == game->blocks_list.metallic_blue_button.id)
		&& mid_ray->perpendicular_distance < 2.0f)
	{
		render_door_tooltip(self, fb);
		self->tooltips.use_triggered = TRUE;
	}
	else
		self->tooltips.use_triggered = FALSE;
}

static void	render_weapon_tooltip(t_raycasting_scene *const self,
				t_frame *const fb)
{
	frame_layer_transform_add(fb,
		&self->tooltips.pick_key_text.target,
		ft_frame_transform(ft_vec2f(0.0f, 0.5f),
			ft_isize(fb->size.x / 2 + 20,
				fb->size.y / 2 + 20 + 40 * self->tooltips.use_triggered),
			ft_vec2f(2.0f, 2.0f),
			255));
	frame_layer_transform_add(fb,
		animation_current(&self->tooltips.pick_key_animation,
			&self->assets.pick_key_spritesheet),
		ft_frame_transform(ft_vec2f(0.0f, 0.5f),
			ft_isize(fb->size.x / 2
				+ ft_strlen(self->tooltips.pick_key_display) * 5 * 2 + 25,
				fb->size.y / 2 + 20 + 40 * self->tooltips.use_triggered),
			ft_vec2f(2.0f, 2.0f),
			255));

}

static void	weapon_tooltip(t_raycasting_scene *const self,
				t_frame *const fb)
{
	if (self->weapon.nearest_weapon)
	{
		self->tooltips.pick_triggered = TRUE;
		self->tooltips.pick_key_display[0] = 0;
		ft_strcpy((char*)&self->tooltips.pick_key_display, "Switch to ");
		ft_strncat((char*)&self->tooltips.pick_key_display,
			self->weapon.nearest_weapon->specs.name,
			20 - ft_strlen((char*)&self->tooltips.pick_key_display));
		text_set_ref(&self->tooltips.pick_key_text,
			static_string_as_ref(
				ft_static_string(self->tooltips.pick_key_display)));
		text_render(&self->tooltips.pick_key_text,
			ft_text_settings(ft_isize(0, 0), 9));
		frame_fill_blend(&self->tooltips.pick_key_text.target,
			ft_rgba(255, 255, 255, 255),
			blend_colorize);
		render_weapon_tooltip(self, fb);
	}
	else
		self->tooltips.pick_triggered = FALSE;
}

void		raycasting_scene_render_tooltip(t_raycasting_scene *const self,
				t_frame *const fb)
{
	door_tooltip(self, fb);
	weapon_tooltip(self, fb);
}
