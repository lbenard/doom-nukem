/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 07:36:41 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/28 07:37:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/noise_test_scene.h"

void	destroy_noise_test_scene(t_noise_test_scene *const self)
{
	destroy_scene(&self->super);
}
