/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:10:05 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/07 16:59:49 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/string.h"
#include "ft/str.h"

t_result	init_string(t_string *const self, const t_string_args *const args)
{
	size_t	len;

	len = ft_strlen(args->str);
	if (!(self->str = (char*)malloc(len + 1)))
		return (ERROR);
	self->str[len] = '\0';
	ft_strcpy(self->str, args->str);
	self->len = len;
	return (OK);
}