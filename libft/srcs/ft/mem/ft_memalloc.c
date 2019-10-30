/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:00:08 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:31:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/mem.h"
#include "types.h"

void	*ft_memalloc(size_t size)
{
	t_u8	*data;

	if (!(data = (t_u8*)malloc(size)))
		return (NULL);
	ft_bzero(data, size);
	return (data);
}
