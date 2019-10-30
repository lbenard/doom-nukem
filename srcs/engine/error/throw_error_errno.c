/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_errno.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:25:28 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 12:50:05 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "engine/error.h"
#include "ft/io.h"

void	*throw_error_errno(const char *const fn, const int err)
{
	if (err)
	{
		ft_putstr(fn);
		ft_putstr(": ");
		errno = err;
		perror(PROGRAM_NAME);
	}
	return (NULL);
}
