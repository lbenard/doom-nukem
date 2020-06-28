/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:53:27 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/27 02:09:50 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXT_H
# define TEXT_H

# include "engine/frame.h"
# include "containers/string.h"
# include "engine/ascii_font.h"

typedef struct	s_text
{
	t_module		module;
	t_frame			target;
	t_rgba			*pixels;
	t_ascii_font	font;
	t_string		text;
}				t_text;

typedef struct	s_text_args
{
	const char	*font_path;
	t_usize		view_size;
}				t_text_args;

t_constructor	text(const char *const font_path, const t_usize view_size);

t_result		init_text(t_text *const self, const t_text_args *const args);

t_result		text_set(t_text *const self, const t_string string);
t_result		text_set_ref(t_text *const self, const t_string_ref ref);

typedef struct	s_text_settings
{
	t_isize	position;
	size_t	height;
}				t_text_settings;

t_text_settings	ft_text_settings(const t_isize position,
					const size_t height);

void			text_render(t_text *const self, const t_text_settings settings);

void			destroy_text(t_text *const self);

#endif