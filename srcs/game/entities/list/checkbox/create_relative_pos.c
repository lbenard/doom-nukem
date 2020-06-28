/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_relative_pos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:18:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/28 18:42:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/checkbox_entity.h"
#include "ft/str.h"

t_checkbox_entity	*create_checkbox_relative_pos(t_entity_list *const list,
						const char *const name,
						const t_checkbox_position position,
						const t_window *const window)
{
	t_checkbox_entity	*ret;

	ret = (t_checkbox_entity*)entity_list_add_entity(list,
		checkbox_entity_base(name, window));
	if (ret)
		ret->super.transform.position =
			ft_vec3f(position.relative_pos.x, position.relative_pos.y, 0.0f);
	return (ret);
}