/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 21:33:32 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 21:34:23 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sound.h"

void	destroy_sound(t_sound *const self)
{
	destroy_module(&self->module);
	if (self->sound)
		sfSound_destroy(self->sound);
	if (self->sound_buffer)
		sfSoundBuffer_destroy(self->sound_buffer);
}
