/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:56:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 19:16:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/error.h"
#include "engine/render_texture.h"

t_render_texture	*new_render_texture(const t_render_texture_args *const args)
{
	t_render_texture	*ret;

	if (!(ret = sfRenderTexture_create(args->size.x, args->size.y, 0)))
	{
		return (throw_error_str("new_render_texture()",
			"failed to create new render texture"));
	}
	return (ret);
}
