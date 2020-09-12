/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:27:23 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 17:57:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/music.h"

void	destroy_music(t_music *const self)
{
	destroy_module(&self->module);
	Mix_FreeMusic(self->music);
}
