/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_is_flag_correct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:35:17 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:02:33 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/parsing.h"
#include "engine/error.h"
#include "ft/str.h"

t_result	dn_is_flag_correct(char *line)
{
	if (!line)
		return (throw_result_str("dn_is_flag_correct()", "invalid line"));
	if (!*line)
		return (throw_result_str("dn_is_flag_correct()", "line is blank"));
	line++;
	while (*line)
	{
		if (!ft_isalnum(*line) && *line != '_')
		{
			return (throw_result_str("dn_is_flag_correct()",
				"incorrect snake_case syntax"));
		}
		line++;
	}
	return (OK);
}
