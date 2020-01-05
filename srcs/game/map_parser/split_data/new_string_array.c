/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_string_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:44:57 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 12:30:27 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "engine/error.h"
#include <stdlib.h>

char	**new_string_array(size_t size)
{
	char	**ret;
	size_t	i;

	if (!(ret = (char**)malloc(sizeof(char*) * (size + 1))))
		return (throw_error_str("new_string_array", "malloc failed"));
	i = 0;
	while (i <= size)
	{
		ret[i] = NULL;
		i++;
	}
	return (ret);
}
