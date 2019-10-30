/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:46:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:39:46 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft/str.h"

static size_t	ft_word_count(const char *s, char c)
{
	size_t	wc;

	wc = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		while (*s != c && *s)
			s++;
		wc++;
	}
	return (wc);
}

static size_t	ft_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**result;
	size_t	word_len;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(result = (char**)malloc(sizeof(char*) * (ft_word_count(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		word_len = ft_word_len(s, c);
		result[i] = ft_strndup(s, word_len);
		s += word_len;
		i++;
	}
	result[i] = (char*)0;
	return (result);
}
