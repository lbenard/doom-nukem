/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:16:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 00:28:40 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/menu_scene.h"
#include "engine/game.h"
#include "engine/delta.h"
#include "engine/lookup_table.h"
#include "game/scenes/raycasting_scene.h"

static void	update_buttons(t_menu_scene *const self)
{
	double		wall;
	t_usize		mid;
	sfVector2i	mouse;

	wall = get_wall_time() / 5.0f;
	mouse = sfMouse_getPositionRenderWindow(game_singleton()->window.window);
	mid = ft_usize(self->window_size.x / 2, self->window_size.y / 2);
	self->start_game_ref->super.transform.position = ft_vec3f(
		cosine_lookup(wall - (int)wall) * 10.0f + mid.x
			- (mouse.x - (int)mid.x) / 50.0f
			- (self->start_game_ref->normal_texture.size.x / 2),
		sine_lookup(wall - (int)wall) * 5.0f + mid.y + 30
			- (mouse.y - (int)mid.y) / 50.0f
			- (self->start_game_ref->normal_texture.size.y / 2),
		0.0f);
	self->close_game_ref->super.transform.position = ft_vec3f(
		sine_lookup(wall - (int)wall) * 10.0f + mid.x
			- (mouse.x - (int)mid.x) / 50.0f
			- (self->close_game_ref->normal_texture.size.x / 2),
		sine_lookup(wall - (int)wall) * 5.0f + mid.y + 120
			- (mouse.y - (int)mid.y) / 50.0f
			- (self->close_game_ref->normal_texture.size.y / 2),
		0.0f);
}

static void	update_images(t_menu_scene *const self)
{
	double		wall;
	t_usize		mid;
	sfVector2i	mouse;

	wall = get_wall_time() / 5.0f;
	mouse = sfMouse_getPositionRenderWindow(game_singleton()->window.window);
	mid = ft_usize(self->window_size.x / 2, self->window_size.y / 2);
	self->title_ref->super.transform.position = ft_vec3f(
		cosine_lookup(wall - (int)wall) * 5.0f + mid.x
			- (mouse.x - (int)mid.x) / 200.0f
			- (self->title_ref->image.size.x / 2),
		sine_lookup(wall - (int)wall) * 2.0f + mid.y - 150
			- (mouse.y - (int)mid.y) / 200.0f
			- (self->title_ref->image.size.y / 2),
		0.0f);
	self->credits_ref->super.transform.position = ft_vec3f(5,
		self->window_size.y - self->credits_ref->image.size.y - 5, 0);
}

void		menu_scene_update(t_menu_scene *const self)
{
	entity_list_update(&self->super.entities);
	if (self->start_game_ref->is_clicked)
	{
		game_set_scene(raycasting_scene(&game_singleton()->window));
		return ;
	}
	if (self->close_game_ref->is_clicked)
		window_close(&game_singleton()->window);
	update_buttons(self);
	update_images(self);
}
