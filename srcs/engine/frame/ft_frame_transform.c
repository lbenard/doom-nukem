/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame_transform.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:17:38 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/15 17:45:28 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

t_frame_transform	ft_frame_transform(const t_vec2f anchor,
						const t_isize position,
						const t_vec2f scale,
						const t_u8 opacity)
{
	t_frame_transform	ret;

	ret.anchor = anchor;
	ret.position = position;
	ret.scale = scale;
	ret.opacity = opacity;
	return (ret);
}
