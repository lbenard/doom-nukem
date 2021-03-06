/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:42:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 15:10:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "game/scenes/raycasting_scene.h"
#include "game/entities/monster_entity.h"
#include "ft/mem.h"
#include "maths/maths.h"
#include "engine/delta.h"
#include "engine/lookup_table.h"

static void	display_hud(t_raycasting_scene *self, t_frame *const fb)
{
	int				perc_sprite;
	float			index_sprite;
	static double	i;
	float			amplitude;
	float			fx;

	perc_sprite = ft_max(100 * self->entities.player_ref->health / 150, 0);
	index_sprite = ((float)self->hud_ray.heart_ss.grid_size.x / 100.0f)
		* perc_sprite;
	amplitude = 4.0f - 0.3 * (8 - index_sprite);
	i += 0.04 + (float)((8 - index_sprite) / 100);
	if (i >= 3.160)
		i = 0;
	fx = 2 + cos((i - 0.523) * 3) * sin((i - 0.523))
		/ ((i - 0.523) * amplitude);
	frame_layer_transform(fb,
		&self->hud_ray.heart_ss.sprite[8 - ft_max(ft_min(index_sprite, 8), 1)],
			ft_frame_transform(ft_vec2f(0.5f, 0.5f),
				ft_isize(fb->size.x / 2 -
					self->hud_ray.heart_ss.grid_size.x / 2,
					fb->size.y - self->hud_ray.heart_ss.sprite_size.y * 3),
						ft_vec2f(fx * 2, fx * 2), 255), blend_add);
	raycasting_scene_render_tooltip(self, fb);
}

static void	render_game_over_background(t_raycasting_scene *const self,
				t_frame *const fb,
				const float opacity)
{
	float		scale;

	scale = 4 + ft_fmin((get_wall_time() - self->death_time) * 1.0f, 8.0f);
	frame_layer_transform_add(fb,
		&self->assets.game_over_background,
		ft_frame_transform(ft_vec2f(0.5f, 0.5f),
		ft_isize(fb->size.x / 2, fb->size.y / 2),
		ft_vec2f(fb->size.x / (float)self->assets.game_over_background.size.x,
			fb->size.y / (float)self->assets.game_over_background.size.y),
		opacity));
	frame_layer_transform(fb, &self->assets.game_over.target,
		ft_frame_transform(ft_vec2f(0.5f, 1.5f),
			ft_isize(fb->size.x / 2, fb->size.y / 2),
			ft_vec2f(scale, scale),
			opacity),
		blend_invert);
}

static void	render_game_over_buttons(t_raycasting_scene *const self,
				t_frame *const fb)
{
	t_usize	mid;
	t_vec2i	mouse;
	double	wall;

	SDL_GetMouseState(&mouse.x, &mouse.y);
	mid = ft_usize(self->window_ref->size.x / 2, self->window_ref->size.y / 2);
	wall = get_wall_time() / 5.0f;
	self->entities.retry_button_ref->super.transform.position = ft_vec3f(
		cosine_lookup(wall - (int)wall) * 10.0f + mid.x
			- (mouse.x - (int)mid.x) / 50.0f
			- (self->entities.retry_button_ref->normal_texture.size.x / 2),
		sine_lookup(wall - (int)wall) * 5.0f + mid.y + 45
			- (mouse.y - (int)mid.y) / 50.0f
			- (self->entities.retry_button_ref->normal_texture.size.y / 2),
		0.0f);
	button_entity_render(self->entities.retry_button_ref, fb);
	self->entities.give_up_button_ref->super.transform.position = ft_vec3f(
		sine_lookup(wall - (int)wall) * 10.0f + mid.x
			- (mouse.x - (int)mid.x) / 50.0f
			- (self->entities.give_up_button_ref->normal_texture.size.x / 2),
		sine_lookup(wall - (int)wall) * 5.0f + mid.y + 125
			- (mouse.y - (int)mid.y) / 50.0f
			- (self->entities.give_up_button_ref->normal_texture.size.y / 2),
		0.0f);
	button_entity_render(self->entities.give_up_button_ref, fb);
}

static void	render_game_over(t_raycasting_scene *const self,
				t_frame *const fb)
{
	t_u8		opacity;

	opacity = ft_fmin((get_wall_time() - self->death_time) * 32.0f, 255.0f);
	render_game_over_background(self, fb, opacity);
	render_game_over_buttons(self, fb);
}

// #include <stdio.h>

// static void	render_skybox(t_raycasting_scene *const self,
// 				t_frame *const fb, float p_hView, float p_vView)
// {
// 	t_usize	i;
// 	float	offset;
// 	t_vec2f	ratio;

// 	(void)p_vView;
// 	offset = self->assets.skybox.size.x / 2 * M_PI;
// 	offset *= p_hView;
// 	ratio.x = fb->size.x / (float)self->assets.skybox.size.x / 1.0f;
// 	ratio.y = (fb->size.y + 200.0f) / (float)self->assets.skybox.size.y;
// 	printf("ratio %f %f\n", ratio.x, ratio.y);
// 	i.y = 0;
// 	while (i.y < fb->size.y / 2 + self->entities.player_ref->super.transform.rotation.x)
// 	{
// 		i.x = 0;
// 		while (i.x < fb->size.x)
// 		{
// 			fb->pixels[i.y * fb->size.x + i.x] =
// 				self->assets.skybox.pixels[(int)((int)((float)i.y / ratio.y) * self->assets.skybox.size.x + (int)(i.x / ratio.x + offset))];
// 			i.x++;
// 		}
// 		i.y++;
// 	}
// }

void	render_skybox(t_raycasting_scene *const self,
			t_frame *const fb,
			float p_hView,
			float p_vView)
{
	float	offset;
	int		scale;
	t_usize	i;

	(void)p_vView;
	scale = 1;
	offset = self->assets.skybox.size.x / 2 * M_PI * scale;
	offset *= p_hView;
	i.y = 0;
	while (i.y < fb->size.y)
	{
		i.x = 0;
		while (i.x < fb->size.x)
		{
			fb->pixels[i.y * fb->size.x + i.x] = self->assets.skybox.pixels[(int)(i.y * self->assets.skybox.size.x + i.x + offset) % self->assets.skybox.size.x];
			i.x++;
		}
		i.y++;
	}
}

void		raycasting_scene_render(t_raycasting_scene *const self,
				t_frame *const fb)
{
	frame_fill(fb, ft_rgba(42, 0, 0, 255));
	raycasting_scene_render_screen(self);
	render_skybox(self, fb, self->entities.player_ref->super.transform.rotation.y, 100.0f);
	if (self->map.floor)
		raycasting_scene_render_floor(self, fb,
			self->entities.player_ref->dir, self->entities.player_ref->plane);
	if (self->map.ceiling)
		raycasting_scene_render_ceiling(self, fb,
			self->entities.player_ref->dir, self->entities.player_ref->plane);
	raycasting_scene_render_map(self, fb);
	raycasting_scene_render_monster_infos(self, fb);
	if (!self->entities.player_ref->is_dead)
	{
		frame_layer_transform(fb, &self->assets.crosshair,
			ft_frame_transform(ft_vec2f(0.5f, 0.5f),
				ft_isize(fb->size.x / 2, fb->size.y / 2),
				ft_vec2f(1.0f, 1.0f),
				255),
			blend_invert);
		raycasting_scene_render_weapon_display(self, fb);
		raycasting_scene_render_weapon(self, fb);
		display_hud(self, fb);
	}
	else
		render_game_over(self, fb);
	frame_layer_opaque(&self->last_frame, fb, ft_isize(0, 0));
}
