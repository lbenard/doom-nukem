/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:00:18 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/29 15:03:18 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "engine/module.h"
# include "containers/vector.h"

typedef struct		s_vector_args
{
	const void	*data;
	size_t		size;
}					t_vector_args;

t_smodule_factory	vector(void);
t_smodule_factory	vector_data(const void *data, size_t size);

#endif