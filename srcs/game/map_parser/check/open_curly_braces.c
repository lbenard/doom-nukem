/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_curly_braces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppetitea <ppetitea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 12:57:40 by ppetitea          #+#    #+#             */
/*   Updated: 2020/01/05 12:09:42 by ppetitea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "engine/error.h"
#include "game/map_parser/parser.h"

t_result	check_open_curly_brace_left_side(char *data, size_t index)
{
	size_t	i;

	if (index < 3 || data[index - 1] != ':' || data[index - 2] != '"')
		return (throw_result_str("check_open_curly_brace_left_side",
			"cannot find \": before {"));
	i = index - 3;
	while (i > 0 && data[i] != '"')
	{
		if (!ft_isalpha(data[i]) && !ft_isdigit(data[i]) &&
			data[i] != '_')
			return (throw_result_str("check_open_curly_brace_left_side",
				"bad key format before {"));
		i--;
	}
	if (data[i] != '"')
		return (throw_result_str("check_open_curly_brace_left_side",
			"cannot find \": before {"));
	return (OK);
}

t_result	check_open_curly_brace_right_side(char *data, size_t index)
{
	size_t	i;

	i = index + 1;
	if (is_index_match_to_object_key(data, i) == TRUE)
		return (OK);
	else
		return (throw_result_str("check_open_curly_brace_right_side",
			"cannot find key after {"));
}
