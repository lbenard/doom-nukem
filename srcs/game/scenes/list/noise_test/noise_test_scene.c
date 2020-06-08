/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise_test_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 07:15:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/28 07:16:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/noise_test_scene.h"

t_constructor	noise_test_scene(void)
{
	return (ft_constructor(init_noise_test_scene,
		destroy_noise_test_scene,
		sizeof(t_noise_test_scene),
		NULL));
}