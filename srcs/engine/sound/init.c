/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:25:42 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 17:37:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "engine/sound.h"

t_result	init_sound(t_sound *const self, t_sound_args *const args)
{
	init_module(&self->module);
	if (!(self->sound = Mix_LoadWAV(args->path)))
		return (throw_result_str("init_sound()", "failed to load sound"));
	return (OK);
}
