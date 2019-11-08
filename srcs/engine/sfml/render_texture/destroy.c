/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:58:16 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 05:11:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render_texture.h"

void	destroy_render_texture(t_render_texture *const self)
{
	sfRenderTexture_destroy(self->texture);
}
