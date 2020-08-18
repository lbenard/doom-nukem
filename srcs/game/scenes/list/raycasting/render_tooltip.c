/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tooltip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:07:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/18 19:17:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "maths/maths.h"
#include "engine/delta.h"
#include "game/scenes/raycasting_scene.h"

static void	use_tooltip(t_raycasting_scene *const self,
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
		|| wall->id == game->blocks_list.metallic_blue_button.id
		|| wall->id == game->blocks_list.ending.id)
		&& mid_ray->perpendicular_distance < 2.0f)
	{
		raycasting_scene_render_use_tooltip(self, fb);
		self->tooltips.use_triggered = TRUE;
	}
	else
		self->tooltips.use_triggered = FALSE;
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
		raycasting_scene_render_weapon_tooltip(self, fb);
	}
	else
		self->tooltips.pick_triggered = FALSE;
}

static void	ending_tooltip(t_raycasting_scene *const self,
				t_frame *const fb)
{
	if (self->tooltips.ending_triggered)
		self->tooltips.ending_text_opacity = 3.0f;
	if (self->tooltips.ending_text_opacity <= 0.0f)
		return ;
	self->tooltips.ending_triggered = FALSE;
	frame_layer_transform_add(fb,
		&self->tooltips.ending_text.target,
		ft_frame_transform(ft_vec2f(0.5f, 0.0f),
			ft_isize(fb->size.x / 2,
				fb->size.y - 40),
			ft_vec2f(2.0f, 2.0f),
			ft_min(self->tooltips.ending_text_opacity * 255.0f, 255)));
	self->tooltips.ending_text_opacity -= 1.0f * get_last_delta();
	if (self->tooltips.ending_text_opacity < 0.0f)
		self->tooltips.ending_text_opacity = 0.0f;
}

void		raycasting_scene_render_tooltip(t_raycasting_scene *const self,
				t_frame *const fb)
{
	use_tooltip(self, fb);
	weapon_tooltip(self, fb);
	ending_tooltip(self, fb);
}
