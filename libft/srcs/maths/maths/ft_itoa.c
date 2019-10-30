/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:37:03 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:06:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "maths/maths.h"

char	*ft_itoa(int n)
{
	char	*result;
	size_t	nb_len;

	nb_len = ft_nblen(n);
	if (!(result = (char*)malloc(nb_len + 1)))
		return (NULL);
	result[nb_len] = 0;
	if (n < 0)
		result[0] = '-';
	while (42)
	{
		result[--nb_len] = '0' + ft_abs(n % 10);
		n /= 10;
		if (!n)
			break ;
	}
	return (result);
}
