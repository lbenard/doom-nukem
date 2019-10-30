/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:55:16 by lbenard           #+#    #+#             */
/*   Updated: 2019/04/24 16:58:39 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

int	ft_isnumber(const char *str)
{
	if (!*str)
		return (0);
	while (*str && !ft_isspace(*str))
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}