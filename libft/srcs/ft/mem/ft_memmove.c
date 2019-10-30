/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 01:57:10 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:31:53 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"
#include "types.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_u8		*dst_byte;
	const t_u8	*src_byte;

	dst_byte = (t_u8*)dst;
	src_byte = (const t_u8*)src;
	if (src_byte < dst_byte)
	{
		dst_byte += len - 1;
		src_byte += len - 1;
		while (len--)
			*(dst_byte--) = *(src_byte--);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
