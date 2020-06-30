/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_ref.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:40:52 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:50:17 by mribouch         ###   ########.fr       */
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
