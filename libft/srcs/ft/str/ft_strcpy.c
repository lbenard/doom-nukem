/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 02:26:04 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:37:43 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "ft/mem.h"

char	*ft_strcpy(char *dst, const char *src)
{
	return ((char*)ft_memcpy(dst, src, ft_strlen(src) + 1));
}
