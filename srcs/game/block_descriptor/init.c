/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:05:18 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/05 20:21:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/block_descriptor.h"
#include "engine/error.h"

static t_bool	is_translucent(t_block_descriptor *const self)
{
	t_usize	i;

	i.y = 0;
	while (i.y < self->texture.size.y)
	{
		i.x = 0;
		while (i.x < self->texture.size.x)
		{
			if (self->texture.pixels[i.y * self->texture.size.x + i.x].c.a
				!= 255)
				return (TRUE);
			i.x++;
		}
		i.y++;
	}
	return (FALSE);
}

t_result		init_block_descriptor(t_block_descriptor *const self,
					t_block_descriptor_args *const args)
{
	init_module(&self->module);
	module_add(&self->module, &self->texture,
		frame_from_file(args->texture_path));
	self->id = args->id;
	self->name = args->name;
	self->path = args->texture_path;
	if (self->module.has_error)
	{
		destroy_block_descriptor(self);
		return (throw_result_str("init_block_descriptor()",
			"failed to init editor block"));
	}
	self->translucent = is_translucent(self);
	return (OK);
}
