/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 02:19:38 by lbenard           #+#    #+#             */
/*   Updated: 2020/06/05 01:52:08 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_H
# define MODULE_H

# include "types.h"
# include "containers/list.h"

/*
** Module constructor
*/
typedef struct	s_constructor
{
	t_result	(*constructor_fn)();
	void		(*destructor_fn)();
	size_t		module_size;
	const void	*args;
}				t_constructor;

t_constructor	ft_constructor(t_result (*const constructor_fn)(),
					void (*const destructor_fn)(),
					const size_t module_size,
					const void *const args);

/*
** Module node
*/
typedef struct	s_module_node
{
	t_list_head	node;
	void		*object;
	void		(*destructor_fn)();
}				t_module_node;

t_result		init_module_node(t_module_node *const self,
					void *const object,
					void (*destructor_fn)());
void			destroy_module_node(t_module_node *const self);

/*
** A generic-type module initializer and destructor that keeps track of
** sub-modules and potential errors. Modules are kept in a list. Every module
** is initialized with a constructor which just stores how to build and destroy
** the module. Whenever an error is catched while addind a module, it stops
** building newer modules and set `has_error` to TRUE.
*/
typedef struct	s_module
{
	t_list_head	node;
	t_bool		has_error;
	t_list_head	modules;
	void		(*destructor_fn)();
}				t_module;

t_result		init_module(t_module *const self);

void			module_add(t_module *const self,
					void *const module,
					const t_constructor constructor);
void			module_remove(t_module *const self,
					const void *const module_ref);
void			*static_module_allocate(const t_constructor constructor);
t_result		static_module_create(void *const module,
					const t_constructor constructor);

void			destroy_module(t_module *const self);

#endif
