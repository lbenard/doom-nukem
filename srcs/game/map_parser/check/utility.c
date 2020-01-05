/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 11:58:23 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 12:52:47 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_index_match_to_object_key(char *data, size_t index)
{
	size_t	i;

	i = index;
	while (data[i] && ft_isspace(data[i]))
		i++;
	if (data[i] != '"')
		return (FALSE);
	i++;
	while (data[i] && data[i] != '"' && data[i + 1] != ':')
	{
		if (!ft_isalpha(data[i]) && !ft_isdigit(data[i]) &&
			data[i] != '_')
			return (FALSE);
		i++;
	}
	if (data[i] != '"')
		return (FALSE);
	return (TRUE);
}