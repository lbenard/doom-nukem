/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:41:45 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/16 21:59:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft/io.h"
#include "maths/maths.h"

static void	ft_real_fd(float n, int fd)
{
	if ((int)n)
	{
		ft_real_fd(n / 10.0f, fd);
		ft_putchar_fd('0' + ft_abs((int)n % 10), fd);
	}
}

void		ft_putfloat_fd(float n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n < 10.0f)
		ft_putchar_fd('0' + ft_abs((int)n % 10), fd);
	else
		ft_real_fd(n, fd);
	ft_putchar_fd('.', fd);
	ft_putchar_fd('0' + (int)(n * 10.0f) % 10, fd);
	ft_putchar_fd('0' + (int)(n * 100.0f) % 10, fd);
	ft_putchar_fd('0' + (int)(n * 1000.0f) % 10, fd);
	ft_putchar_fd('0' + (int)(n * 10000.0f) % 10, fd);
}
