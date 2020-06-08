/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise_test_scene.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 07:09:31 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/28 07:16:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOISE_TEST_SCENE_H
# define NOISE_TEST_SCENE_H

# include "engine/scene.h"
# include "engine/frame.h"

typedef struct	s_noise_test_scene
{
	t_scene	super;
}				t_noise_test_scene;

t_constructor	noise_test_scene(void);

t_result		init_noise_test_scene(t_noise_test_scene *const self);

void			noise_test_scene_update(t_noise_test_scene *const self);
void			noise_test_scene_render(t_noise_test_scene *const self,
					t_frame *const framebuffer);

void			destroy_noise_test_scene(t_noise_test_scene *const self);

#endif