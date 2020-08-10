/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tooltip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:07:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 18:46:59 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"

static void	render_tooltip(t_raycasting_scene *const self,
				t_frame *const fb)
{
	frame_layer_transform_add(fb,
		&self->assets.use_key_text.target,
		ft_frame_transform(ft_vec2f(0.0f, 0.5f),
			ft_isize(fb->size.x / 2 + 20, fb->size.y / 2 + 20),
			ft_vec2f(2.0f, 2.0f),
			255));
	frame_layer_transform_add(fb,
		animation_current(&self->assets.use_key_animation,
			&self->assets.use_key_spritesheet),
		ft_frame_transform(ft_vec2f(0.0f, 0.5f),
			ft_isize(fb->size.x / 2 + self->assets.use_key_text.target.size.x * 2 + 25,
				fb->size.y / 2 + 20),
			ft_vec2f(2.0f, 2.0f),
			255));
}

void		raycasting_scene_render_tooltip(t_raycasting_scene *const self,
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
		render_tooltip(self, fb);
}
