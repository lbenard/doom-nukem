/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   module.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenard <lbenard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:44:54 by lbenard           #+#    #+#             */
/*   Updated: 2019/10/05 15:50:25 by lbenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODULE_H
# define MODULE_H

# include "types.h"
# include "containers/list.h"


typedef void			*(*t_new_fn)();

/*
** Init and destroy functions for stack modules
*/
typedef struct			s_smodule_descriptor
{
	t_result	(*init_fn)();
	void		(*destroy_fn)();
}						t_smodule_descriptor;

t_smodule_descriptor	ft_smodule_descriptor(t_result (*init_fn)(),
							void (*destroy_fn)());

/*
** Stack factory, stores the argument used to build a stack module node
*/
typedef struct			s_smodule_factory
{
	t_smodule_descriptor	descriptor;
	const void				*args;
}						t_smodule_factory;

t_smodule_factory		ft_smodule_factory(
							const t_smodule_descriptor descriptor,
							const void *args);

/*
** Stack module node
*/
typedef struct			s_smodule
{
	t_list_head				node;
	void					*module_ref;
	t_smodule_descriptor	descriptor;
}						t_smodule;

t_smodule				*new_smodule(void *const module,
							t_smodule_descriptor descriptor);
void					free_smodule(t_smodule *const module);

/*
** New and free functions for heap modules
*/
typedef struct			s_hmodule_descriptor
{
	void	*(*new_fn)();
	void	(*free_fn)();
}						t_hmodule_descriptor;

t_hmodule_descriptor	ft_hmodule_descriptor(void *(*new_fn)(),
							void (*free_fn)());

/*
** Heap factory, stores the argument used to build a heap module node
*/
typedef struct			s_hmodule_factory
{
	t_hmodule_descriptor	descriptor;
	const void				*args;
}							t_hmodule_factory;

t_hmodule_factory		ft_hmodule_factory(
							const t_hmodule_descriptor descriptor,
							const void *args);

/*
** Heap module node
*/
typedef struct			s_hmodule
{
	t_list_head				node;
	void					**module_ref;
	t_hmodule_descriptor	descriptor;
}							t_hmodule;

t_hmodule				*new_hmodule(void **const module,
							t_hmodule_descriptor descriptor);
void					free_hmodule(t_hmodule *const module);

/*
** A generic-type module initializer and destructor that keeps track of
** allocated sub-modules and potential malloc errors. Modules are kept in
** lists, stack (scope dependant) modules and heap (non-scope dependant, like
** list nodes) modules. Every module is initialized with a factory which just
** stores how to build the module (init_* or new_* function) and how to destroy
** it (destroy_* or free_* function). Whenever a module catches an error, it
** stops building newver modules and set `has_error` to TRUE.
*/
typedef struct			s_module
{
	t_list_head	smodules;
	t_list_head	hmodules;
	t_bool		has_error;
}						t_module;

t_result				init_module(t_module *self);

void					module_add_smodule(t_module *const self,
							const t_smodule_factory factory,
							void *const module);
void					module_add_non_owned_smodule(t_module *const self,
							const t_smodule_factory factory,
							void *const module);
void					module_remove_smodule(t_module *const self,
							const void *const module_ref);

void					module_add_hmodule(t_module *const self,
							const t_hmodule_factory factory,
							void **const module);
void					module_add_non_owned_hmodule(t_module *const self,
							const t_hmodule_factory factory,
							void **const module);
void					module_remove_hmodule(t_module *const self,
							void **const module_ref);

void					destroy_module(t_module *const self);

#endif
