/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:10:05 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:50:30 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/string.h"
#include "ft/str.h"

t_result	init_string(t_string *const self, const t_string_args *const args)
{
	size_t	len;

	init_module(&self->module);
	len = ft_strlen(args->str);
	if (!(self->str = (char*)malloc(len + 1)))
		return (ERROR);
	self->str[len] = '\0';
	ft_strcpy(self->str, args->str);
	self->len = len;
	return (OK);
}
