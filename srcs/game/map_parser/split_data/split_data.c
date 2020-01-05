/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:44:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 12:54:49 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"
#include <stdlib.h>

static size_t	get_index_of_next_entry(char *data)
{
	size_t		i;
	size_t		deep;

	deep = 0;
	i = 0;
	while (data[i])
	{
		if (data[i] == '{')
			deep++;
		if (data[i] == '}')
			deep--;
		if (i && !deep && (data[i] == ','))
			break;
		i++;
	}
	return (data[i] ? i + 1 : i);
}

static size_t	get_object_amount(char *data)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	while (data[i])
	{
		i += get_index_of_next_entry(&data[i]);
		ret++;
	}
	return (ret);
}

static size_t	get_end_value_offset(char *data)
{
	size_t		i;
	size_t		deep;

	deep = 0;
	i = 0;
	while (data[i])
	{
		if (data[i] == '{')
			deep++;
		if (data[i] == '}')
			deep--;
		if (i && !deep && (data[i] == ',' || data[i] == '\n'))
			break;
		i++;
	}
	return (i);
}

char	**split_by_entry(char *data)
{
	char	**ret;
	size_t	size;
	size_t	i;
	size_t	j;
	size_t	k;

	size = get_object_amount(data);
	ret = new_string_array(size);
	k = 0;
	i = 0;
	while (data[i])
	{
		j = get_index_of_next_entry(&data[i]);
		if (!(ret[k++] = ft_strndup(&data[i],
			get_end_value_offset(&data[i]))))
		{
			free_string_array(ret);
			return (throw_error_str("split_by_entry", "malloc failed"));
		}
		i += j;
	}
	return (ret);
}