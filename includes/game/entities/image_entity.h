/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:31:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/18 18:58:22 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_ENTITY_H
# define IMAGE_ENTITY_H

# include "engine/entity.h"
# include "engine/frame.h"
# include "containers/module.h"

/*
** A frame represented as an entity.
*/
typedef struct	s_image_entity
{
	t_entity			super;
	t_frame				image;
	t_frame_transform	transform;
}				t_image_entity;

typedef struct	s_image_entity_args
{
	const char			*path;
	t_frame_transform	transform;
	t_usize				size;
}				t_image_entity_args;

t_constructor	image_entity_from_file(const char *const path,
					const t_frame_transform transform);
t_constructor	image_entity_size(const t_usize size);

t_result		init_image_entity_from_file(t_image_entity *const self,
					const t_image_entity_args *const args);
t_result		init_image_entity_size(t_image_entity *const self,
					const t_image_entity_args *const args);

void			image_entity_update(t_image_entity *const self);
void			image_entity_render(t_image_entity *const self,
					t_frame	*const frame);

void			destroy_image_entity(t_image_entity *const self);

#endif
