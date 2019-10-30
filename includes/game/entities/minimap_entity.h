/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_entity.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:16:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 22:22:34 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_ENTITY_H
# define MINIMAP_ENTITY_H

# include "engine/classic_entity.h"
# include "sizes/usize.h"
# include "engine/raycasting.h"
# include "engine/frame.h"

/*
** Sizable minimap entity. Uses raycasting informations
*/
typedef struct		s_minimap_entity
{
	t_classic_entity	super;
	t_usize				size;
	const t_raycasting	*raycasting_ref;
	t_frame				minimap;
}					t_minimap_entity;

typedef struct		s_minimap_entity_args
{
	const t_raycasting	*renderer;
	t_usize				max_size;
}					t_minimap_entity_args;

t_hmodule_factory	minimap_entity(const t_raycasting *renderer,
						const t_usize max_size);

t_minimap_entity	*new_minimap_entity(
						const t_minimap_entity_args *const args);

void				minimap_entity_update(t_minimap_entity *const self);
void				minimap_entity_render(t_minimap_entity *const self,
						t_frame *const frame);

void				free_minimap_entity(t_minimap_entity *const self);

#endif
