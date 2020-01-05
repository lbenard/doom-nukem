/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 00:40:03 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 12:23:32 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"

char		*get_value_offset(char *data)
{
	size_t	i;

	i = 0;
	while (data[i] && data[i] != ':')
		i++;
	while (data[i] && data[i] != '"')
		i++;
	return (!data[i] ? NULL : &data[i]);
}

char		*get_key_offset(char *data)
{
	size_t	i;

	i = 0;
	while (data[i] && data[i] != '"')
		i++;
	return (!data[i] ? NULL : &data[i]);
}
