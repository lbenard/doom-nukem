/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 21:24:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/10 21:25:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/sound.h"

t_constructor	sound(const char *const path)
{
	static t_sound_args	args;

	args.path = path;
	return (ft_constructor(init_sound, destroy_sound, sizeof(t_sound), &args));
}