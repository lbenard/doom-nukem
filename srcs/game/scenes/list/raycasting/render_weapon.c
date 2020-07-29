/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:24:54 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/29 15:54:31 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/io.h"
#include "ft/str.h"

static void	render_shotgun_shooting(t_raycasting_scene *const self)
{
	if (self->weapon.just_shooted == TRUE)
	{
		self->shotgun_anim.speed = 0.5;
		self->weapon.shooting = TRUE;
		self->shotgun_anim.iter = 0;
	}
	if (self->weapon.shooting == TRUE)
	{
		if (self->shotgun_anim.iter == self->shotgun_ss.grid_size.x *
			(1 / 0.5) - 1)
		{
			self->shotgun_anim.speed = 0;
			self->shotgun_anim.anim = 0;
			self->weapon.shooting = FALSE;
		}
	}
}

static void render_shotgun_reloading(t_raycasting_scene *const self)
{
	if (self->weapon.just_reloaded == TRUE)
	{
		if (self->weapon.shotgun == 1)
		{
			ft_putendl("clip 1 donc anim 3");
			self->shotgun_anim.anim = 3;
		}
		else
		{
			ft_putendl("clip 0 donc anim 1");
			self->shotgun_anim.anim = 1;
		}
		self->shotgun_anim.speed = 0.08;
		self->weapon.reloading = TRUE;
		self->shotgun_anim.iter = 0;
	}
	if (self->weapon.reloading == TRUE)
	{
		if (self->shotgun_anim.iter == self->pistol_ss.grid_size.x *
			(1 / 0.08) - 1 && self->shotgun_anim.speed != 0)
		{
			self->shotgun_anim.iter = 0;
			if (self->weapon.shotgun == 2)
				self->shotgun_anim.anim++;
			if (self->shotgun_anim.anim >= 3)
			{
				self->shotgun_anim.anim = 0;
				self->shotgun_anim.speed = 0;
				self->weapon.reloading = FALSE;
			}
		}
	}
}

static void	render_weapon_shooting(t_raycasting_scene *const self)
{
	if (self->weapon.just_shooted == TRUE)
	{
		self->pistol_anim.speed = 0.4;
		self->weapon.shooting = TRUE;
		self->pistol_anim.iter = 0;
	}
	if (self->weapon.shooting == TRUE)
	{
		if (self->pistol_anim.iter == self->pistol_ss.grid_size.x *
			(1 / 0.4) - 1)
		{
			self->pistol_anim.speed = 0;
			self->pistol_anim.anim = 0;
			self->weapon.shooting = FALSE;
		}
	}
}

static void	render_weapon_reloading(t_raycasting_scene *const self)
{
	if (self->weapon.just_reloaded == TRUE)
	{
		self->pistol_anim.anim = 1;
		self->pistol_anim.speed = 0.08;
		self->weapon.reloading = TRUE;
		self->pistol_anim.iter = 0;
	}
	if (self->weapon.reloading == TRUE)
	{
		if (self->pistol_anim.iter == self->pistol_ss.grid_size.x *
			(1 / 0.08) - 1 && self->pistol_anim.speed != 0)
		{
			self->pistol_anim.iter = 0;
			self->pistol_anim.anim++;
			if (self->pistol_anim.anim >= 3)
			{
				self->pistol_anim.anim = 0;
				self->pistol_anim.speed = 0;
				self->weapon.reloading = FALSE;
			}
		}
	}
}

void	raycasting_scene_render_weapon(t_raycasting_scene *const self,
			t_frame *const fb)
{
	if (ft_strcmp(self->weapon.weapon.name, "Pistol") == 0)
	{
		render_weapon_shooting(self);
		render_weapon_reloading(self);
		frame_layer_transform_add(fb, animation_current(&self->pistol_anim,
			&self->pistol_ss), ft_frame_transform(ft_vec2f(1, 1),
				ft_isize(fb->size.x - fb->size.x / 6, fb->size.y),
					ft_vec2f(3, 3), 255));
	}
	else if (ft_strcmp(self->weapon.weapon.name, "Shotgun") == 0)
	{
		render_shotgun_shooting(self);
		render_shotgun_reloading(self);
		frame_layer_transform_add(fb, animation_current(&self->shotgun_anim,
			&self->shotgun_ss), ft_frame_transform(ft_vec2f(1, 1),
				ft_isize(fb->size.x - fb->size.x / 6, fb->size.y),
					ft_vec2f(3, 3), 255));
	}

}