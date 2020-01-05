/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_curly_braces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:57:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 12:52:40 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"

t_result	check_close_curly_brace_left_side(char *data, size_t index)
{
	size_t	i;

	i = index - 1;
	while (i > 0 && ft_isspace(data[i]))
		i--;
	if (data[i] != '}' && data[i] != '"' && !ft_isdigit(data[i]))
		return (throw_result_str("check_close_curly_brace_left_side",
			"wrong data before }"));
	return (OK);
}

t_result	check_close_curly_brace_right_side(char *data, size_t index)
{
	size_t	i;
	
	i = index + 1;
	if (data[i] == ',')
	{
		if (is_index_match_to_object_key(data, i + 1) == TRUE)
			return (OK);
		return (throw_result_str("check_close_curly_brace_right_side",
			"cannot detect key after },"));
	}
	while (data[i] && ft_isspace(data[i]))
		i++;
	if (data[i] == '}' || !data[i])
		return (OK);
	return (throw_result_str("check_close_curly_brace_right_side",
		"wrong data after }"));
}
