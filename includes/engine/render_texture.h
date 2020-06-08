/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_texture.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 07:17:53 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/04 22:21:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TEXTURE_H
# define RENDER_TEXTURE_H

# include <SFML/Graphics.h>
# include "sizes/usize.h"
# include "containers/module.h"

typedef struct	s_render_texture
{
	t_module		module;
	sfRenderTexture	*texture;
	t_usize			size;
}				t_render_texture;

typedef struct	s_render_texture_args
{
	t_usize	size;
}				t_render_texture_args;

t_constructor	render_texture(const t_usize size);

t_result		init_render_texture(t_render_texture *const self,
					const t_render_texture_args *const args);
void			destroy_render_texture(t_render_texture *const self);

#endif
