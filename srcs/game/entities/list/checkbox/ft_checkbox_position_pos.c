/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbox_position_pos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:24:01 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/28 18:24:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

t_checkbox_position	ft_checkbox_position_pos(const t_vec3f relative_pos)
{
	t_checkbox_position	ret;

	ret.relative_pos = relative_pos;
	return (ret);
}
