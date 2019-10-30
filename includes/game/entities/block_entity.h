/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_entity.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:09:19 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 12:51:02 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_ENTITY_H
# define BLOCK_ENTITY_H

# include "engine/entity.h"
# include "engine/module.h"
# include "maths/vec2i.h"

typedef struct	s_block_entity
{
	t_entity	super;
}				t_block_entity;

typedef struct	s_block_entity_args
{
	t_vec2i	position;
}				t_block_entity_args;

t_hmodule_factory	block_entity(const t_vec2i position);

#endif