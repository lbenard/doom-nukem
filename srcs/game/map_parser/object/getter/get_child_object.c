/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_child_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:45:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 11:53:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"

t_json_object	*get_child_list_object_by_key(t_json_object *tree, char *key)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_json_object	*child;

	if (tree->type != LIST)
		return (throw_error_str("get_child_list_object_by_key",
			"must provide an object type list"));
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_json_object*)pos;
		if (!ft_strcmp(child->key, key) && child->type == LIST)
			return (child);
	}
	return (throw_error_str("get_child_list_object_by_key",
		"do not find the key"));
}

t_json_object	*get_child_object_by_key(t_json_object *tree, char *key)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_json_object	*child;

	if (tree->type != LIST)
		return (throw_error_str("get_child_object_by_key",
			"must provide an object type list"));
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_json_object*)pos;
		if (!ft_strcmp(child->key, key))
			return (child);
	}
	return (throw_error_str("get_child_object_by_key",
		"do not find the key"));
}