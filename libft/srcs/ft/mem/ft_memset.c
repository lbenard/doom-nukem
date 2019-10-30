/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 01:45:26 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:32:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"
#include "types.h"

void	*ft_memset(void *b, int c, size_t len)
{
	t_u8	*dst;
	t_u8	src;

	dst = (t_u8*)b;
	src = (t_u8)c;
	while (len--)
		*(dst++) = src;
	return (b);
}
