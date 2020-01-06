/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 20:45:31 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 22:25:47 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game/map_parser/parser.h"

int		get_int_value_by_key(t_dnon_object *tree, char *key, int by_default)
{
	t_list_head		*pos;
	t_list_head		*next;
	t_dnon_object	*child;

	if (tree->type != LIST)
		return (by_default);
	pos = (t_list_head*)tree->value;
	next = pos->next;
	while ((pos = next) != (t_list_head*)tree->value)
	{
		next = next->next;
		child = (t_dnon_object*)pos;
		if (!ft_strcmp(child->key, key) && child->type == NUMBER)
			return ((int)(*(float*)child->value));
	}
	return (by_default);
}