/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 07:16:53 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/28 07:39:16 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/noise_test_scene.h"
#include "engine/error.h"

t_result	init_noise_test_scene(t_noise_test_scene *const self)
{
	if (init_scene(&self->super,
		"Noise test",
		noise_test_scene_update,
		noise_test_scene_render) == ERROR)
	{
		return (throw_result_str("init_noise_test_scene()",
			"failed to init scene"));
	}
	return (OK);
}