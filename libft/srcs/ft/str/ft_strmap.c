/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:16:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:38:29 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/str.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new;
	char	*cpy;

	if (!s || !f)
		return (NULL);
	if (!(new = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	cpy = new;
	while (*s)
		*cpy++ = f(*s++);
	*cpy = 0;
	return (new);
}
