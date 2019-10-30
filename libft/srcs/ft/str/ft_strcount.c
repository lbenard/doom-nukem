/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:52:48 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:37:36 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"

size_t	ft_strcount(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
		count += (*s++ == c);
	return (count);
}
