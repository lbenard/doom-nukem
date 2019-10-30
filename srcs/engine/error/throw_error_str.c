/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:23:36 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/04 12:50:10 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "engine/error.h"
#include "ft/io.h"

void	*throw_error_str(const char *const fn, const char *const cause)
{
	if (cause)
	{
		ft_putstr(PROGRAM_NAME ": ");
		ft_putstr(fn);
		ft_putstr(": ");
		ft_putstr(cause);
		ft_putchar('\n');
	}
	return (NULL);
}
