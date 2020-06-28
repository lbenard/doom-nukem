/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_relative.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:48:00 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/28 18:40:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "game/entities/checkbox_entity.h"
#include "ft/str.h"

t_checkbox_entity	*create_checkbox_relative(t_entity_list *const list,
						const char *const name,
						const t_checkbox_position position,
						const t_window *const window)
{
	t_checkbox_entity	*ret;
	t_vec3f				relative_pos;

	ret = (t_checkbox_entity*)entity_list_add_entity(list,
		checkbox_entity_base(name, window));
	if (ret && position.relative)
	{
		relative_pos = position.relative->super.transform.position;
		if (position.side == ON_TOP)
			ret->super.transform.position =
				ft_vec3f(relative_pos.x, relative_pos.y - position.gap, 0.0f);
		if (position.side == RIGHT_TO)
			ret->super.transform.position =
				ft_vec3f(relative_pos.x + position.gap, relative_pos.y, 0.0f);
		if (position.side == BELOW)
			ret->super.transform.position =
				ft_vec3f(relative_pos.x, relative_pos.y + position.gap, 0.0f);
		if (position.side == LEFT_TO)
			ret->super.transform.position =
				ft_vec3f(relative_pos.x - position.gap, relative_pos.y, 0.0f);
	}
	return (ret);
}