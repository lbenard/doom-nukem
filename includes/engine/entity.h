/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:17:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 01:59:21 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "containers/module.h"
# include "maths/transform.h"

/*
** Super-class for any entity object. Every entity contains a transform
** (position + rotation + scale)
*/
typedef struct			s_entity
{
	t_module		module;
	t_transform		transform;
	struct s_entity_vtable
	{
		void	(*update)();
	}				vtable;
}						t_entity;

t_result				init_entity(t_entity *const self,
							const t_transform transform,
							const struct s_entity_vtable vtable);
t_result				init_entity_default(t_entity *const self,
							const struct s_entity_vtable vtable);

struct s_entity_vtable	entity_vtable(void (*update)());

#endif
