/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbox_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 18:23:10 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/28 18:23:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/entities/checkbox_entity.h"

t_checkbox_position	ft_checkbox_position(
						const t_checkbox_entity *const relative,
						const t_checkbox_side side,
						const float gap)
{
	t_checkbox_position	ret;

	ret.relative = relative;
	ret.side = side;
	ret.gap = gap;
	return (ret);
}
