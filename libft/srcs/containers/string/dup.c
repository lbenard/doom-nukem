/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:29:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:50:22 by mribouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/string.h"
#include "ft/str.h"

t_result	string_dup(t_string *const self, const t_string_ref ref)
{
	free(self->str);
	if (!(self->str = (char*)malloc(ref.len + 1)))
		return (ERROR);
	ft_strcpy(self->str, ref.str);
	self->str[ref.len] = '\0';
	self->len = ref.len;
	return (OK);
}
