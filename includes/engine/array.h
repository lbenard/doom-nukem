/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:57:52 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/26 22:12:32 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include "engine/module.h"

typedef struct		s_array
{
	t_module	module;
	void		*array;
	size_t		size;
}					t_array;

typedef struct		s_array_args
{
	size_t	size;
}					t_array_args;

t_smodule_factory	array(size_t size);

t_result			init_array(t_array *const self,
						const t_array_args *const args);
void				destroy_array(t_array *const self);

#endif