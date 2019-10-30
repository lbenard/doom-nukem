/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_get_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:12:44 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:02:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/parsing.h"
#include "engine/error.h"
#include "ft/str.h"

char	*dn_get_value(char *kv_line)
{
	if (!dn_is_kv_correct(kv_line, '\n'))
		return (throw_error_str("dn_get_value()", "incorrect kv_line"));
	return (ft_strndup(
		ft_strstr(kv_line, ":") + 2,
		ft_strstr(kv_line, "\n") - (ft_strstr(kv_line, ": ") + 2)));
}
