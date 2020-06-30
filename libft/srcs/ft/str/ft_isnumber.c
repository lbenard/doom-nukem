/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 16:55:16 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:56:04 by mribouch         ###   ########.fr       */
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
