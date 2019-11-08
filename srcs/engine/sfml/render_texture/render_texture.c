/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:52:00 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 05:09:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render_texture.h"

t_constructor	render_texture(const t_usize size)
{
	static t_render_texture_args	args;

	args.size = size;
	return (ft_constructor(init_render_texture,
		destroy_render_texture,
		sizeof(t_render_texture),
		&args));
}
