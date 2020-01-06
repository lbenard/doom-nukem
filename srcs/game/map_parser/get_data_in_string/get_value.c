/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 00:36:12 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 22:25:31 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"
#include <stdlib.h>

static char		*data_to_string_value(char *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (data[i] != '"')
		return (NULL);
	i++;
	j = 0;
	while (data[i + j] && data[i + j] != '"')
	{
		if (data[i + j] == '{' || data[i + j] == '}')
			return (throw_error_str("data_to_string_value",
				"value must not contain curly braces")); 
		j++;
	}
	if (data[i + j] != '"' || data[i + j + 1])
		return (throw_error_str("data_to_string_value",
		"wrong end string value detected")); 
	return (ft_strndup(&data[i], j));
}

static float		*data_to_float_value(char *data)
{
	float	*ret;
	size_t	i;
	t_bool	point;

	point = FALSE;
	i = data[0] == '-' ? 1 : 0;
	while (data[i])
	{
		if (!ft_isdigit(data[i]) && (data[i] != '.' || point == TRUE))
			return (throw_error_str("data_to_float_value",
				"number has wrong format"));
		if (data[i] == '.')
			point = TRUE;
		i++;
	}
	if (!(ret = (float*)malloc(sizeof(float))))
		return (throw_error_str("data_to_float_value", "malloc failed"));
	*ret = ft_atof(data);
	return (ret);
}

void		*get_object_value(char *data, t_dnon_value_type type)
{
	size_t	i;

	i = 0;
	while (data[i] && data[i] != ':')
		i++;
	i++;
	if (type == STRING)
		return (data_to_string_value(&data[i]));
	else if (type == NUMBER)
		return (data_to_float_value(&data[i]));
	else
		return (throw_error_str("get_object_value", "wrong type detected"));
}