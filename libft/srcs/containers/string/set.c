/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:19:40 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/07 16:51:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/string.h"
#include "ft/str.h"

t_result	string_set(t_string *const self, const char *const str)
{
	size_t	len;

	free(self->str);
	len = ft_strlen(str);
	if (!(self->str = (char*)malloc(len + 1)))
		return (ERROR);
	ft_strcpy(self->str, str);
	self->str[len] = '\0';
	self->len = len;
	return (OK);
}