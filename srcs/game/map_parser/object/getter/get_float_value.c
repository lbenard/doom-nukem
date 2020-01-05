/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_float_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:45:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/04 16:11:16 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game/map_parser/parser.h"

float		get_float_value_by_key(t_json_object *tree, char *key, float by_default)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_json_object	*child;

	if (tree->type != LIST)
		return (by_default);
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_json_object*)pos;
		if (!ft_strcmp(child->key, key) && child->type == NUMBER)
			return (*(float*)child->value);
	}
	return (by_default);
}