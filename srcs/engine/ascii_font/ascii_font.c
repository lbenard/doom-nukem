/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_font.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:21:02 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:41:13 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/ascii_font.h"

t_constructor	ascii_font(const char *const path)
{
	static t_ascii_font_args	args;

	args.path = path;
	return (ft_constructor(init_ascii_font,
		destroy_ascii_font,
		sizeof(t_ascii_font),
		&args));
}
