/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:02:59 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/07 15:08:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include "containers/module.h"
# include "sizes/usize.h"
# include "sizes/isize.h"
# include "engine/array.h"
# include "engine/render_texture.h"
# include "engine/sprite.h"
# include "colors/rgba.h"
# include "engine/blend.h"

/*
** Rendering frame with alpha channel
*/
typedef struct	s_frame
{
	t_module			module;
	t_usize				size;
	t_array				frame;
	t_render_texture	render_texture;
	t_sprite			sprite;
}				t_frame;

typedef struct	s_frame_args
{
	t_usize		size;
	t_rgba		fill_color;
	const char	*path;
}				t_frame_args;

t_constructor	frame(const t_usize size, const t_rgba fill_color);
t_constructor	frame_from_file(const char *const path);

t_result		init_frame(t_frame *const self,
					const t_frame_args *const args);
t_result		init_frame_from_file(t_frame *const self,
					const t_frame_args *const args);

void			frame_update(t_frame *const self);
void			frame_clear(t_frame *const self);
void			frame_fill(t_frame *const self,
					const t_rgba fill_color);
void			frame_layer(t_frame *const self,
					t_frame *const layer,
					const t_isize pos,
					t_u32 (*const blend)(const t_rgba *const back,
						const t_rgba *const front));

void			destroy_frame(t_frame *const self);

#endif
