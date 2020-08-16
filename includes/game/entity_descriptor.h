/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_descriptor.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:34:36 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 21:21:45 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_DESCRIPTOR_H
# define ENTITY_DESCRIPTOR_H

# include "containers/module.h"
# include "engine/frame.h"
# include "engine/scene.h"

typedef t_constructor	(*t_constructor_fn)(t_scene *const, const t_vec2f);

typedef struct			s_entity_descriptor
{
	t_module			module;
	const char			*name;
	const char			*icon_path;
	t_frame				icon;
	t_constructor_fn	constructor_fn;
}						t_entity_descriptor;

typedef struct			s_entity_descriptor_args
{
	const char			*name;
	const char			*icon_path;
	t_constructor_fn	constructor_fn;
}						t_entity_descriptor_args;

t_constructor			entity_descriptor(const char *const name,
							const char *const icon_path,
							const t_constructor_fn constructor_fn);

t_result				init_entity_descriptor(t_entity_descriptor *const self,
							t_entity_descriptor_args *const args);

t_entity_descriptor		*entity_descriptor_from_name(
							t_entity_descriptor *const descriptors,
							const size_t amount,
							const char *const name);

void					destroy_entity_descriptor(
							t_entity_descriptor *const self);

#endif
