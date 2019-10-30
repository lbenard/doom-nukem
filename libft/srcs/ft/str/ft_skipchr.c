/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:57:24 by lbenard           #+#    #+#             */
/*   Updated: 2019/09/30 19:33:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

char	*ft_skipchr(const char *str, char skip)
{
	if (!str)
		return (NULL);
	while (*str == skip)
		str++;
	return ((char*)str);
}
