/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:26:48 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 17:27:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sound.h"

void	sound_play(t_sound *const self)
{
	Mix_VolumeChunk(self->sound, MIX_MAX_VOLUME);
	Mix_PlayChannel(-1, self->sound, 0);
}
