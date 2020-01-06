/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:20:50 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 22:25:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"
#include <stdio.h>

void	debug_split(char **datas)
{
	size_t	i;

	i = 0;
	while (datas[i])
	{
		printf("%s", datas[i]);
		i++;
	}
}

void		debug_object(t_dnon_object *obj)
{
	static int	deep = 0;

	for (int i = 0; i < deep; i++)
		printf("  ");
	if (obj->type == STRING)
		printf("\"%s\": \"%s\",\n", obj->key, (char*)obj->value);
	else if (obj->type == NUMBER && obj->value != NULL)
		printf("\"%s\": %f,\n", obj->key, *((float*)obj->value));
	else if (obj->type == LIST)
	{
		printf("\"%s\": {\n", obj->key);
		deep++;
		list_foreach((t_list_head*)obj->value, 0, debug_object);
		deep--;
		for (int i = 0; i < deep; i++)
			printf("  ");
		printf("}\n");
	}
}
