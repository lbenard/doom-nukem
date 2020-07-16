/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opm_monster_entity.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 02:06:24 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/15 02:10:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPM_MONSTER_ENTITY_H
# define OPM_MONSTER_ENTITY_H

# include "game/entities/monster_entity.h"
# include "engine/animation.h"

typedef struct	s_opm_monster_entity
{
	t_monster_entity	super;
	t_animation			animation;
}				t_opm_monster_entity;

#endif