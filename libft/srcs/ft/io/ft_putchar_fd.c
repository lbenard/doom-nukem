/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 20:07:27 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/20 19:29:15 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft/io.h"

void	ft_putchar_fd(char c, int fd)
{
	int ret;

	ret = write(fd, &c, 1);
	(void)ret;
}
