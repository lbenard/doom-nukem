/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_entity.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 01:49:21 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/19 04:33:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_ENTITY_H
# define WEAPON_ENTITY_H

# include "game/entities/sprite_entity.h"
# include "engine/spritesheet.h"
# include "engine/animation.h"

typedef struct	s_weapon_specs
{
	const char	*name;
	size_t		clip;
	size_t		clip_size;
	float		damage;
	float		shoot_time;
	float		loading_time;
	float		decay;
}				t_weapon_specs;

t_weapon_specs	ft_weapon_specs_default(void);

typedef struct	s_weapon_entity
{
	t_sprite_entity	super;
	t_bool			is_picked;
	t_spritesheet	*hud_ref;
	t_frame			hud;
	t_weapon_specs	specs;
	t_bool			first_render;
	double			last_shot;
	t_bool			loading;
	t_bool			reloading;
	t_bool			shooting;
	t_bool			trigger_reloading;
	t_bool			stopped_shooting;
	t_bool			just_shooted;
	t_bool			just_reloaded;
	double			load_start;
	double			reload_start;
	double			shoot_start;
}				t_weapon_entity;

typedef struct s_raycasting_scene	t_raycasting_scene;

typedef struct	s_weapon_entity_args
{
	const t_spritesheet	*spritesheet_ref;
	const char			*icon_path;
	t_weapon_specs		specs;
	t_raycasting_scene	*ctx;
}				t_weapon_entity_args;

t_constructor	weapon_entity(const t_spritesheet *const spritesheet_ref,
					const char *const icon_path,
					const t_weapon_specs specs,
					t_raycasting_scene *const ctx);

t_result		init_weapon_entity(t_weapon_entity *const self,
					const t_weapon_entity_args *const args);

void			weapon_entity_update(t_weapon_entity *const self);

void			destroy_weapon_entity(t_weapon_entity *const self);

#endif
