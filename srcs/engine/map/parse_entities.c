/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 00:19:55 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/19 21:22:27 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/map.h"
#include "engine/error.h"
#include "engine/parsing.h"
#include "ft/str.h"
#include "maths/maths.h"

static t_map_entity_node	*create_node(const char *const key,
								const t_vec2f pos)
{
	t_map_entity_node	*new_node;

	if (!entity_descriptor_from_name(
		(t_entity_descriptor*)&game_singleton()->entities_list,
		sizeof(game_singleton()->entities_list),
		key))
		return (throw_error_str("create_node()", "failed to find descriptor"));
	if (!(new_node = static_module_allocate(map_entity_node(key, pos))))
		return (throw_error_str("create_node()", "failed to create node"));
	return (new_node);
}

static t_result				add_entity_handle_error(char **entity_values,
								char *message)
{
	dn_free_values(entity_values);
	return (throw_result_str("add_entity()", message));
}

static t_result				add_entity(t_map *const self, char *const p)
{
	char				**entity_values;
	char				*key;
	t_map_entity_node	*new_node;

	if (!(entity_values = dn_get_values(p, ' ')))
		return (throw_result_str("add_entity()", "failed to get values"));
	if (dn_strsplit_length(entity_values) != 2)
		return (add_entity_handle_error(entity_values, "incorrect values"));
	if (!(key = dn_get_key(p)))
		return (add_entity_handle_error(entity_values, "failed to get key"));
	if (!(new_node = create_node(key,
		ft_vec2f(ft_atof(entity_values[0]), ft_atof(entity_values[1])))))
	{
		dn_free_values(entity_values);
		free(key);
		return (throw_result_str("add_entity()", "failed to create node"));
	}
	list_add_entry(&new_node->node, &self->entities);
	dn_free_values(entity_values);
	return (OK);
}

t_result					map_parse_entities(t_map *const self,
								char *entities_flag_str)
{
	char	*p;

	if (!entities_flag_str)
	{
		return (throw_result_str("map_parse_size()",
			"invalid size flag string"));
	}
	init_list_head(&self->entities);
	p = entities_flag_str;
	while ((p = ft_skipchr(p, '\n')) && *p)
	{
		if (add_entity(self, p) == ERROR)
		{
			free_entity_list(&self->entities);
			free(entities_flag_str);
			return (throw_result_str("map_parse_entities()",
				"failed to add entity"));
		}
		p = ft_nextline(p);
	}
	free(entities_flag_str);
	return (OK);
}
