/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 17:02:59 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 02:09:42 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

# include "containers/module.h"
# include "sizes/usize.h"
# include "sizes/isize.h"
# include "maths/vec2f.h"
# include "engine/array.h"
# include "engine/render_texture.h"
# include "engine/sprite.h"
# include "colors/rgba.h"
# include "engine/blend.h"

/*
** Rendering frame with alpha channel
*/
typedef struct		s_frame
{
	t_module			module;
	t_usize				size;
	t_array				frame;
	t_rgba				*pixels;
	t_render_texture	render_texture;
	t_sprite			sprite;
}					t_frame;

typedef struct		s_frame_args
{
	t_usize		size;
	t_rgba		fill_color;
	const char	*path;
}					t_frame_args;

t_constructor		frame(const t_usize size, const t_rgba fill_color);
t_constructor		frame_from_file(const char *const path);
t_constructor		frame_from_bmp(const char *const path);

t_result			init_frame(t_frame *const self,
						const t_frame_args *const args);
t_result			init_frame_from_file(t_frame *const self,
						const t_frame_args *const args);
t_result			init_frame_from_bmp(t_frame *const self,
						const t_frame_args *const args);

void				frame_update(t_frame *const self);
void				frame_clear(t_frame *const self);
void				frame_fill(t_frame *const self,
						const t_rgba fill_color);
void				frame_fill_blend(t_frame *const self,
						const t_rgba fill_color,
						t_rgba (*const blend)(const t_rgba back,
							const t_rgba front));
void				frame_layer(t_frame *const self,
						const t_frame *const layer,
						const t_isize pos,
						t_rgba (*const blend)(const t_rgba back,
							const t_rgba front));
void				frame_layer_opaque(t_frame *const self,
						const t_frame *const layer,
						const t_isize pos);
/*
** Transform-related layer functions
*/
typedef struct		s_frame_transform
{
	t_vec2f	anchor;
	t_isize	position;
	t_vec2f	scale;
	t_u8	opacity;
}					t_frame_transform;

typedef struct		s_frame_coordinates
{
	t_isize	start;
	t_isize	end;
}					t_frame_coordinates;

t_frame_coordinates	coordinates(const t_frame *const frame,
						const t_frame_transform transform);

t_frame_transform	ft_frame_transform_default(void);
t_frame_transform	ft_frame_transform_position(const t_isize position);
t_frame_transform	ft_frame_transform(const t_vec2f anchor,
						const t_isize position,
						const t_vec2f scale,
						const t_u8 opacity);

void				frame_layer_transform(t_frame *const self,
						const t_frame *const layer,
						const t_frame_transform transform,
						t_rgba (*const blend)(const t_rgba back,
							const t_rgba front));

void				destroy_frame(t_frame *const self);

#endif
