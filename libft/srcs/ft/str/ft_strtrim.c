/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:49:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:40:04 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/str.h"

static int	ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(const char *s)
{
	char	*s_cpy;
	char	*result;
	char	*result_cpy;
	size_t	result_len;

	if (!s)
		return (NULL);
	while (ft_iswhitespace(*s))
		s++;
	s_cpy = (char*)s + ft_strlen(s) - 1;
	while (ft_iswhitespace(*s_cpy) && s_cpy > s)
		s_cpy--;
	result_len = s_cpy - s + 1;
	if (!(result = (char*)malloc(result_len + 1)))
		return (NULL);
	result_cpy = result;
	while (result_len--)
		*result_cpy++ = *s++;
	*result_cpy = 0;
	return (result);
}
