/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:22:50 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/03 16:51:37 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "engine/error.h"
#include "ft/io.h"

void	*throw_error(const char *const fn)
{
	if (errno)
	{
		ft_putstr(fn);
		ft_putstr(": ");
		perror(PROGRAM_NAME);
	}
	errno = 0;
	return (NULL);
}
