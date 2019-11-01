/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 23:38:02 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/30 22:58:14 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_H
# define CURSOR_H

# include "engine/module.h"
# include "types.h"
# include "engine/frame.h"

/*
** Mouse cursor module
*/
typedef struct			s_cursor
{
	t_module	module;
	t_bool		is_visible;
	t_frame		cursor;
}						t_cursor;

typedef struct			s_cursor_args
{
	t_usize		size;
	t_rgba		fill_color;
	const char	*path;
}						t_cursor_args;

t_smodule_factory	cursor(const t_usize size, const t_rgba fill_color);
t_smodule_factory	cursor_from_file(const char *const path);

t_result			init_cursor(t_cursor *const self,
						const t_cursor_args *const args);
t_result			init_cursor_from_file(t_cursor *const self,
						const t_cursor_args *const args);

void				cursor_set_visibility(t_cursor *const self,
						const t_bool is_visible);

void				destroy_cursor(t_cursor *const self);

#endif
