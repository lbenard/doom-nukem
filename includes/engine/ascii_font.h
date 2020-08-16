/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_font.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:56:08 by lbenard           #+#    #+#             */
/*   Updated: 2019/12/07 17:23:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASCII_FONT_H
# define ASCII_FONT_H

# include "containers/module.h"
# include "engine/frame.h"

typedef struct	s_ascii_font
{
	t_module	module;
	const char	*path;
	t_frame		raster;
}				t_ascii_font;

typedef struct	s_ascii_font_args
{
	const char	*path;
}				t_ascii_font_args;

t_constructor	ascii_font(const char *const path);

t_result		init_ascii_font(t_ascii_font *const self,
					const t_ascii_font_args *const args);

void			destroy_ascii_font(t_ascii_font *const self);

#endif
