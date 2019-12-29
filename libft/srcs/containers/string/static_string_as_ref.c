/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_string_as_ref.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:11:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/20 20:11:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/string.h"

t_string_ref	static_string_as_ref(t_static_string self)
{
	t_string_ref	ret;

	ret.str = self.str;
	ret.len = self.len;
	return (ret);
}