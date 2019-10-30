/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:23:58 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 20:02:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths/maths.h"
#include "ft/str.h"

double	ft_atof(const char *str)
{
	double	result;
	int		sign;
	double	decimal;

	result = 0.0;
	sign = 1;
	decimal = 0.1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		result = result * 10.0 + (*str++ - '0');
	if (*str++ == '.')
		while (ft_isdigit(*str))
		{
			result += decimal * (*str++ - '0');
			decimal /= 10.0;
		}
	return (sign * result);
}
