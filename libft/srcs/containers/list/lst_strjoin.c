/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:00:21 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 20:00:51 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "containers/list.h"
#include "ft/str.h"

static void	makestr(const t_list *lst, const char *separator, char **str)
{
	if (lst && separator && str && *str)
		while (lst)
		{
			ft_strcat(*str, (char*)lst->content);
			if (lst->next)
				ft_strcat(*str, separator);
			lst = lst->next;
		}
}

char		*lst_strjoin(const t_list *lst, const char *separator)
{
	t_list	*cpy;
	size_t	str_len;
	size_t	separator_len;
	char	*result;

	if (!lst || !separator)
		return (NULL);
	cpy = (t_list*)lst;
	str_len = 0;
	separator_len = ft_strlen(separator);
	while (cpy)
	{
		str_len += cpy->content_size - 1;
		if (cpy->next)
			str_len += separator_len;
		cpy = cpy->next;
	}
	if (!(result = (char*)malloc(str_len + 1)))
		return (NULL);
	makestr(lst, separator, &result);
	return (result);
}
