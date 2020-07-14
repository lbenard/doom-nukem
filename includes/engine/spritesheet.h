/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spritesheet.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:55:25 by mribouch          #+#    #+#             */
/*   Updated: 2020/07/08 19:05:39 by mribouch         ###   ########.fr       */
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
	int			nb_sprite;
	int			sheet_w;
	int			sheet_h;
	int			sprite_w;
	int			sprite_h;
	int			sprite_line;
	int			sprite_height;
}				t_spritesheet;

typedef struct	s_spritesheet_args
{
	char		*path;
	int			nb_sprite;
	int			line;
	int			height;
}				t_spritesheet_args;

t_result		init_spritesheet(t_spritesheet *const self,
					t_spritesheet_args *const args);
void			destroy_spritesheet(t_spritesheet *const self);
t_constructor	spritesheet(char *path, int nb_sprite, int nb_line, int height);

#endif