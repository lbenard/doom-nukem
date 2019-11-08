/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classic_entity.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:17:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:38:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSIC_ENTITY_H
# define CLASSIC_ENTITY_H

# include "containers/module.h"
# include "maths/transform.h"

/*
** Super-class for any entity object. Every entity contains a transform
** (position + rotation + scale)
*/
typedef struct	s_classic_entity
{
	t_module		module;
	t_transform		transform;
	void			(*update_fn)();
}				t_classic_entity;

t_result		init_classic_entity(t_classic_entity *const self,
					const t_transform transform,
					void (*update_fn)());
t_result		init_classic_entity_default(t_classic_entity *const self,
					void (*update_fn)());

#endif
