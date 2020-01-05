/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 00:36:12 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 12:23:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"

char	*get_object_key(char *data)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	while (data[i] && ft_isspace(data[i]))
		i++;
	if (data[i] != '"')
		return (NULL);
	i++;
	j = 0;
	while (data[i + j] && (data[i + j] != '"' || data[i + j + 1] != ':'))
	{
		if (!ft_isalpha(data[i + j]) && !ft_isdigit(data[i + j]) &&
			data[i + j] != '_')
			return (NULL);
		j++;
	}
	if (!(ret = ft_strndup(&data[i], j)))
		return(throw_error_str("get_object_key", "ft_strndup failed"));
	return (ret);
}
