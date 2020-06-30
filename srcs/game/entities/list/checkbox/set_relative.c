/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_relative.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 01:06:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/29 01:07:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

void	checkbox_set_relative(t_checkbox_entity *const self,
			const t_checkbox_position position)
{
	t_vec3f	relative_pos;

	relative_pos = position.relative->super.transform.position;
	if (position.side == ON_TOP)
		self->super.transform.position =
			ft_vec3f(relative_pos.x, relative_pos.y - position.gap, 0.0f);
	if (position.side == RIGHT_TO)
		self->super.transform.position =
			ft_vec3f(relative_pos.x + position.gap, relative_pos.y, 0.0f);
	if (position.side == BELOW)
		self->super.transform.position =
			ft_vec3f(relative_pos.x, relative_pos.y + position.gap, 0.0f);
	if (position.side == LEFT_TO)
		self->super.transform.position =
			ft_vec3f(relative_pos.x - position.gap, relative_pos.y, 0.0f);
}
