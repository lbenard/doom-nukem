/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:25:42 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 18:57:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "engine/music.h"

t_result	init_music(t_music *const self, t_music_args *const args)
{
	init_module(&self->module);
	if (!(self->music = Mix_LoadMUS(args->path)))
		return (throw_result_str("init_music()", "failed to load music"));
	return (OK);
}
