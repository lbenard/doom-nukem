/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:30:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/10 21:41:41 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <string.h>
# include "types.h"

/*
** Dynamic size array container
*/
typedef struct	s_vector
{
	size_t	capacity;
	size_t	size;
	void	*data;
}				t_vector;

/*
** Constructors
*/
t_result		init_vector(t_vector *vector);
t_result		init_vector_data(t_vector *vector, const void *data,
	size_t size);

/*
** Capacity
*/
t_result		vector_reserve(t_vector *vector, size_t capacity);
t_result		vector_shrink(t_vector *vector);
t_result		vector_double(t_vector *vector);

/*
** Modifiers
*/
void			vector_clear(t_vector *vector);
t_result		vector_insert(t_vector *vector, size_t pos, const void *data,
	size_t size);
t_result		vector_push_back(t_vector *vector, const void *data,
	size_t size);

/*
** Destructors
*/
void			destroy_vector(t_vector *vector);

#endif
