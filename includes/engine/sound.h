/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:21:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 17:24:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_H
# define SOUND_H

# include <SDL_mixer.h>
# include "containers/module.h"

typedef struct	s_sound
{
	t_module	module;
	Mix_Chunk	*sound;
}				t_sound;

typedef struct	s_sound_args
{
	const char	*path;
}				t_sound_args;

t_constructor	sound(const char *path);

t_result		init_sound(t_sound *const self, t_sound_args *const args);

void			sound_play(t_sound *const self);

void			destroy_sound(t_sound *const self);

#endif
