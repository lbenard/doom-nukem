/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:40:12 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/27 01:37:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "engine/module.h"
# include <SFML/Graphics.h>
# include "sizes/usize.h"
# include "types.h"
# include "engine/frame.h"
# include "engine/string.h"
# include "engine/cursor.h"

/*
** Window module wrapped around SFML RenderWindow object.
*/
typedef struct			s_window
{
	t_module		module;
	sfRenderWindow	*window;
	const char		*base_name;
	t_string		name;
	t_frame			frame;
	t_cursor		cursor;
	const t_usize	size;
}						t_window;

typedef struct			s_window_args
{
	const char	*name;
	t_usize		size;
}						t_window_args;

t_smodule_factory	window(const char *const name, const t_usize size);

t_result				init_window(t_window *const self,
							const t_window_args *const args);

void					window_update(t_window *const self);
t_bool					window_is_running(const t_window *const self);
t_bool					window_is_focused(const t_window *const self);
t_result				window_set_name(t_window *const self,
							const char *const name);
void					window_close(t_window *const self);

void					destroy_window(t_window *const self);

#endif
