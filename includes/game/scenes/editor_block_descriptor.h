/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_block_descriptor.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:27:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/01 00:28:09 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_BLOCK_DESCRIPTOR_H
# define EDITOR_BLOCK_DESCRIPTOR_H

#include "containers/module.h"
#include "engine/frame.h"

typedef struct	s_editor_block_descriptor
{
	t_module	module;
	size_t		id;
	const char	*name;
	t_frame		texture;
}				t_editor_block_descriptor;

typedef struct	s_editor_block_descriptor_args
{
	size_t		id;
	const char	*name;
	const char	*texture_path;
}				t_editor_block_descriptor_args;

t_constructor	editor_block_descriptor(const size_t id,
					const char *name,
					const char *texture_path);

t_result		init_editor_block_descriptor(
					t_editor_block_descriptor *const self,
					t_editor_block_descriptor_args *const args);
void			destroy_editor_block_descriptor(
					t_editor_block_descriptor *const self);

#endif