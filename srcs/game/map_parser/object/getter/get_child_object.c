/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_child_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:45:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 22:25:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"

t_dnon_object	*get_child_list_object_by_key(t_dnon_object *tree, char *key)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*child;

	if (tree->type != LIST)
		return (throw_error_str("get_child_list_object_by_key",
			"must provide an object type list"));
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_dnon_object*)pos;
		if (!ft_strcmp(child->key, key) && child->type == LIST)
			return (child);
	}
	return (throw_error_str("get_child_list_object_by_key",
		"do not find the key"));
}

t_dnon_object	*get_child_object_by_key(t_dnon_object *tree, char *key)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*child;

	if (tree->type != LIST)
		return (throw_error_str("get_child_object_by_key",
			"must provide an object type list"));
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_dnon_object*)pos;
		if (!ft_strcmp(child->key, key))
			return (child);
	}
	return (throw_error_str("get_child_object_by_key",
		"do not find the key"));
}