/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 01:51:34 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:31:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"
#include "types.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_u8		*dst_byte;
	const t_u8	*src_byte;
	t_u8		to_find;

	dst_byte = (t_u8*)dst;
	src_byte = (const t_u8*)src;
	to_find = (t_u8)c;
	while (n--)
	{
		*(dst_byte++) = *src_byte;
		if (*(src_byte++) == to_find)
			return ((void*)dst_byte);
	}
	return (NULL);
}
