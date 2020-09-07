/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_descriptor.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:27:33 by lbenard           #+#    #+#             */
/*   Updated: 2020/09/05 18:30:24 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_DESCRIPTOR_H
# define BLOCK_DESCRIPTOR_H

# include "containers/module.h"
# include "engine/frame.h"

typedef struct		s_block_descriptor
{
	t_module	module;
	char		id;
	const char	*name;
	const char	*path;
	t_frame		texture;
	t_bool		translucent;
}					t_block_descriptor;

typedef struct		s_block_descriptor_args
{
	char		id;
	const char	*name;
	const char	*texture_path;
}					t_block_descriptor_args;

t_constructor		block_descriptor(const char id,
						const char *name,
						const char *texture_path);

t_result			init_block_descriptor(t_block_descriptor *const self,
						t_block_descriptor_args *const args);

t_block_descriptor	*block_descriptor_from_id(
						t_block_descriptor *const descriptors,
						const size_t amount,
						const char id);

void				destroy_block_descriptor(t_block_descriptor *const self);

#endif
