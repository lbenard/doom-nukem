/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_segment_component_entity.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:32:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/05 22:43:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_SEGMENT_COMPONENT_ENTITY_H
# define EDITOR_SEGMENT_COMPONENT_ENTITY_H

# include "game/entities/editor_component_entity.h"
# include "game/entities/editor_vertex_component_entity.h"

typedef struct	s_segment_vertices
{
	t_editor_vertex_component_entity	*a;
	t_editor_vertex_component_entity	*b;
	t_segment							positions;
}				t_segment_vertices;

typedef struct	s_segment_sectors
{
	void	*a;
	void	*b;
}				t_segment_sectors;

typedef struct	s_editor_segment_component_entity
{
	t_editor_component_entity	super;
	t_segment_vertices			vertices;
	t_segment_sectors			sectors;
	t_bool						is_portal;
	t_shape						shape;
}				t_editor_segment_component_entity;



#endif