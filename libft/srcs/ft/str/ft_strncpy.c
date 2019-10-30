/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 02:29:32 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:38:48 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*dst_cpy;

	dst_cpy = dst;
	while (len--)
	{
		*(dst++) = *src;
		if (*src)
			src++;
	}
	return (dst_cpy);
}
