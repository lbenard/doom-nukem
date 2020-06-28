/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:47:51 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 01:37:56 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/text.h"

t_constructor	text(const char *const font_path, t_usize view_size)
{
	static t_text_args	args;

	args.font_path = font_path;
	args.view_size = view_size;
	return (ft_constructor(init_text,
		destroy_text,
		sizeof(t_text),
		&args));
}
