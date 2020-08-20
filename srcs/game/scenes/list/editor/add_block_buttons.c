/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_block_buttons.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 23:24:18 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/20 17:46:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/scenes/editor_scene.h"
#include "maths/maths.h"

static void	check_box_position(t_editor_scene *const self,
				t_block_checkbox_entity **buttons, size_t i)
{
	if (i % 6 == 0)
	{
		if (i == 0)
			block_checkbox_set_relative(buttons[i],
				ft_checkbox_position((t_checkbox_entity*)
					self->hud.create_group.show_blocks_ref, BELOW,
				50.0f));
		else
			block_checkbox_set_relative(buttons[i],
				ft_checkbox_position((t_checkbox_entity*)buttons[i - 6],
				BELOW, 50.0f));
	}
	else
		block_checkbox_set_relative(buttons[i],
			ft_checkbox_position((t_checkbox_entity*)buttons[i - 1],
			RIGHT_TO, 50.0f));
}

void		add_block_buttons(t_editor_scene *const self,
				const t_editor_scene_args *const args,
				t_game *const game)
{
	t_block_descriptor		*descriptors;
	size_t					descriptors_size;
	t_block_checkbox_entity	**buttons;
	size_t					buttons_size;
	size_t					i;

	descriptors = (t_block_descriptor*)&game->blocks_list;
	descriptors_size = sizeof(game->blocks_list) / sizeof(*descriptors);
	buttons = (t_block_checkbox_entity**)&self->hud.blocks_group;
	buttons_size = sizeof(self->hud.blocks_group) / sizeof(*buttons);
	i = 0;
	while (i < ft_smin(descriptors_size, buttons_size))
	{
		buttons[i] = create_block_checkbox(
			&self->super.entities, "editor/editor-button.bmp",
			&descriptors[i], args->screen);
		if (buttons[i])
			check_box_position(self, buttons, i);
		i++;
	}
}
