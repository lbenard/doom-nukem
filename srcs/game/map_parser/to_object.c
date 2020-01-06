/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_object.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:20:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 22:25:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"

t_result	to_object(char *data, t_dnon_object *parent)
{
	size_t				i;
	char				**datas;
	t_dnon_object 		*child;

	if (!(datas = split_by_entry(data)))
		return (throw_result_str("to_object", "split failed"));
	i = 0;
	while (datas[i])
	{
		if ((child = create_dnon_object_with_data(get_key_offset(datas[i]))) == NULL)
			return (throw_result_str("to_object", "obj creation failed"));
		 list_add_entry(&child->node, (t_list_head*)parent->value);
		if (child->type == LIST)
			to_object(get_value_offset(datas[i]), child);
		i++;
	}
	free_string_array(datas);
	return (OK);
}