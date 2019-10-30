/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:09:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:39:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/str.h"
#include "ft/mem.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
