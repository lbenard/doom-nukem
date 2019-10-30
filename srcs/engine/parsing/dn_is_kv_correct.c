/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_is_kv_correct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:55:06 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:02:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/parsing.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	dn_is_kv_correct(char *line, char end)
{
	if (!line)
		return (throw_result_str("dn_is_kv_correct()", "invalid line"));
	if (!*line)
		return (throw_result_str("dn_is_kv_correct()", "line is blank"));
	while (*line && *line != ':' && *line != end)
	{
		if (!ft_isalnum(*line) && *line != '_')
		{
			return (throw_result_str("dn_is_kv_correct()",
				"incorrect snake_case key syntax"));
		}
		line++;
	}
	if (*line != ':')
		return (throw_result_str("dn_is_kv_correct()", "missing colon"));
	if (line[1] != ' ')
	{
		return (throw_result_str("dn_is_kv_correct()",
			"missing space after colon"));
	}
	return (OK);
}
