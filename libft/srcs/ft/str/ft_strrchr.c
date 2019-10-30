/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 02:06:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:39:38 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

char	*ft_strrchr(const char *s, int c)
{
	char		to_find;
	const char	*s_cpy;

	to_find = (char)c;
	s_cpy = (char*)s + ft_strlen(s);
	while (42)
	{
		if (*s_cpy == to_find)
			return ((char*)s_cpy);
		if (s_cpy == s)
			break ;
		s_cpy--;
	}
	return (NULL);
}
