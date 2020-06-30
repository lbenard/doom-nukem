/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_string_as_ref.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:11:19 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:50:36 by mribouch         ###   ########.fr       */
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
