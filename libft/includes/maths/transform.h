/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mribouch <mribouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 21:18:49 by lbenard           #+#    #+#             */
/*   Updated: 2020/07/26 17:45:30 by mribouch         ###   ########.fr       */
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
	t_vec3f	direction;
}				t_transform;

/*
** Constructors
*/
t_transform		ft_transform(t_vec3f position, t_vec3f rotation, t_vec3f scale);
t_transform		ft_transform_default(void);

#endif
