/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 20:03:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/30 16:50:25 by mribouch         ###   ########.fr       */
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
