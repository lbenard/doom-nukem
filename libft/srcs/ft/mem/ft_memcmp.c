/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 02:14:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:31:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/mem.h"
#include "types.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_u8	*s1_byte;
	t_u8	*s2_byte;
	int		diff;

	s1_byte = (t_u8*)s1;
	s2_byte = (t_u8*)s2;
	while (n--)
		if ((diff = *(s1_byte++) - *(s2_byte++)))
			return (diff);
	return (0);
}
