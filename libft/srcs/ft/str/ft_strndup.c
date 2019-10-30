/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:21:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:38:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/str.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;

	if (!(dst = (char*)malloc(n + 1)))
		return (NULL);
	ft_strncpy(dst, s1, n);
	dst[n] = 0;
	return (dst);
}
