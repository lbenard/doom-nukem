/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 21:25:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 21:32:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sound.h"
#include "engine/error.h"

t_result	init_sound(t_sound *const self, const t_sound_args *const args)
{
	init_module(&self->module);
	self->sound_buffer = NULL;
	self->sound = NULL;
	if (!(self->sound_buffer = sfSoundBuffer_createFromFile(args->path)))
	{
		destroy_sound(self);
		return (throw_result_str("init_sound()",
			"failed to load sound buffer"));
	}
	if (!(self->sound = sfSound_create()))
	{
		destroy_sound(self);
		return (throw_result_str("init_sound()",
			"failed to create sound"));
	}
	sfSound_setBuffer(self->sound, self->sound_buffer);
	return (OK);
}
