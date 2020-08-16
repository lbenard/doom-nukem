/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:08:25 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 20:18:12 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft/io.h"
#include "ft/str.h"

void	ft_putstr_fd(const char *s, int fd)
{
	int	ret;

	if (s)
		ret = write(fd, s, ft_strlen(s));
	(void)ret;
}
