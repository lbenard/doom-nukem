/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_ref.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:40:52 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/07 17:41:30 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/string.h"

t_string_ref	string_as_ref(t_string *const self)
{
	t_string_ref	ref;

	ref.str = self->str;
	ref.len = self->len;
	return (ref);
}