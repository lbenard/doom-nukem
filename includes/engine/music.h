/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:21:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 18:57:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUSIC_H
# define MUSIC_H

# include <SDL_mixer.h>
# include "containers/module.h"

typedef struct	s_music
{
	t_module	module;
	Mix_Music	*music;
}				t_music;

typedef struct	s_music_args
{
	const char	*path;
}				t_music_args;

t_constructor	music(const char *path);

t_result		init_music(t_music *const self, t_music_args *const args);

void			music_play(t_music *const self);

void			destroy_music(t_music *const self);

#endif
