/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_radio_groups.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:05:20 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/16 23:40:21 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"

void	init_radio_groups(t_editor_scene *const self)
{
	init_radio_group(&self->hud.tools,
		(t_checkbox_entity**const)&self->hud.tools_group,
		sizeof(self->hud.tools_group) / sizeof(t_checkbox_entity*), 0);
	init_radio_group(&self->hud.create,
		(t_checkbox_entity**const)&self->hud.create_group,
		sizeof(self->hud.create_group) / sizeof(t_checkbox_entity*), 0);
	init_radio_group(&self->hud.blocks,
		(t_checkbox_entity**const)&self->hud.blocks_group,
		sizeof(self->hud.blocks_group) / sizeof(t_checkbox_entity*), 0);
	init_radio_group(&self->hud.entities,
		(t_checkbox_entity**const)&self->hud.entities_group,
		sizeof(self->hud.entities_group) / sizeof(t_checkbox_entity*), 0);
}
