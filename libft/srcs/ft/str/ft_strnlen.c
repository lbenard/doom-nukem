/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:26:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:39:17 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "maths/maths.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	return (ft_min(ft_strlen(s), maxlen));
}
