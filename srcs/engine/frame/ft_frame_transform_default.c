/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame_transform_default.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:12:50 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:41:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

t_frame_transform	ft_frame_transform_default(void)
{
	t_frame_transform	ret;

	ret.anchor = ft_vec2f(0.5f, 0.5f);
	ret.position = ft_isize(0, 0);
	ret.scale = ft_vec2f(1.0f, 1.0f);
	ret.opacity = COLOR_OPAQUE;
	return (ret);
}
