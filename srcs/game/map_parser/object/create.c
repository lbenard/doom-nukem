/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:33:22 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 12:16:50 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game/map_parser/parser.h"
#include "engine/error.h"
#include <stdlib.h>

t_json_object	*new_json_object()
{
	t_json_object	*ret;

	if (!(ret = (t_json_object*)malloc(sizeof(t_json_object))))
		return (throw_error_str("new_json_object", "malloc failed"));
	init_list_head(&ret->node);
	return (ret);
}

t_json_object	*create_json_object(char *key, t_json_value_type type)
{
	t_json_object	*ret;

	if (!(ret = new_json_object()))
		return (throw_error_str("create_json_object", "obj creation failed"));
	ret->key = key;
	ret->type = type;
	if (type == LIST)
	{
		if (!(ret->value = (t_list_head*)malloc(sizeof(t_list_head))))
			return (throw_error_str("create_json_object", "malloc failed")); 
		init_list_head((t_list_head*)ret->value);
	}
	return (ret);
}

t_json_object	*create_json_object_with_data(char *data)
{
	t_json_object	*object;

	if (data == NULL)
		return (throw_error_str("create_json_object_with_data", "data is null"));
	if ((object = new_json_object()) == NULL)
		return (throw_error_str("create_json_object_with_data", "obj creation failed"));
	if ((object->key = get_object_key(data)) == NULL)
		return (throw_error_str("create_json_object_with_data", "failed to find key"));
	if ((object->type = get_object_value_type(data)) == UNKNOW)
		return (throw_error_str("create_json_object_with_data", "failed to find type"));
	if (object->type == LIST)
	{
		if (!(object->value = (t_list_head*)malloc(sizeof(t_list_head))))
			return (throw_error_str("object_with_data", "malloc failed"));
		init_list_head((t_list_head*)object->value);
	}
	else
		object->value = get_object_value(data, object->type);
	return (object);
}