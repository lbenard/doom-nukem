/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame_transform_position.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:15:39 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/15 17:45:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

t_frame_transform	ft_frame_transform_position(const t_isize position)
{
	t_frame_transform	ret;

	ret.anchor = ft_vec2f(0.5f, 0.5f);
	ret.position = position;
	ret.scale = ft_vec2f(1.0f, 1.0f);
	ret.opacity = COLOR_OPAQUE;
	return (ret);
}