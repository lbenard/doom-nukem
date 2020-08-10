/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon_display.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:04:04 by lbenard           #+#    #+#             */
/*   Updated: 2020/08/10 19:27:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/raycasting_scene.h"
#include "maths/maths.h"
#include "ft/str.h"

static void	itoa_limit(char *const dest, size_t n, size_t limit)
{
	size_t	nb_len;
	size_t	pow;

	if ((nb_len = ft_nblen(n)) > limit)
	{
		nb_len = limit;
		pow = limit;
		n = 1;
		while (pow--)
			n *= 10;
		n--;
	}
	dest[nb_len] = 0;
	while (42)
	{
		dest[--nb_len] = '0' + n % 10;
		n /= 10;
		if (!n)
			break ;
	}
	return ;
}


static void	update_display(t_raycasting_scene *const self)
{
	itoa_limit(self->weapon.display, self->entities.weapon_ref->specs.clip, 4);
	ft_strcat(self->weapon.display, "/");
	itoa_limit(self->weapon.display + ft_strlen(self->weapon.display),
		self->weapon.ammo, 4);
	text_set_ref(&self->weapon.display_text,
		static_string_as_ref(ft_static_string(self->weapon.display)));
	text_render(&self->weapon.display_text,
		ft_text_settings(ft_isize(0, 0), 9));
	frame_fill_blend(&self->weapon.display_text.target,
		ft_rgba(0, 0, 0, 255),
		blend_colorize);
}

void	raycasting_scene_render_weapon_display(t_raycasting_scene *const self,
			t_frame *const fb)
{
	if (self->entities.weapon_ref)
	{
		if (self->entities.weapon_ref->first_render
			|| self->entities.weapon_ref->just_shooted
			|| self->entities.weapon_ref->just_reloaded)
			update_display(self);
		self->entities.weapon_ref->first_render = FALSE;
		frame_layer_transform_add(fb,
			&self->weapon.display_text.target,
			ft_frame_transform(ft_vec2f(0.0f, 1.0f),
				ft_isize(10 - 2, fb->size.y - 5 - 2),
				ft_vec2f(3.0f, 3.0f),
				255));
	}
}
