/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:27:22 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:54:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

t_constructor	frame(const t_usize size, const t_rgba fill_color)
{
	static t_frame_args	args;

	args.size = size;
	args.fill_color = fill_color;
	return (ft_constructor(init_frame, destroy_frame, sizeof(t_frame), &args));
}
