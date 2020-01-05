/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_string_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:44:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 12:55:00 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"
#include <stdlib.h>

void	free_string_array(char **datas)
{
	size_t	i;

	if (!datas)
		return;
	i = 0;
	while (datas[i])
	{
		free(datas[i]);
		datas[i] = NULL;
		i++;
	}
	free(datas);
}