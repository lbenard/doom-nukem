/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 20:37:33 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/18 20:38:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_camera_entity.h"

void	destroy_editor_camera_entity(t_editor_camera_entity *const self)
{
	destroy_module(&self->super.module);
}