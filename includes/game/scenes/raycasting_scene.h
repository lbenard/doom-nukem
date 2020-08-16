/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:51:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/17 00:15:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_SCENE_H
# define RAYCASTING_SCENE_H

# include "engine/scene.h"
# include "engine/window.h"
# include "engine/frame.h"
# include "engine/array.h"
# include "engine/sound.h"
# include "engine/text.h"
# include "engine/animation.h"
# include "engine/spritesheet.h"
# include "game/entities/player_entity.h"
# include "game/entities/image_entity.h"
# include "game/entities/button_entity.h"
# include "game/entities/weapon_entity.h"
# include "game/entity_descriptor.h"
# include "maths/vec2i.h"
# include "maths/vec2f.h"
# include "game/hud_game.h"

/*
** Raycasting level scene
*/
typedef struct	s_raycasting_scene
{
	t_scene			super;
	t_map			map;
	const char		*path;
	t_window		*window_ref;
	t_hud_game		hud_ray;
	double			death_time;
	float			fov;
	t_array			zbuffer;
	t_entity_list	sprite_entities;
	t_entity_list	monster_entities;
	t_entity_list	weapon_entities;
	t_entity_list	ammo_entities;
	struct	s_assets
	{
		t_frame			floor;
		t_frame			ceiling;
		t_frame			crosshair;
		t_spritesheet	use_key_spritesheet;
		t_spritesheet	pick_key_spritesheet;
		t_frame			game_over_background;
		t_text			game_over;
		t_spritesheet	fireball_spritesheet;
		t_spritesheet	alien_spritesheet;
		t_spritesheet	onepunchman_spritesheet;
		t_spritesheet	ghast_spritesheet;
		t_spritesheet	nyarlathotep_spritesheet;
		t_spritesheet	pistol_spritesheet;
		t_sound			pistol_sound;
		t_spritesheet	shotgun_spritesheet;
		t_spritesheet	minigun_spritesheet;
		t_frame			ammo_sprite;
	}				assets;
	struct	s_inputs
	{
		t_input_id	use;
		t_input_id	shoot;
		t_input_id	reload;
		t_input_id	pick;
	}				inputs;
	struct	s_entities_ref
	{
		t_button_entity	*retry_button_ref;
		t_button_entity	*give_up_button_ref;
		t_player_entity	*player_ref;
		t_weapon_entity	*weapon_ref;
	}				entities;
	struct	s_weapon_infos
	{
		size_t					ammo;
		double					last_shot;
		char					display[10];
		t_text					display_text;
		const t_weapon_entity	*nearest_weapon;
	}				weapon;
	struct	s_tooltips
	{
		t_animation		use_key_animation;
		t_text			use_key_text;
		t_bool			use_triggered;
		t_animation		pick_key_animation;
		char			pick_key_display[20];
		t_text			pick_key_text;
		t_bool			pick_triggered;
	}				tooltips;
}				t_raycasting_scene;

typedef struct	s_raycasting_scene_args
{
	t_window	*window;
	const char	*path;
}				t_raycasting_scene_args;

t_constructor	raycasting_scene(t_window *const window,
					const char *path);

t_result		init_raycasting_scene(t_raycasting_scene *const self,
					t_raycasting_scene_args *const args);
void			init_raycasting_scene_vars(t_raycasting_scene *const self,
					t_raycasting_scene_args *const args);
void			init_raycasting_scene_modules(
					t_raycasting_scene *const self);
void			init_raycasting_scene_tooltips(
					t_raycasting_scene *const self);
void			init_raycasting_scene_entity_lists(
					t_raycasting_scene *const self);
void			init_raycasting_scene_assets(
					t_raycasting_scene *const self);
void			init_raycasting_scene_inputs(
					t_raycasting_scene *const self);
void			init_raycasting_scene_weapon(
					t_raycasting_scene *const self);
void			raycasting_scene_add_entities(
					t_raycasting_scene *const self);
void			raycasting_scene_add_death_buttons(
					t_raycasting_scene *const self);

void			raycasting_scene_update(t_raycasting_scene *const self);
void			raycasting_scene_render(t_raycasting_scene *const self,
					t_frame *const fb);
void			raycasting_scene_render_sprites(t_raycasting_scene *const self,
					t_frame *const fb);
void			raycasting_scene_render_weapon_display(
					t_raycasting_scene *const self,
					t_frame *const fb);
void			raycasting_scene_render_weapon(t_raycasting_scene *const self,
					t_frame *const fb);
void			raycasting_scene_render_tooltip(t_raycasting_scene *const self,
					t_frame *const fb);

t_result		raycasting_scene_add_entity(t_raycasting_scene *const self,
					const t_entity_descriptor *const entity_descriptor,
					const t_vec2f pos);
void			raycasting_scene_kill_monster(t_raycasting_scene *const self,
					const t_entity *const monster);

void			raycasting_scene_weapon_set_pistol(
					t_raycasting_scene *const self);
void			raycasting_scene_weapon_set_minigun(
					t_raycasting_scene *const self);

void			raycasting_scene_weapon_set_shotgun(
					t_raycasting_scene *const self);

void			raycasting_scene_weapon_use(t_raycasting_scene *const self);
t_bool			raycasting_scene_weapon_shoot(t_raycasting_scene *const self,
					const size_t ammo_amount);
void			raycasting_scene_weapon_reload(t_raycasting_scene *const self);

void			destroy_raycasting_scene(t_raycasting_scene *const self);

t_rgba			ft_get_lerp_col(t_rgba color1, float dist, float value);
/*
** Utils
*/
typedef struct	s_ray
{
	t_vec2f	hit;
	float	perpendicular_distance;
	float	horizontal_ratio;
}				t_ray;

t_ray			cast(const t_map *const map,
					const t_vec2f pos,
					const t_vec2f dir);

#endif
