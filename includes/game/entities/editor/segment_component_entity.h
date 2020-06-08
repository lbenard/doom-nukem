/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_component_entity.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 22:32:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/01/07 22:46:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEGMENT_COMPONENT_ENTITY_H
# define SEGMENT_COMPONENT_ENTITY_H

# include "game/entities/component_entity.h"
# include "game/entities/vertex_component_entity.h"

typedef struct	s_segment_vertices
{
	t_vertex_component_entity	*a;
	t_vertex_component_entity	*b;
	t_segment					positions;
}				t_segment_vertices;

typedef struct	s_segment_sectors
{
	void	*a;
	void	*b;
}				t_segment_sectors;

typedef struct	s_segment_component_entity
{
	t_component_entity	super;
	t_segment_vertices	vertices;
	t_segment_sectors	sectors;
	t_bool				is_portal;
	t_shape				shape;
}				t_segment_component_entity;

#endif