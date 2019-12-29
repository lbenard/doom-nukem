/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:03:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/20 20:04:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/string.h"
#include "ft/str.h"

t_static_string	ft_static_string(const char *const str)
{
	t_static_string	ret;

	ret.str = str;
	ret.len = ft_strlen(str);
	return (ret);
}