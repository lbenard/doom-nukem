/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:40:12 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/12 00:12:06 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <SFML/Graphics.h>
# include "containers/module.h"
# include "sizes/usize.h"
# include "types.h"
# include "engine/frame.h"
# include "containers/string.h"
# include "engine/cursor.h"

/*
** Window module wrapped around SFML RenderWindow object.
*/
typedef struct	s_window
{
	t_module		module;
	sfRenderWindow	*window;
	const char		*base_name;
	t_string		name;
	t_frame			frame;
	t_bool			is_cleared;
	t_cursor		cursor;
	t_usize			size;
	t_bool			is_fullscreen;
}				t_window;

typedef struct	s_window_args
{
	const char	*name;
	t_usize		size;
	t_bool		fullscreen;
}				t_window_args;

t_constructor	window(const char *const name,
					const t_usize size,
					const t_bool fullscreen);

t_result		init_window(t_window *const self,
					const t_window_args *const args);

void			window_update(t_window *const self);
t_bool			window_is_running(const t_window *const self);
t_bool			window_is_focused(const t_window *const self);
t_result		window_set_name(t_window *const self,
					const char *const name);
t_isize			window_get_mouse_pos(const t_window *const self);
void			window_close(t_window *const self);

void			destroy_window(t_window *const self);

#endif
