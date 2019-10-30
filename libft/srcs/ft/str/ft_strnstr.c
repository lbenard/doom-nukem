/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 02:49:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 20:18:35 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "ft/mem.h"
#include "maths/maths.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	haystack_len;
	size_t	needle_len;
	size_t	looking_len;

	i = 0;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (char *)haystack;
	if (needle_len > len)
		return (NULL);
	looking_len = ft_min(len, haystack_len);
	while (i <= ((looking_len >= needle_len) ? looking_len - needle_len : 0))
	{
		if (ft_memcmp(&haystack[i], needle, needle_len) == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
