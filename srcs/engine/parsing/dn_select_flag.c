/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_select_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:19:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:03:03 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/parsing.h"
#include "engine/error.h"
#include "ft/str.h"

char	*dn_select_flag(char *map_str, char *flag_name)
{
	char	*flag_start;
	char	*flag_end;
	char	*flag;
	char	*ret;

	if (!(flag = dn_new_flag(flag_name)))
	{
		return (throw_error_str("dn_select_flag()",
			"failed to create new flag"));
	}
	if (!(flag_start = ft_strstr(map_str, flag)))
	{
		free(flag);
		return (throw_error_str("dn_select_flag()", "cannot find flag"));
	}
	flag_start += ft_strlen(flag);
	if ((flag_end = ft_strstr(flag_start, "\n-")))
		ret = ft_strndup(flag_start, flag_end - flag_start);
	else
		ret = ft_strdup(flag_start);
	free(flag);
	return (ret);
}
