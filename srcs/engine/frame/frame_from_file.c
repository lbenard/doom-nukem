/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_from_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 09:04:31 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/26 22:21:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/frame.h"

t_constructor	frame_from_file(const char *const path)
{
	static t_frame_args		args;

	args.path = path;
	return (ft_constructor(init_frame_from_file,
		destroy_frame,
		sizeof(t_frame),
		&args));
}
