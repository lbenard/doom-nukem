/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_selected.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 23:07:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/19 23:07:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/editor_vertex_component_entity.h"

t_bool	editor_vertex_component_entity_is_selected(
			t_editor_component_entity *const self,
			const t_isize cursor_pos)
{
	(void)self;
	(void)cursor_pos;
	return (FALSE);
}
