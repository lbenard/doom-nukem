/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 01:12:05 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 00:26:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor/block_checkbox_entity.h"

t_block_checkbox_entity	*create_block_checkbox(t_entity_list *const list,
							const char *const base_name,
							const t_editor_block_descriptor *const block,
							const t_window *const window)
{
	t_block_checkbox_entity	*ret;

	ret = (t_block_checkbox_entity*)entity_list_add_entity(list,
		block_checkbox_entity(base_name, block, window));
	return (ret);
}
