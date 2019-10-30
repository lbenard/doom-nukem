/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dn_new_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:22:39 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:02:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "engine/parsing.h"
#include "engine/error.h"
#include "ft/str.h"

char	*dn_new_flag(char *flag_name)
{
	char	*tmp;
	char	*flag;

	if (!flag_name)
		return (throw_error_str("dn_new_flag()", "incorrect flag_name"));
	if (!(tmp = ft_strjoin("\n-", flag_name)))
	{
		return (throw_error_str("dn_new_flag()",
			"failed to join temporary flag name"));
	}
	if (!(flag = ft_strjoin(tmp, "\n")))
	{
		free(tmp);
		return (throw_error_str("dn_new_flag()",
			"failed to join flag name"));
	}
	free(tmp);
	return (flag);
}
