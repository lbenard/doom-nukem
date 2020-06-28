/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:57:28 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:44:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

t_frame_coordinates	coordinates(const t_frame *const frame,
						const t_frame_transform transform)
{
	t_frame_coordinates	ret;

	ret.start.x = transform.position.x
		+ (frame->size.x * transform.scale.x * (0.0f - transform.anchor.x));
	ret.start.y = transform.position.y
		+ (frame->size.y * transform.scale.y * (0.0f - transform.anchor.y));
	ret.end.x = ret.start.x + frame->size.x * transform.scale.x;
	ret.end.y = ret.start.y + frame->size.y * transform.scale.y;
	return (ret);
}
