/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritesheet.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:55:25 by mribouch          #+#    #+#             */
/*   Updated: 2020/08/12 19:06:20 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITESHEET_H
# define SPRITESHEET_H

# include "containers/module.h"
# include "engine/frame.h"

typedef struct	s_spritesheet
{
	t_module	module;
	t_frame		pixels;
	t_frame		*sprite;
	size_t		nb_sprite;
	t_usize		grid_size;
	t_usize		sheet_size;
	t_usize		sprite_size;
}				t_spritesheet;

typedef struct	s_spritesheet_args
{
	const char	*path;
	t_usize		grid_size;
}				t_spritesheet_args;

t_constructor	spritesheet(const char *const path, const t_usize grid_size);

t_result		init_spritesheet(t_spritesheet *const self,
					t_spritesheet_args *const args);

void			destroy_spritesheet(t_spritesheet *const self);

#endif
