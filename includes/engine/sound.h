/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 21:13:41 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 21:28:54 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_H
# define SOUND_H

# include "containers/module.h"
# include "SFML/Audio.h"

typedef struct	s_sound
{
	t_module		module;
	sfSoundBuffer	*sound_buffer;
	sfSound			*sound;
}				t_sound;

typedef struct	s_sound_args
{
	const char	*path;
}				t_sound_args;

t_constructor	sound(const char *const path);

t_result		init_sound(t_sound *const self, const t_sound_args *const args);

void			sound_play(t_sound *const self);

void			destroy_sound(t_sound *const self);

#endif