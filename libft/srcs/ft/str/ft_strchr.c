/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 01:45:01 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:36:58 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

char	*ft_strchr(const char *s, int c)
{
	char	to_find;

	to_find = (char)c;
	while (42)
	{
		if (*s == to_find)
			return ((char*)s);
		if (!*s)
			break ;
		s++;
	}
	return (NULL);
}
