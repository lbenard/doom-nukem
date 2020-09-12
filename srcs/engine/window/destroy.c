/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 00:27:51 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 18:04:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL_mixer.h>
#include "engine/window.h"

void	destroy_window(t_window *const self)
{
	destroy_module(&self->module);
	SDL_DestroyWindow(self->window);
	Mix_CloseAudio();
	Mix_Quit();
	SDL_VideoQuit();
	SDL_AudioQuit();
	SDL_Quit();
}
