/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:31:45 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:21:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_ENTITY_H
# define IMAGE_ENTITY_H

# include "engine/classic_entity.h"
# include "engine/frame.h"
# include "engine/module.h"

/*
** A frame represented as an entity.
*/
typedef struct		s_image_entity
{
	t_classic_entity	super;
	t_frame				image;
}					t_image_entity;

typedef struct		s_image_entity_args
{
	const char *path;
}					t_image_entity_args;

t_hmodule_factory	image_entity_from_file(const char *const path);

t_image_entity		*new_image_entity_from_file(
						const t_image_entity_args *const args);

void				image_entity_update(t_image_entity *const self);
void				image_entity_render(t_image_entity *const self,
						t_frame	*const frame);

void				free_image_entity(t_image_entity *const self);

#endif
