/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:18:49 by lbenard           #+#    #+#             */
/*   Updated: 2019/02/23 21:21:19 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "maths/vec3f.h"

/*
** 3D transform attributes
*/
typedef struct	s_transform
{
	t_vec3f	position;
	t_vec3f	rotation;
	t_vec3f	scale;
}				t_transform;

/*
** Constructors
*/
t_transform		ft_transform(t_vec3f position, t_vec3f rotation, t_vec3f scale);
t_transform		ft_transform_default(void);

#endif
