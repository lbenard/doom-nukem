/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_clone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:14:30 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:50:27 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/string.h"
#include "ft/str.h"

t_result	init_string_clone(t_string *const self,
				const t_string_args *const args)
{
	init_module(&self->module);
	if (!(self->str = (char*)malloc(args->string_ref.len + 1)))
		return (ERROR);
	ft_strcpy(self->str, args->string_ref.str);
	self->str[args->string_ref.len] = '\0';
	self->len = args->string_ref.len;
	return (OK);
}
