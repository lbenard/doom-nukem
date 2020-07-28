/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:24:54 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/28 15:47:11 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "ft/io.h"

static void	render_weapon_shooting(t_raycasting_scene *const self)
{
	if (self->weapon.just_shooted == TRUE)
	{
		self->pistol_anim.speed = 0.2;
		self->weapon.shooting = TRUE;
		self->pistol_anim.iter = 0;
	}
	if (self->weapon.shooting == TRUE)
	{
		if (self->pistol_anim.iter == self->pistol_ss.grid_size.x *
			(1 / 0.2) - 1)
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
		ft_putendl("fengjgikrhjhiojhioh");
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
			ft_putendl("couilles");
			self->pistol_anim.iter = 0;
			self->pistol_anim.anim++;
			if (self->pistol_anim.anim >= 3)
			{
				ft_putendl("seches");
				self->pistol_anim.anim = 0;
				self->pistol_anim.speed = 0;
				self->weapon.reloading = FALSE;
			}
		}
	}
}

void	render_weapon(t_raycasting_scene *const self, t_frame *const fb)
{
	render_weapon_shooting(self);
	render_weapon_reloading(self);
	frame_layer_transform_add(fb, animation_current(&self->pistol_anim,
		&self->pistol_ss), ft_frame_transform(ft_vec2f(0.5, 1),
			ft_isize(fb->size.x / 2, fb->size.y), ft_vec2f(3, 3), 255));

}