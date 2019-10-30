/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 07:17:53 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TEXTURE_H
# define RENDER_TEXTURE_H

# include <SFML/Graphics.h>
# include "sizes/usize.h"
# include "engine/module.h"

typedef sfRenderTexture	t_render_texture;

typedef struct			s_render_texture_args
{
	t_usize	size;
}						t_render_texture_args;

t_hmodule_factory	render_texture(const t_usize size);

t_render_texture		*new_render_texture(
							const t_render_texture_args *const args);
void					free_render_texture(t_render_texture *const self);

#endif
