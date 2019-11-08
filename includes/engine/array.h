/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:57:52 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 04:37:55 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "containers/module.h"

typedef struct	s_array
{
	void		*array;
	size_t		size;
}				t_array;

typedef struct	s_array_args
{
	size_t	size;
}				t_array_args;

t_constructor	array(size_t size);

t_result		init_array(t_array *const self,
					const t_array_args *const args);
void			destroy_array(t_array *const self);

#endif