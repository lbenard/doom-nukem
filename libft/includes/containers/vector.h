/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:30:43 by lbenard           #+#    #+#             */
/*   Updated: 2019/11/06 20:29:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <string.h>
# include "types.h"
# include "containers/module.h"

/*
** Dynamic size array container
*/
typedef struct	s_vector
{
	size_t	capacity;
	size_t	size;
	void	*data;
}				t_vector;

typedef struct	s_vector_args
{
	const void	*data;
	size_t		size;
}				t_vector_args;

/*
** Constructors
*/
t_constructor	vector(void);
t_constructor	vector_data(const void *data, const size_t size);
t_result		init_vector(t_vector *const vector);
t_result		init_vector_data(t_vector *const vector,
					const t_vector_args *const args);

/*
** Capacity
*/
t_result		vector_reserve(t_vector *const vector, size_t capacity);
t_result		vector_shrink(t_vector *const vector);
t_result		vector_double(t_vector *const vector);

/*
** Modifiers
*/
void			vector_clear(t_vector *const vector);
t_result		vector_insert(t_vector *const vector,
					size_t pos,
					const void *data,
					size_t size);
t_result		vector_push_back(t_vector *const vector,
					const void *data,
					size_t size);

/*
** Destructors
*/
void			destroy_vector(t_vector *const vector);

#endif
