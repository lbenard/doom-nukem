/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   music.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:24:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 17:56:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/music.h"

t_constructor	music(const char *path)
{
	static t_music_args	args;

	args.path = path;
	return (ft_constructor(init_music, destroy_music, sizeof(t_music), &args));
}
