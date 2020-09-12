/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:27:23 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 17:28:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sound.h"

void	destroy_sound(t_sound *const self)
{
	destroy_module(&self->module);
	Mix_FreeChunk(self->sound);
}
