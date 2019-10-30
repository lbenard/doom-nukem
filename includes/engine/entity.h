/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:40:57 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/11 17:04:01 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

typedef size_t	t_entity_uid;

/*
** Super-class for any entity object.
*/
typedef struct	s_entity
{
	t_entity_uid	uid;
}				t_entity;

t_entity		ft_entity(void);

t_entity_uid	get_new_entity_uid(void);


#endif