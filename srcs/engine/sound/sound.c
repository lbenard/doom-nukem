/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 17:24:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/12 17:35:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sound.h"

t_constructor	sound(const char *path)
{
	static t_sound_args	args;

	args.path = path;
	return (ft_constructor(init_sound, destroy_sound, sizeof(t_sound), &args));
}
