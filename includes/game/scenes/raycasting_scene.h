/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_scene.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:51:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/05 16:07:48 by lbenard          ###   ########.fr       */
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
# include "game/entities/camera_entity.h"
# include "game/entities/button_entity.h"
# include "game/entities/weapon_entity.h"
# include "game/entity_descriptor.h"
# include "maths/vec2i.h"
# include "maths/vec2f.h"
# include "game/hud_game.h"

typedef struct	s_weapon
{
	char	*name;
	size_t	ammo;
	size_t	clip;
	size_t	clip_size;
	float	damage;
	float	shoot_time;
	double	last_shot;
}				t_weapon;

/*
** Raycasting level scene
*/
typedef struct	s_raycasting_scene
{
	t_scene				super;
	t_map				map;
	const char			*path;
	t_rgb				ground_color;
	t_rgb				sky_color;
	t_frame				floor;
	t_frame				ceiling;
	t_frame				crosshair;
	t_spritesheet		use_key_spritesheet;
	t_animation			use_key_animation;
	t_text				use_key_text;
	t_text				game_over;
	double				death_time;
	t_frame				game_over_background;
	t_button_entity		*retry_button_ref;
	t_button_entity		*give_up_button_ref;
	t_array				zbuffer;
	t_player_entity		*player_ref;
	t_input_id			use_input;
	t_hud_game			hud_ray;
	t_weapon_entity		*weapon_ref;
	struct s_weapon_infos
	{
		t_weapon			weapon;
		t_bool				reloading;
		t_bool				shooting;
		t_bool				just_shooted;
		t_bool				just_reloaded;
		t_bool				first_render;
		t_input_id			shoot_input;
		t_input_id			reload_input;
		char				display[10];
		t_text				display_text;
		int					shotgun;
	}					weapon;
	t_camera_entity		*camera_ref;
	t_entity_list		sprite_entities;
	t_entity_list		monster_entities;
	t_window			*window_ref;
	t_sound				pistol;
	t_spritesheet		alien_spritesheet;
	t_spritesheet		onepunchman_spritesheet;
	t_spritesheet		ghast_spritesheet;
	t_spritesheet		pistol_ss;
	t_spritesheet		shotgun_ss;
	t_spritesheet		minigun_ss;
	t_animation			pistol_anim;
	t_animation			shotgun_anim;
	t_animation			minigun_anim;
	t_bool				end_anim;
	t_bool				last_shot;
	float				fov;
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
t_result		init_assets(t_raycasting_scene *const self);

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
