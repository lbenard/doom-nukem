/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 03:23:15 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:38:44 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/str.h"
#include "ft/mem.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	min;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	min = ((s1_len < s2_len) ? s1_len : s2_len) + 1;
	return (ft_memcmp((void*)s1, (void*)s2, (min < n) ? min : n));
}
