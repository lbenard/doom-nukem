/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:25:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:40:00 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/str.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*result;
	char	*cpy;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start + len > s_len)
		return (NULL);
	if (!(result = (char*)malloc(len + 1)))
		return (NULL);
	cpy = result;
	s += start;
	while (len--)
		*cpy++ = *s++;
	*cpy = 0;
	return (result);
}
