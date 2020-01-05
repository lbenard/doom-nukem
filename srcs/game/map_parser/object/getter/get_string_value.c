/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:45:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/03 21:15:43 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game/map_parser/parser.h"

char		*get_string_value_by_key(t_json_object *tree, char *key, char *by_default)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_json_object	*child;

	if (tree->type != LIST)
		return (by_default); /// malloc the default value here ?
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_json_object*)pos;
		if (!ft_strcmp(child->key, key) && child->type == STRING)
			return ((char*)child->value);
			// return a duplicata of value ? to avoid free issues
	}
	return (by_default);
}