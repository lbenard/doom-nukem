/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:32:57 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/23 19:12:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/new_editor_scene.h"

void	destroy_new_editor_scene(t_new_editor_scene *const self)
{
	destroy_scene(&self->super);
}